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
        time.push_back({a, b});
    }
    
    sort(time.begin(), time.end());
    int ans = 0;
    //int val = 0;
    int curr = 0;
    int i = 1;
    while(curr<time.size())
    {
        if(i < n && time[i].first<time[curr].second)
        {
            if(time[curr].second > time[i].second)
            {
                curr = i;
            }
        }
        else
        {
            ans++;
            curr = i;
        }
        i++;
    }
    cout<<ans;
}
