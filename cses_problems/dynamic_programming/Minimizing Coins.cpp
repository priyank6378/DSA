#include <iostream>
#include <vector>  
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

const long long MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    int x; cin >> x;
    vector<int> a;
    for (int i = 0 ; i<n; i++){
        int q ; cin >> q;
        a.push_back(q);
    }
    vector<int> dp(x+1, -1);
    dp[0] = 0;
    for (int i = 1 ; i<=x; i++){
        int ans = INT_MAX;
        for (int j = 0; j< n; j++){
            if (i - a[j] >= 0) {
                if (dp[i-a[j]]!=-1)
                    ans = min(ans, dp[i-a[j]] + 1);
            }
        }
        if (ans != INT_MAX) {
            dp[i] = ans;
        }
    }
    cout << dp[x] << endl; 
 
}

int main() {
    ios::sync_with_stdio(false);  // faster I/O
    cin.tie(nullptr);

    // int n; cin >> n; while (n--)
    solve();

    return 0;
}
