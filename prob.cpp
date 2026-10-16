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


void solve() {
    int n; cin >> n;

    // vector<int> a; 

    long long ans = LLONG_MIN;
    long long cur = LLONG_MIN;
    for (int i = 0; i<n; i++){
        int x; cin >> x;
        if (cur + x < x) {
            cur = x;
        }
        else {
            cur = cur + x;
        }
        ans = max(cur, ans);
    }
    cout << ans << endl; 

}

int main() {

    ios::sync_with_stdio(false);  // faster I/O
    cin.tie(nullptr);

    // int n; cin >> n; while (n--)
    solve();


    return 0;
}
