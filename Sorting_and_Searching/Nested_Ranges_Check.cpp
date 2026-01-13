#include<bits/stdc++.h>
using namespace std;
struct Interval{
    int l; int r; int idx;
};

int main()
{
    int n;
    cin>>n;
    vector <Interval> vect;
    int x, y;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        vect.push_back({x, y, i});
    }
    sort(vect.begin(), vect.end(), [](auto &a, auto &b){
        if(a.l!=b.l)    return a.l<b.l;
        return a.r > b.r;
    });

    vector <int> contain(n, 0);
    vector <int> contained(n, 0);

    int max_r = 0;
    for(int i=0;i<n;i++)
    {
        if(vect[i].r <= max_r)
        {
            contained[vect[i].idx] = 1;
        }
        max_r = max(max_r, vect[i].r);
    }
    int min_r = INT_MAX;
    for(int i=n-1;i>=0;i--)
    {
        if(vect[i].r >= min_r)
        {
            contain[vect[i].idx] = 1;
        }
        min_r = min(min_r, vect[i].r);
    }    
   // cout<<endl;
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