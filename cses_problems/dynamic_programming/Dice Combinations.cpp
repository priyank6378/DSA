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

long long recur(long long cur, vector<long long> &a) {
    if (cur<0) return 0;
    if (cur == 0) return 1;
    if (a[cur]!=-1) return a[cur];
    long long ans = 0;
    for (int i = 1; i<7; i++){
        ans += recur(cur - i, a);
        ans = ans%MOD;
    }
    a[cur] = ans;
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<long long> resolved;
    for (int i = 0; i<n+1; i++) resolved.push_back(-1);
    cout << recur(n, resolved) << endl;

}

int main() {
    ios::sync_with_stdio(false);  // faster I/O
    cin.tie(nullptr);

    // int n; cin >> n; while (n--)
    solve();

    return 0;
}
