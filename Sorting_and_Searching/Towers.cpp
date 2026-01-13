#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin>>n;
    int ans = 0;
    multiset <int> index;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        auto it = index.upper_bound(x);
        if(it != index.end())
        {
            index.erase(it);
        }
        index.insert(x);
    }
    cout<<index.size();
}