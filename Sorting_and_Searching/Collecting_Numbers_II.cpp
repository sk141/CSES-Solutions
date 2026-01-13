#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    vector <int> vect(n);
    unordered_map <int,int> index_hash;
    for(int i=0;i<n;i++)
    {
        cin>>vect[i];
        index_hash[vect[i]] = i+1;
    }

    int curr = 1;
    for(int i=2;i<=n;i++)
    {
        if(index_hash[i]<index_hash[i-1])
        {
            curr++;
        }
    }
  
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin>>a>>b;
        if(a>b)
        {
            swap(a, b);
        }
        int val_a = vect[a-1];
        int val_b = vect[b-1];
        if(val_a!=1 && index_hash[val_a-1]>a && index_hash[val_a-1]<=b)
        {
            curr--;
        }
        if(val_a!=n && index_hash[val_a+1]>a && index_hash[val_a+1]<=b)
        {
            curr++;
        }
        if(val_b!=1 && (val_b-1 != val_a) && index_hash[val_b-1]<b && index_hash[val_b-1]>=a)
        {
            curr++;
        }
        if(val_b!=n && (val_b+1 != val_a) && index_hash[val_b+1]<b && index_hash[val_b+1]>=a)
        {
            curr--;
        }
        cout<<curr<<endl;
        swap(vect[a-1], vect[b-1]);
        index_hash[val_a] = b;
        index_hash[val_b] = a;
    }

}