#include<bits/stdc++.h>
using namespace std;

string convert_binary(long long int n)
{
    string ret;
    while(n)
    {
        char c = ('0'+n%2);
        n/=2;
        ret.push_back(c);
    }
    reverse(ret.begin(), ret.end());
  //  cout<<ret<<endl;
    return ret;
}

long long int dp[51][2][51];

long long int findBits(string &s, int idx, bool tight, int count)
{
    if(idx == s.length())
    {
        //ans += count;
        return count;
    }
    if(dp[idx][tight][count]!=-1)   return dp[idx][tight][count];
    int ub = (tight?(s[idx]-'0'):1);
    long long int temp = 0;
    for(int i=0;i<=ub;i++)
    {
        bool new_tight = (tight && (i==ub));
        int add = (i==1)?1:0;
        temp+=findBits(s, idx+1, new_tight, count+add);
    }
    return dp[idx][tight][count]=temp;
}

long long int findUsingPattern(long long int n)
{
    long long int ret = 0;
  //  cout<<ret<<endl;
    for(long long int i=0;i<64;i++)
    {
        long long int block = (1ll<<i+1);
        long long int add = (1ll<<i);
        long long int full = (n+1)/block;
        long long int rem = (n+1)%block;
        ret = ret + full*add;
     //   cout<<ret<<endl;
       // cout<<max(0ll, rem - add)<<endl;
        ret = ret + max(0ll, rem - add);
    }
   // cout<<ret<<endl;
    return ret;
}

void solve()
{
    long long int n;
    cin>>n;
//     string s =  convert_binary(n);
//    // long long ans = 0;
//     memset(dp, -1, sizeof(dp));
//    // cout<<s<<endl;
//     cout<<findBits(s, 0, 1, 0);
    cout<<findUsingPattern(n);
    //cout<<ans;
}

int main()
{
    solve();
}