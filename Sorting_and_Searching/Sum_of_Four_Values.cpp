#include<bits/stdc++.h>
using namespace std;
using pii = pair <int,int>;
using T = tuple<int,int,int>;

int main()
{
    int n, x;
    cin>>n>>x;
    vector <int> vect(n);
    for(int i=0;i<n;i++)
    {
        cin>>vect[i];
    }
    
    set <T> pair_sums;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum = vect[i]+vect[j];
            pair_sums.insert({sum, i, j});
        }
    }


    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            pair_sums.erase({vect[i]+vect[j], i, j});
        }
        for(int j=i-1;j>=0;j--)
        {
            int diff = x-vect[i]-vect[j];
            auto it = pair_sums.lower_bound({diff, -1, -1});
            if(it == pair_sums.end())   continue;
            auto [sum, k, l] = *it;
            if(sum != diff) continue;
            cout<<(i+1)<<" "<<j+1<<" "<<k+1<<" "<<l+1;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
}