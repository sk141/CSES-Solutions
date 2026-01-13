#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin>>n;
    int ans = 0;
    int cnt = 0;
    int start = 0;
    map <int,int> index;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(index.count(x))
        {
            start = max(start, index[x]+1);
        }
        index[x] = i;
        cnt = i-start+1;
      //  cout<<cnt<<" ";
        ans = max(ans, cnt);
    }
    cout<<ans<<endl;

}