#include <bits/stdc++.h>
using namespace std;
using ll  = long long int;
const long long MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    unordered_map <int,ll> freq;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        freq[x]++;
    }
    long long int ans = 1;
    for(auto it : freq)
    {
        ans = (ans%MOD * ((it.second+1)%MOD))%MOD;
    }
    cout<<ans-1;
}
