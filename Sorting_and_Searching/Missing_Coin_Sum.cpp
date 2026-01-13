#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
using pii = pair<int,int>;
// int main()
// {
//     int n;
//     cin>>n;
//     vector <ll> vect(n);
//     for(int i=0;i<n;i++)    cin>>vect[i];
//     sort(vect.begin(), vect.end());
//     ll val = 1;
//     for(auto it : vect)
//     {
//         if(it > val)
//         {
//             break;
//         }
//         val+=it;
//     }
//     cout<<val;
// }

// int main()
// {
//     int n;
//     cin>>n;
//     vector <pii> vect(n);
//     int x;
//     for(int i=0;i<n;i++)    
//     {
//         cin>>x;
//         vect[i] = {x, i};
//     }
//     sort(vect.begin(), vect.end());
//     int val = 1;
//     for(int i=1;i<n;i++)
//     {
//         if(vect[i].second < vect[i-1].second)
//         {
//             val++;
//         }
//     }
//     cout<<val;
// }


// int main()
// {
//     int n, m, k;
//     cin>>n>>m>>k;
//     vector <pii> vect(n);
//     int x;
//     for(int i=0;i<n;i++)    
//     {
//         cin>>x;
//         vect[i] = {x-k, x+k};
//     }
//     vector <int> aprt(m);
//     for(int i=0;i<m;i++)
//     {
//         cin>>aprt[i];
//     }
//     sort(vect.begin(), vect.end());
//     sort(aprt.begin(), aprt.end());
//     int ans = 0;
//     int i, j;
//     i = j = 0;
//     while(i<n && j<m)
//     {
//         while(j<m && aprt[j] < vect[i].first)
//         {
//             j++;
//         }
//         while(i<n && aprt[j] > vect[i].second)
//         {
//             i++;
//         }
//         if(i!=n && j!=m && (aprt[j]>=vect[i].first && aprt[j]<=vect[i].second))
//         {
//             ans++;
//             i++;
//             j++;
//         }
//     }
//     cout<<ans;
// }


// int main()
// {
//     int n, m, k;
//     cin>>n;
//     vector <int> vect(n);
//     int x = 0;
//     for(int i=0;i<n;i++)    
//     {
//         cin>>vect[i];
//         x+=vect[i];
//         // vect[i] = {x-k, x+k};
//     }
//     sort(vect.begin(), vect.end());
    
//     cout<<max(x, 2*vect[n-1]);
// }


int main()
{
    int n;
    cin>>n;
    set <int> s;
    int x;
    for(int i=0;i<n;i++)    
    {
        cin>>x;
        s.insert(x);
    }
    cout<<s.size();
}


