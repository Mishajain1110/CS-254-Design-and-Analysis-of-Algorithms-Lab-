#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int safe(vector<vector<int>>& mat, int i, int j, vector<vector<bool>>& visited){
    return (i < mat.size()) && (i >= 0) && (j < mat[0].size()) && (j >= 0) && (mat[i][j] && !visited[i][j]);
}

void DFS_traversal(vector<vector<int>>& mat, int i, int j, vector<vector<bool>>& visited, int& count){
    vector<int> m_number = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> n_number = {-1, 0, 1, -1, 1, -1, 0, 1};
    visited[i][j] = true;

    for(int p = 0; p < 8; p++){
        if(safe(mat, i + m_number[p], j + n_number[p], visited)){
            count++;
            DFS_traversal(mat, i + m_number[p], j + n_number[p], visited, count);
        }
    }

}

int find_largest_region(vector<vector<int>>& mat){
    int m = mat.size();
    int n = mat[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int ans = INT_MIN;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){

            if(mat[i][j] && !visited[i][j]){
                int count = 1;
                DFS_traversal(mat, i, j, visited, count);
                ans = max(ans, count);
            }

        }
    }

    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    int t;
    cin >> t;

    while(t--){
        int m, n;
        cin >> m >> n;
        vector<vector<int>> mat(m, vector<int>(n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }

        int res = find_largest_region(mat);
        cout << "Output of testcase " << 5 - t << ": " << res << endl;
    }

    return 0;
}