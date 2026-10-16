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

long recur(int cur, vector<int> &a, vector<long> &b) {
    if (cur<0) return 0;
    if (b[cur]!=-1) return b[cur];
    long ans = 0;
    for (int i : a){
        ans += recur(cur - i, a, b);
        ans = ans%MOD;
    }
    b[cur] = ans;
    return b[cur];
}
 
void solve() {
    int n; cin >> n;
    int x; cin >> x;
    vector<int> a;
    for (int i = 0 ; i<n; i++){
        int q ; cin >> q;
        a.push_back(q);
    }
    vector<long> dp(x+1, -1);
    dp[0] = 1;
    recur(x, a, dp);
    cout << dp[x] << endl; 
 
}


int main() {
    ios::sync_with_stdio(false);  // faster I/O
    cin.tie(nullptr);

    // int n; cin >> n; while (n--)
    solve();

    return 0;
}
