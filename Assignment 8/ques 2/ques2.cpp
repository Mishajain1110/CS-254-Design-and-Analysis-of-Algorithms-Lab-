#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

long long minimumCost(int m, int n, int bitMask, int prev, int col, vector<vector<vector<int>>>& graph, vector<vector<vector<int>>>& dp){
    if (bitMask == ((1 << m) - 1)){
        return 0;
    }

    if (dp[bitMask][prev][col == 1] != 0){
        return dp[bitMask][prev][col == 1];
    }

    long long ans = INT_MAX;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < 2; j++){
            if (graph[prev][i][j] && !(bitMask & (1 << i)) && (j != col)){
                long long var = graph[prev][i][j] + minimumCost(m, n, bitMask | (1 << i), i, j, graph, dp);
                ans = min(var, ans);
            }
        }
    }
    return dp[bitMask][prev][col == 1] = ans;
}

void createGraph(vector<pair<pair<int, int>, pair<int, char>>> &g, int n, vector<vector<vector<int>>>& graph){

    for (int i = 0; i < n; i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int cost = g[i].second.first;
        char color = g[i].second.second;
        graph[u][v][color == 'G'] = cost;
        graph[v][u][color == 'G'] = cost;
    }
}

int Cost(int m, int n, vector<vector<vector<int>>>& graph, vector<vector<vector<int>>>& dp){
    long long ans = INT_MAX;

    for (int i = 0; i < m; i++){
        ans = min(ans, minimumCost(m, n, 1 << i, i, 2, graph, dp));
    }

    return ans == INT_MAX ? -1 : ans;
}

int main(){  
#ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
#endif
    int t;
    cin >> t;

    while (t--){
        vector<vector<vector<int>>> graph(20, vector<vector<int>>(20, vector<int>(2)));
        vector<vector<vector<int>>> dp(20, vector<vector<int>>(1 << 20, vector<int>(2)));
        int v, e;
        cin >> v >> e;
        vector<pair<pair<int, int>, pair<int, char>>> edges(e);
        int v1, v2, wt, color;

        for (int i = 0; i < e; i++){
            cin >> v1 >> v2 >> wt >> color;

            if(color == 1){
                edges[i] = make_pair(make_pair(v1, v2), make_pair(wt, 'G'));
            }
            
            else{
                edges[i] = make_pair(make_pair(v1, v2), make_pair(wt, 'B'));
            }
            
        }

        createGraph(edges, e, graph);
        int ans = Cost(v, e, graph, dp);
        if(ans == -1){
            cout << "Output of testcase " << 4 - t << ": " << "not possible" << endl;
        }
        else{
            cout << "Output of testcase " << 4 - t << ": " << ans << endl;
        }
    }
}
