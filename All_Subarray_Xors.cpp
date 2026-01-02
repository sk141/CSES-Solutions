#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> cur, nxt;
    cur.reserve(64);
    nxt.reserve(64);

    vector<int> all;
    all.reserve(6000000); // ~ n * 30

    for (int i = 0; i < n; i++) {
        nxt.clear();

        // subarray of length 1
        nxt.push_back(a[i]);

        // extend previous subarrays
        for (int x : cur) {
            nxt.push_back(x ^ a[i]);
        }

        // deduplicate nxt
        sort(nxt.begin(), nxt.end());
        nxt.erase(unique(nxt.begin(), nxt.end()), nxt.end());

        cur = nxt;

        // collect results
        for (int x : cur) {
            all.push_back(x);
        }
    }

    // count distinct values
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    cout << all.size() << "\n";
    for(auto it : all)
    {
        cout<<it<<" ";
    }
    return 0;
}
