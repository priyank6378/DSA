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

    vector<int> a,b;
    for (int i = 0; i<n; i++){
        int x, y; cin >> x >> y; 
        a.push_back(x);
        b.push_back(y);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0 , j = 0 ;
    int cnt = 0;
    int ans = 0;
    while (i+j<n+n){
        if (i<n and a[i] <= b[j]) {
            cnt ++ ;
            i++;
        }
        else {
            cnt --;
            j++;
        }
        ans = max(cnt, ans);
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
