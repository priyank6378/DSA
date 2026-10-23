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
    int m; cin >> m;
 
    vector<int> a;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    vector<long> b;
    long c = 0;
    for (int i = 0 ; i<n; i++){
        c += a[i];
        b.push_back(c);
    }
    for (int i = 0 ; i<m; i++){
        int x, y; cin >> x >> y;
        x--;y--;
        x--;
        cout << b[y] - (x<0?0:b[x]) << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);  // faster I/O
    cin.tie(nullptr);

    // int n; cin >> n; while (n--)
    solve();

    return 0;
}
