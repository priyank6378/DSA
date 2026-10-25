class Solution {
public:
    void fill(vector<vector<int>>& a, vector<vector<int>>& visited, int i, int j) {
        if (i < 0 or i >= a.size() or j<0 or j>=a[0].size()) return;
        if (a[i][j] or visited[i][j]) return; 
        visited[i][j] = 1;
        fill(a, visited, i+1, j);
        fill(a, visited, i-1, j);
        fill(a, visited, i, j+1);
        fill(a, visited, i, j-1);
    }

    int closedIsland(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0 ; i < n ; i++){
            fill(a,visited,i, 0);
            fill(a, visited, i, m-1);
        }
        for (int i = 0 ; i < m ; i++){
            fill(a,visited,0, i);
            fill(a, visited, n-1, i);
        }
        int ans = 0;
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<m; j++){
                if (visited[i][j] == 0 and a[i][j] == 0) {
                    ans ++ ;
                    fill(a, visited, i, j);
                }
            }
        }
        return ans;
    }
};