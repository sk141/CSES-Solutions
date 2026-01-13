#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    int n;
    cin>>n;
    vector <ll> vect(n);
    for(int i=0;i<n;i++)    cin>>vect[i];
    sort(vect.begin(), vect.end());
    ll val = vect[n/2];
    ll ans = 0;
    for(auto it : vect)
    {
        ans += abs(it-val);
    }
    cout<<ans;
}