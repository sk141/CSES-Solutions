#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin>>n>>x;
    int a;
    vector <pair <int,int>> time;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        time.push_back({a, i});
    }
    sort(time.begin(), time.end());
    for(auto it : time)
    {
       // cout<<x-it.first<<endl;
        auto idx = lower_bound(time.begin(), time.end(), x-it.first,
        [](const pair<int,int>& p, int value){
            return p.first<value;
        });
        if(idx != time.end())
        {
            int val = idx-time.begin();
        //    cout<<val<<" "<<it.second<<endl;
            if(time[val].second!=it.second && time[val].first == x-it.first)
            {
                cout<<it.second+1<<" "<<time[val].second+1;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}
