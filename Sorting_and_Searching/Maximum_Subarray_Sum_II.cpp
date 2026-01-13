#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    int n, a, b;
    cin>>n>>a>>b;
    vector <int> vect(n+1);
    for(int i=0;i<n;i++)    cin>>vect[i+1];
    long long int ans = LLONG_MIN;
    vector <ll> psum(n+1, 0);
    multiset <ll> wnd;
    for(int r=1;r<=n;r++)
    {
        psum[r] = psum[r-1]+vect[r];
        if(r<a) continue;
        wnd.insert(psum[r-a]);
        if(r>b)
        {
            wnd.erase(wnd.find(psum[r-b-1]));
        }
        ll mss_i = psum[r]- *wnd.begin();
        ans = max(ans, mss_i);
    }
    cout<<ans<<endl;
}
