#include<bits/stdc++.h>
using namespace std;
using pii =  pair <int,int>;
int main()
{
    int n, K;
    cin>>n>>K;
    vector <pii> vect(n);
    int a, b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        vect[i] = {b, a};
    }
    sort(vect.begin(), vect.end());
    multiset <int> time;
    time.insert(vect[0].first);
    int ans = 1;
    for(int i=1;i<n;i++)
    {
        auto it =  time.upper_bound(vect[i].second);
        if(it != time.begin())
        {
            it--;
            ans++;
            time.erase(it);
            time.insert(vect[i].first);
        }
        else
        {
            if(time.size() < K)
            {
                ans++;
                time.insert(vect[i].first);
            }
        }
    }
    cout<<ans;
}