#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    cin>>n>>a>>b;
    vector <int> vect(n);
    for(int i=0;i<n;i++)    cin>>vect[i];
    long long int sum = 0;
    long long int ans = LLONG_MIN;
    int l = 0;
    for(int r=0;r<n;r++)
    {
        sum += vect[r];
        int k = r-l+1;
        if(k>b)
        {
            sum -= vect[l++];
            k--;
        }
        
        if(k>=a && sum < 0)
        {
            sum -= vect[l++];
            k--;
        }

        if(k>=a && k<=b)
        {
            ans = max(ans, sum);
        }
    }
    cout<<ans<<endl;
}