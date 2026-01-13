#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    int x;

    multiset <int> tickets;
    vector <int> price(m);
    for(int i=0;i<n;i++)
    {
        cin>>x;
        tickets.insert(x);
    }
    for(int i=0;i<m;i++)
    {
        cin>>price[i];
    }
    //sort(price.begin(), price.end());
    //sort(tickets.begin(), tickets.end());
    vector <int> ans;
    
    for(int i=0;i<m;i++)
    {
        auto idx = tickets.upper_bound(price[i]);
        
        if(idx!=tickets.begin())
        {
            idx--;
            cout<<*idx<<endl;
            tickets.erase(idx);
        }
        else
        {
            cout<<-1<<endl;
        }
    }
}

/*
NOTE :- used set.upper_bound on a set or multiset and not upper_bound(set.begin(), set.end(), value)
using set's own internal upper bound is much faster
*/