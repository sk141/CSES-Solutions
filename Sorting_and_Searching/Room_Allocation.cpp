#include<bits/stdc++.h>
using namespace std;
using PII = pair <int,int>;

struct Interval{
    int st;
    int et;
    int index;
};

int main()
{
    int n, p, q;
    cin>>n;
    vector <Interval> time;
    for(int i=0;i<n;i++)
    {
        cin>>p>>q;
        time.push_back({p, q, i});
    }

    sort(time.begin(), time.end(), [](const Interval &a, const Interval &b){
        if(a.st == b.st)
        {
            return a.et<b.et;
        }
        return a.st<b.st;
    });
    auto [a, b, idx] = time[0];
    vector <int> assignedRoom(n);
    assignedRoom[idx] = 1;
    int ans = 1;
    multiset <PII> et_rid;
    et_rid.insert({b, ans});
    for(int i=1;i<n;i++)
    {
        auto [a, b, idx] = time[i];
        auto [smallest_et, rid] = *et_rid.begin();
        if(smallest_et < a)
        {
            et_rid.erase(et_rid.begin());
            et_rid.insert({b, rid});
            assignedRoom[idx] = rid;
        }
        else
        {
            ans++;
            et_rid.insert({b, ans});
            assignedRoom[idx] = ans;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<assignedRoom[i]<<" ";
    }
}