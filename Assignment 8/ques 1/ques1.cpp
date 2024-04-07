#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    return a[2] > b[2];
}

void makeSet(vector<int>& parent, vector<int>& rank, int n){

    for(int i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int>& parent, int node){
    if(parent[node] == node){
        return node;
    }

    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(vector<int>& parent, vector<int>& rank, int u, int v){
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }

    else if(rank[v] < rank[u]){
        parent[v] = u;
    }

    else{
        parent[v] = u;
        rank[u]++;
    }

}

pair<int, vector<vector<int>>> maximumSpanningTree(vector<vector<int>>& edges, int n){
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int maxWeight = 0;
    vector<vector<int>> treeEdges;

    for(int i = 0; i < edges.size(); i++){
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);

        if(u != v){
            treeEdges.push_back({edges[i][0], edges[i][1]});
            maxWeight += edges[i][2];
            unionSet(parent, rank, u, v);
        }
    }

    return make_pair(maxWeight, treeEdges);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    int t;
    cin >> t;

    while(t--){
        int v, e;
        cin >> v >> e;
        vector<vector<int>> edges(e);
        int v1, v2, wt;

        for(int i = 0; i < e; i++){
            cin >> v1 >> v2 >> wt;
            edges[i] = {v1, v2, wt};
        }

        auto res = maximumSpanningTree(edges, v);
        cout << "Output of testcase " << 10 - t << endl;
        cout << "Maximum weight: " << res.first << endl;
        cout << "Maximum spanning tree edges: ";

        for(auto vec : res.second){
            cout << "(" << vec[0] << ", " << vec[1] << ")" << " ";
        }
        
        cout << endl << endl;
    }
}