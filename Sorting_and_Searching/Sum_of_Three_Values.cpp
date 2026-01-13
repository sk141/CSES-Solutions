#include<bits/stdc++.h>
using namespace std;
using pii = pair <int,int>;

int main()
{
    int n, x;
    cin>>n>>x;
    vector <pii> vect(n);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        vect[i] = {x, i};
    }
    sort(vect.begin(), vect.end());
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int k = vect[i].first+vect[j].first;
            auto it = lower_bound(vect.begin()+j+1, vect.end(), x-k, [](const pii &a, int val){
                return a.first < val;
            }); 
            if(it!=vect.end() && vect[it-vect.begin()].first==(x-k))
            {
                cout<<vect[i].second+1<<" "<<vect[j].second+1<<" "<<vect[it-vect.begin()].second+1;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}