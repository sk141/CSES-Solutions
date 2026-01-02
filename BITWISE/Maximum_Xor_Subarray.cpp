#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    TrieNode* child[2];
    TrieNode()
    {
        child[0] = child[1] = nullptr;
    }
};

class Trie{
public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(long long int n)
    {
        TrieNode* curr = root;
        for(int i=40;i>=0;i--)
        {
            int val = ((n>>i) & 1);
           // cout<<val<<" ";
            if(curr->child[val]==nullptr)
            {
                curr->child[val] = new TrieNode();
            }
            curr = curr->child[val];
        }
      //  cout<<endl;
    }

    long long int find(long long int n)
    {
        long long int ret = 0;
        TrieNode* curr = root;
       // cout<<n<<endl;
        for(int i=40;i>=0;i--)
        {
            int val = ((n>>i) & 1);
           // cout<<1-val<<" ";
            if(curr->child[1-val]!=nullptr)
            {
              // cout<<1-val<<" ";
                ret |= (1ll<<i);
                curr = curr->child[1-val];
            }
            else
            {
              //  cout<<val<<" ";
                curr = curr->child[val];
            }
        }
       // cout<<endl;
       // cout<<ret<<endl;
        return ret;
    }
};

int findMaxXor(vector<int>& nums)
{
    int n = nums.size();
    Trie* t = new Trie();
    t->insert(0);
    long long int xorVal = 0;
    long long int ans = 0;
    for(int i=0;i<n;i++)
    {
        //ans = max(ans, nums[i]);
        xorVal = xorVal^nums[i];
      //  cout<<xorVal<<endl;
        long long int val = t->find(xorVal);
      //  cout<<val<<endl;
        ans = max(ans, val);
        t->insert(xorVal);
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> vect(n);
    for(int i=0;i<n;i++)
    {
        cin>>vect[i];
    }
    cout<<findMaxXor(vect);
}

int main()
{
    solve();
}