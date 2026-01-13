#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
using pll = pair <ll, ll>;
int main()
{
    int n;
    cin>>n;
    ll a, b;
    vector <pll> vect(n);
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        vect[i] = {a, b};
    }
    sort(vect.begin(), vect.end(), [](const pll &a, const pll &b){
        if(a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first < b.first;
    });
    ll ans = 0;
    ll t = 0;
    for(auto it : vect)
    {
        t+= it.first;
        ans = ans + (it.second-t);
    }
    cout<<ans;
}