#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    ll n;
    cin>>n;
    vector <ll> vect(n);
    for(int i=0;i<n;i++)
    {
        cin>>vect[i];
    }
    long long int sum = 0;
    ll count = 0;
    map <ll, ll> hash;
    hash[0] = 1;
    for(int i=0;i<n;i++)
    {
        sum += vect[i];
        sum = (sum%n + n)%n;
       // ll d = (sum%n + n)%n;
        count += hash[sum];
        hash[sum]++;
    }
    cout<<count;
}