#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a, b;
    vector <pair <int,int>> time;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        time.push_back({a, 1});
        time.push_back({b, -1});
    }
    
    sort(time.begin(), time.end());
    int ans = 0;
    int val = 0;
    int i = 0;
    while(i<time.size())
    {
        val += time[i].second;
        i++;
        ans = max(ans, val);
    }
    cout<<ans;
}
