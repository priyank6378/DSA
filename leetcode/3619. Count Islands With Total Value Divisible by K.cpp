class Solution {
public:
    long long fill(vector<vector<int>>& a, vector<vector<int>>& visited, int i, int j) {
        if (i < 0 or i >= a.size() or j<0 or j>=a[0].size()) return 0;
        if (a[i][j] == 0 or visited[i][j]) return 0; 
        visited[i][j] = 1;
        long long ans = a[i][j];
        ans += fill(a, visited, i+1, j);
        ans += fill(a, visited, i-1, j);
        ans += fill(a, visited, i, j+1);
        ans += fill(a, visited, i, j-1);
        return ans;
    }

    int countIslands(vector<vector<int>>& a, int k) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<m; j++){
                if (visited[i][j] == 0 and a[i][j]) {
                    long long x = fill(a, visited, i, j);
                    if (x%k == 0) ans ++ ;
                }
            }
        }
        return ans;
    }
};