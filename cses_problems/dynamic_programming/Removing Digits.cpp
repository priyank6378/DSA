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
    int t;
    int ans = 0 ;
    while (n){
        int t= n;
        int m = 0;
        while (t) {
            m = max(m, t%10);
            t /=10;
        }
        n -= m;
        ans ++ ;
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
