#include<bits/stdc++.h>
using namespace std;

vector <int> findKXOR(vector<int>& vect, int n, int k)
{
    vector <int> basis(31, 0);
    for(auto it : vect)
    {
        int curr = it;
        for(int i=30;i>=0;i--)
        {
            if(!((curr>>i)&1))  continue;
            if(!basis[i])
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

    vector <int> temp;
    for(int i=30;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(basis[j] && ((basis[i]>>j)&1))
            {
                basis[i]^=basis[j];
            }
        }
        if(basis[i])
        {
            temp.push_back(basis[i]);
        }
    }
    reverse(temp.begin(), temp.end());
    int m = temp.size();
    //cout<<"m is "<<m<<endl;
    int exp = min(30, n-m);
    int freq = (1<<exp);
    int x = ((k+freq-1)/freq);
    vector <int> value;
    for(int i=0;i<x;i++)
    {
        int add = 0;
        for(int j=30;j>=0;j--)
        {
            if((i>>j)&1)
            {
                add = add ^ temp[j];
            }
        }
        value.push_back(add);
    }
    vector <int> ret;
    for(int i=0;i<x && k>0;i++)
    {
        for(int j=0;j<freq &&  k>0;j++)
        {
            ret.push_back(value[i]);
            k--;
        }
    }
    return ret;
}

int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> vect(n);
    for(int i=0;i<n;i++)    cin>>vect[i];
    vector <int> ans = findKXOR(vect, n, k);
    for(auto it : ans)
    {
        cout<<it<<" ";
    }
}

/*
In this solution, reduction is required in order to generate the
xor values in sorted order
*/