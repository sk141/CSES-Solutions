#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, n;
    cin>>x>>n;
    set <int> pos;
    multiset <int> len;
    pos.insert(0);
    pos.insert(x);
    len.insert(x);
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        auto it = pos.upper_bound(p);
        int right = *it;
        int left = *prev(it);
        len.erase(len.find(right-left));
        len.insert(p-left);
        len.insert(right-p);
        pos.insert(p);
        cout<<*len.rbegin()<<" ";
    }
}