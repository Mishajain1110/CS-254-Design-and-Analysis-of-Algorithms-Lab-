#include<iostream>
#include<vector>
using namespace std;

bool dfs(vector<vector<int>>& adj, int s, vector<int>& visited, vector<int>& rec){
    visited[s] = true;
    rec[s] = true;

    for(auto ele : adj[s]){
        if(!visited[ele] && dfs(adj, ele, visited, rec)){
            return true;
        }

        else if(rec[ele]){
            return true;
        }
    }

    rec[s] = false;
    return false;
}

bool detectCycle(int v, vector<vector<int>>& edges){
    vector<vector<int>> adj(v);

    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
    }

    vector<int> visited(v, false);
    vector<int> rec(v, false);

    for(int i = 0; i < v; i++){
        if(!visited[i]){
            if(dfs(adj, i, visited, rec)){
                return true;
            }
        }
    }
    
    return false;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input4.txt", "r", stdin);
        freopen("output4.txt", "w", stdout);
    #endif
    int t;
    cin >> t;

    while(t--){
        int v, e;
        cin >> v >> e;
        vector<vector<int>> edges(e);
        int v1, v2;

        for(int i = 0; i < e; i++){
            cin >> v1 >> v2;
            edges[i] = {v1, v2};
        }

        int ans = detectCycle(v, edges);
        if(ans){
            cout << "Output of testcase " << 10 - t << ": " << "YES" << endl;
        }
        else{
            cout << "Output of testcase " << 10 - t << ": " << "NO" << endl;
        }
       
    }
}