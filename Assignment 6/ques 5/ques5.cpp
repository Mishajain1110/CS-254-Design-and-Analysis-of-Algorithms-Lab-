#include <iostream>
#include <vector>
using namespace std;

int timer1 = 1;
int timer2 = 1;

void dfsBridge(vector<vector<int>> &adj, int s, int parent, vector<int> &vis, vector<int> &disc, vector<int> &low, vector<vector<int>> &bridges){
    vis[s] = 1;
    disc[s] = timer1;
    low[s] = timer1;
    timer1++;

    for (auto ele : adj[s]){

        if (ele == parent){
            continue;
        }

        else if (!vis[ele]){
            dfsBridge(adj, ele, s, vis, disc, low, bridges);
            low[s] = min(low[s], low[ele]);
            if (low[ele] > disc[s]){
                bridges.push_back({s, ele});
            }
        }

        else{
            low[s] = min(low[s], low[ele]);
        }
    }

    return;
}

vector<vector<int>> findBridges(int v, vector<vector<int>> &edges){
    vector<vector<int>> adj(v);
    // convert the given directed graph into undirected graph and then use Tarjan's algorithm to compute articulation points and bridges.
    for (auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<int> vis(v, 0);
    vector<int> disc(v);
    vector<int> low(v);
    vector<vector<int>> bridges;

    for (int i = 0; i < v; i++){
        if (!vis[i]){
            dfsBridge(adj, i, -1, vis, disc, low, bridges);
        }
    }

    return bridges;
}

void dfsArticulationPoint(vector<vector<int>> &adj, int s, int parent, vector<int> &vis, vector<int> &disc, vector<int> &low, vector<int> &mark){
    vis[s] = 1;
    disc[s] = timer2;
    low[s] = timer2;
    timer2++;
    int child = 0;

    for (auto ele : adj[s]){

        if (ele == parent){
            continue;
        }

        else if (!vis[ele]){
            dfsArticulationPoint(adj, ele, s, vis, disc, low, mark);
            low[s] = min(low[s], low[ele]);
            if (low[ele] >= disc[s] && parent != -1)
            {
                mark[s] = 1;
            }
            child++;
        }

        else{
            low[s] = min(low[s], disc[ele]);
        }
    }

    if (child > 1 && parent == -1){
        mark[s] = 1;
    }

    return;
}

vector<int> findArticulationPoints(int v, vector<vector<int>> &edges){
    vector<vector<int>> adj(v);
    // convert the given directed graph into undirected graph and then use Tarjan's algorithm to compute articulation points and bridges.
    for (auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<int> vis(v, 0);
    vector<int> disc(v);
    vector<int> low(v);
    vector<int> mark(v, 0);

    for (int i = 0; i < v; i++){
        if (!vis[i]){
            dfsArticulationPoint(adj, i, -1, vis, disc, low, mark);
        }
    }

    vector<int> res;

    for (int i = 0; i < v; i++){
        if (mark[i]){
            res.push_back(i);
        }
    }

    return res;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input5.txt", "r", stdin);
    freopen("output5.txt", "w", stdout);
#endif
    int t;
    cin >> t;

    while (t--){
        int v, e;
        cin >> v >> e;
        vector<vector<int>> edges(e);
        int v1, v2;

        for (int i = 0; i < e; i++){
            cin >> v1 >> v2;
            edges[i] = {v1, v2};
        }

        vector<int> points = findArticulationPoints(v, edges);
        vector<vector<int>> bridges = findBridges(v, edges);

        cout << "Output of testcase " << 10 - t << endl;
        cout << "Articulation points: ";
        
        if(points.size() == 0){
            cout << "NIL";
        }

        for (auto num : points){
            cout << num << " ";
        }

        cout << endl;
        cout << "Bridges: ";

        if(bridges.size() == 0){
            cout << "NIL";
        }

        for (auto vec : bridges) {
            cout << "(" << vec[0] << ", " << vec[1] << ")"
                 << " ";
        }
        cout << endl << endl;
    }
}
