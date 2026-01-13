#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    int n, k;
    cin>>n>>k;
    vector <ll> vect(n);
    ll r = 0;
    for(int i=0;i<n;i++)
    {
        cin>>vect[i];
        r+=vect[i];
    }
    ll l = *max_element(vect.begin(), vect.end());
    ll ans = LLONG_MAX;
    while(l<=r)
    {
        ll mid = l + (r-l)/2;
        int cnt = 1;
        ll temp_sum = 0;
        for(int i=0;i<n;i++)
        {
            temp_sum +=vect[i];
            if(temp_sum > mid)
            {
                cnt++;
                temp_sum = vect[i];
            }
        }
        if(cnt<=k)
        {
           // cout<<"haha\n";
            ans = mid;
            r = mid-1;
        }
        else if(cnt>k)
        {
            l = mid+1;
        }
    }
    cout<<ans;
}