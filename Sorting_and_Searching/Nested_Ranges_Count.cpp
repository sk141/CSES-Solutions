#include<bits/stdc++.h>
using namespace std;
struct Interval{
    int l; int r; int id;
};

int main()
{
    int n;
    cin>>n;
    vector <Interval> vect;
    int x, y;
    vector <int> indexes;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
     //   indexes.push_back(x);
        indexes.push_back(y);
        vect.push_back({x, y, i});
    }
    sort(vect.begin(), vect.end(), [](auto &a, auto &b){
        if(a.l!=b.l)    return a.l<b.l;
        return a.r > b.r;
    });

    sort(indexes.begin(), indexes.end());
    indexes.erase(unique(indexes.begin(), indexes.end()), indexes.end());

    vector <int> contain(n, 0);
    vector <int> contained(n, 0);
    int N = indexes.size();
    vector <int> bitset(N+1, 0);

    auto add = [&](int idx, int val){
        while(idx <= N)
        {
            bitset[idx]+=val;
            idx += (idx & -idx);
        }
    };

    auto query = [&](int idx){
        int ret = 0;
        while(idx > 0)
        {
            ret = ret + bitset[idx];
            idx -= (idx & -idx);
        }
        return ret;
    };

    for(int i=n-1;i>=0;i--)
    {
        int idx = lower_bound(indexes.begin(), indexes.end(), vect[i].r) - indexes.begin()+1;
        contain[vect[i].id] = query(idx);
        add(idx, 1);
    }

    fill(bitset.begin(), bitset.end(), 0);

    for(int i=0;i<n;i++)
    {
        int idx = lower_bound(indexes.begin(), indexes.end(), vect[i].r) - indexes.begin()+1;
       // cout<<query(idx-1)<<" ";
        contained[vect[i].id] = i - query(idx-1);
        add(idx, 1);
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<contain[i]<<" ";
     //   cout<<" ";
    }  
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<contained[i]<<" ";
    }   
}