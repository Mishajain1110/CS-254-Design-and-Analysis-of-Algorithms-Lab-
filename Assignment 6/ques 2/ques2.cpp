#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> longestPath(int v, vector<vector<int>> & edges){

    vector<int> lp(v, -1);
    vector<vector<int>> adj(v);
    vector<int> indegree(v, 0);

    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }

    queue<int> q;

    for(int i = 0; i < v; i++){
        if(!indegree[i]){
            lp[i] = 0;
            q.push(i);
        }
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto ele : adj[curr]){
            indegree[ele]--;

            if(!indegree[ele]){
                q.push(ele);
            }

            lp[ele] = max(lp[ele], 1 + lp[curr]);
        }
    }

    return lp;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input2.txt", "r", stdin);
        freopen("output2.txt", "w", stdout);
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

        vector<int> res = longestPath(v, edges);
        int ans = 0;
        
        for(auto num : res){
            if(ans < num){
                ans = num;
            }
        }
        cout << "Output of testcase " << 10 - t << ": " << ans << endl;
    }
}