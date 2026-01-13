#include<bits/stdc++.h>
using namespace std;
 
void joseph1(vector <int> vect)
{
    int n = vect.size();
    if(n==1)
    {
        cout<<vect[0];
        return;
    }
    for(int i=1;i<n;i+=2)
    {
        cout<<vect[i]<<" ";
    }
    vector <int> num;
    if(n%2==0)
    {
        for(int i=0;i<n;i+=2)
        {
            num.push_back(vect[i]);
        }
    }
    else
    {
        num.push_back(vect[n-1]);
        for(int i=0;i<n-1;i+=2)
        {
            num.push_back(vect[i]);
        }
    }
    joseph1(num);
}
 
int main()
{
    int n;
    cin>>n;
    vector <int> vect(n);
    for(int i=1;i<=n;i++)
    {
        vect[i-1] = i;
    }
    joseph1(vect);
}