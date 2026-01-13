#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    ll n, k;
    cin>>n>>k;
    vector <ll> time(n);
    for(int i=0;i<n;i++)
    {
        cin>>time[i];
    }
    sort(time.begin(), time.end());
    ll l = 0;
    ll r = *time.rbegin();
    r = r*k;
   // cout<<r<<endl;
   while(l<=r)
    {
        ll mid = l + (r-l)/2;
        ll cnt = 0;
        for(ll i=0;i<n;i++)
        {
            cnt += (mid/time[i]);
            if(cnt >= k)
            {
                break;
            }
        }
        //cout<<mid<<" "<<cnt<<endl;
        if(cnt >=k)
        {
          //  ans = min(ans, mid);
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
   // cout<<ans<<endl;
    cout<<l<<endl;
}