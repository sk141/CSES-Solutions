#include<bits/stdc++.h>
using namespace std;
using pii=pair <int,int>;
int main()
{
    int n;
    cin>>n;
    stack <pii> st;
    int x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        while(!st.empty() && st.top().first >= x)
        {
            st.pop();
        }
        if(st.empty())
        {
            cout<<0;
        }
        else
        {
            cout<<st.top().second;
        }
        cout<<" ";
        st.push({x, i});
    }
    
}
