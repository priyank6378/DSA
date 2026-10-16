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


long long calc(vector<int> &a, int x){
    long long ans = 0;
    for (auto i: a){
        ans += abs(i-x);
    }
    return ans;
}

void solve() {
    int n; cin >> n;

    vector<int> a; 

    for (int i = 0; i<n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    
    int l = a[0], h=a[n-1];
    long long ans = LONG_LONG_MAX;
    while (l<h){
        int m = (l+h)/2;
        long long x = calc(a, m-1), y = calc(a,m), z = calc(a, m+1);
        if (x<y) {
            h = m-1;
        }
        else if (z<y) {
            l = m+1;
        }
        else {
            l = h = m;
        }
    }
    cout << calc(a, l) << endl; 

}

int main() {

    ios::sync_with_stdio(false);  // faster I/O
    cin.tie(nullptr);

    // int n; cin >> n; while (n--)
    solve();


    return 0;
}
