#include<bits/stdc++.h>
using namespace std;

int findMaxSubsetXOR(vector <int>& nums)
{
    vector<int> basis(31, 0);
    for(auto x : nums)
    {
        int curr = x;
        for(int i=30;i>=0;i--)
        {
            if(!((curr>>i)&1))  continue;
            if(basis[i]==0)
            {
                basis[i] = curr;
                break;
            }
            else
            {
                curr = curr^basis[i];
            }
        }
    }
    long long int ans = 0;
    int count = 0;
    for(int i=30;i>=0;i--)
    {
        if(basis[i]!=0)
        {
            count++;       
        }
    }
    ans = (1ll<<count);
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    vector <int> vect(n);
    for(int i=0;i<n;i++)
    {
        cin>>vect[i];
    }
    cout<<findMaxSubsetXOR(vect);
}

int main()
{
    solve();
}