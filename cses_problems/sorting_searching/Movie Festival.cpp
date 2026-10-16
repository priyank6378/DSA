#include <iostream>
#include <vector>  
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;


void solve() {
    int n; cin >> n;

    vector<pair<int,int>> a;
    for (int i = 0; i<n; i++){
        int x, y; cin >> x >> y; 
        a.push_back({y,x});
    }
    sort(a.begin(), a.end());

    int i = 0 ;
    int cnt = 0;
    int ans = 0;
    int cur_time = -1;
    while (i<n){
        int y = a[i].first ,x = a[i].second;
        if (cur_time <= x) {
            cur_time = y;
            ans ++ ;
        }
        i++;
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
