#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin>>n>>x;
    vector <int> vect(n);
    for(int i=0;i<n;i++)
    {
        cin>>vect[i];
    }
    sort(vect.begin(), vect.end());
    int l = 0;
    int r = n-1;
    int ans = 0;
    while(l<=r)
    {
        if(vect[l]+vect[r]>x)
        {
            r--;
        }
        else
        {
            l++;
            r--;
        }
        ans++;
    }
    cout<<ans<<endl;
}