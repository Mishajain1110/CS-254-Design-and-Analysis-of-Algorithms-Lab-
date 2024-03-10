#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> topologicalSort(int v, vector<vector<int>> &edges){

    vector<int> res;
    vector<vector<int>> adj(v);
    vector<int> indegree(v, 0);

    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }

    queue<int> q;

    for(int i = 0; i < v; i++){
        if(!indegree[i]){
            q.push(i);
        }
    }

    while(!q.empty()){
        int curr = q.front();
        res.push_back(curr);
        q.pop();

        for(auto ele : adj[curr]){
            indegree[ele]--;
            if(!indegree[ele]){
                q.push(ele);
            }
        }

    }

    return res;
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
        int v1, v2;

        for(int i = 0; i < e; i++){
            cin >> v1 >> v2;
            edges[i] = {v1, v2};
        }

        vector<int> res = topologicalSort(v, edges);
        cout << "Output of testcase " << 10 - t << ": ";
        
        for(auto num : res){
            cout << num << " ";
        }
        cout << endl;
    }
}