#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(vector<vector<int>>& adj, int s, vector<bool>& vis, vector<int>& comp){
    vis[s] = true;
    comp.push_back(s);

    for(auto ele : adj[s]){
        if(!vis[ele]){
            dfs(adj, ele, vis, comp);
        }
    }

    return;
}

void topologicalSort(vector<vector<int>>& adj, int s, vector<bool>& vis, stack<int>& st){
    vis[s] = true;

    for(auto ele : adj[s]){
        if(!vis[ele]){
            topologicalSort(adj, ele, vis, st);
        }
    }

    st.push(s);
    return;
}

vector<vector<int>> stronglyConnectedComponents(int v, vector<vector<int>>& edges){
    vector<int> order;
    vector<vector<int>> adj(v);
    vector<vector<int>> reversed_adj(v);
    vector<bool> vis(v, false);
    vector<vector<int>> res;

    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        reversed_adj[edge[1]].push_back(edge[0]);
    }

    stack<int> st;

    for(int i = 0; i < v; i++){
        if(!vis[i]){
            topologicalSort(adj, i, vis, st);
        }
    }

    while(!st.empty()){
        order.push_back(st.top());
        st.pop();
    }

    vector<bool> visited(v, false);

    for(auto ele : order){
        if(!visited[ele]){
            vector<int> comp;
            dfs(reversed_adj, ele, visited, comp);
            res.push_back(comp);
        }
    }

    return res;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input3.txt", "r", stdin);
        freopen("output3.txt", "w", stdout);
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

        vector<vector<int>> res = stronglyConnectedComponents(v, edges);
        cout << "Vertices that constitute stongly connected component for testcase " << 10 - t << ": " << endl;

        for(auto vec : res){
            for(auto num : vec){
                cout << num << " ";
            }
            cout << endl;
        }

        cout << endl;
    }
}