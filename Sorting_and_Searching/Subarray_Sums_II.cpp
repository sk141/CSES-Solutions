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
    ll count = 0;
    map <ll, int> hash;
    hash[0] = 1;
    for(int i=0;i<n;i++)
    {
        sum += vect[i];
        count += hash[sum-x];
        hash[sum]++;
    }
    cout<<count;
}