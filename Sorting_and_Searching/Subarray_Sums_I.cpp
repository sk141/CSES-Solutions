#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    int n, x;
    cin>>n>>x;
    vector <ll> vect(n);
    for(int i=0;i<n;i++)
    {
        cin>>vect[i];
    }
    long long int sum = 0;
    int count = 0;
    int j = 0;
    for(int i=0;i<n;i++)
    {
        sum += vect[i];
        while(j<i && sum > x)
        {
            sum-=vect[j++];
        }
        if(sum == x)
        {
            count++;
        }
    }
    cout<<count;
}