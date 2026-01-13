#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    int n, k;
    cin>>n>>k;
    vector <int> vect(n);
    for(int i=0;i<n;i++)
    {
        cin>>vect[i];
    }

    ll start = 0;
    map <int,ll> count;
    ll ans = 0;
    ll len = 0;
    ll i = 0;
    for(i=0;i<n;i++)
    {
        count[vect[i]]++;
        if(count.size()> k)
        {
            len = i-start;
            ans = ans + (len*(len+1))/2;
            while(count.size()>k)
            {
                count[vect[start]]--;
                if(count[vect[start]]==0)
                {
                    count.erase(vect[start]);
                }
                start++;
            }
            ll common = i-start;
            ans = ans - (common*(common+1))/2; 
        }
    } 
    len = i-start;
    ans = ans + (len*(len+1))/2;
    cout<<ans;     
}