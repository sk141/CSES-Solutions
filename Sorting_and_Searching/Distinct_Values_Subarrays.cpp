#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    int n;
    cin>>n;
    int x;
    map <int,ll> index;
    long long int ans =0;
    long long int start = 0;
    ll len = 0;
    for(long long int i=0;i<n;i++)
    {
        cin>>x;
        if(index.count(x))
        {
            len = i-start;
            ans = ans + (len*(len+1))/2;
            ll new_start = max(start, index[x]+1);
            ll common = i-new_start;
            ans = ans - (common*(common+1))/2;
            start = new_start;
        }
        index[x] = i;
    }
    len = n-start;
    ans = ans + (len*(len+1))/2;
    cout<<ans; 
}