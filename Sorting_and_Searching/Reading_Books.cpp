#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector <long long int> vect(n);
    long long int sum = 0;
    for(int i=0;i<n;i++)
    {
        cin>>vect[i];
        sum += vect[i];
    }

    long long int maxVal = *max_element(vect.begin(), vect.end());
    cout<<max(sum, 2*maxVal);

}