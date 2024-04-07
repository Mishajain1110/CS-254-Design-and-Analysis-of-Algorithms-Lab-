#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include <bits/stdc++.h>
using namespace std;

vector<int> present;
int edge;
int parent[100005];

struct singleEdge{
    int source, destination, wt;
} edges[100005];

bool cmp(singleEdge a, singleEdge b){
    return a.wt < b.wt;
}

void makeSet(int n){

    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
}

int findParent(int node){
    if(parent[node] == node){
        return node;
    }

    return parent[node] = findParent(parent[node]);
}

int unionMST(int i, int sum){
    int u = findParent(edges[i].source);
    int v = findParent(edges[i].destination);

    if(u != v){
        parent[u] = v;
        present.push_back(i);

        sum += edges[i].wt;
    }

    return sum;
}

int union2ndMST(int i, int sum){
    int u = findParent(edges[i].source);
    int v = findParent(edges[i].destination);

    if(u != v){
        parent[u] = v;
        sum += edges[i].wt;
        edge++;
    }

    return sum;
}

pair<int, int> secondMinimumSpanningTree(vector<vector<int>>& graphEdges, int v, int e){
    makeSet(v);
    int sum = 0;
    for(int i = 0; i < e; i++){
        edges[i].source = graphEdges[i][0];
        edges[i].destination = graphEdges[i][1];
        edges[i].wt = graphEdges[i][2];
    }

    sort(edges, edges + e, cmp);
    int sumMST;

    for(int i = 0; i < e; i++){
        sum = unionMST(i, sum);
    }
    sumMST = sum;
    int secMST = INT_MAX;
    sum = 0;
    int j;
    for(j = 0; j < present.size(); j++){
        makeSet(v);
        edge = 0;

        for(int i = 0; i < e; i++){
            if(i == present[j]){
                continue;
            }
            sum = union2ndMST(i, sum);
        }

        if(edge != v - 1){
            sum = 0;
            continue;
        }

        if(secMST > sum){
            secMST = sum;
        }
        sum = 0;
    }
    
    return make_pair(sumMST, secMST);
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
        vector<vector<int>> gEdges(e);
        int v1, v2, wt;

        for(int i = 0; i < e; i++){
            cin >> v1 >> v2 >> wt;
            gEdges[i] = {v1, v2, wt};
        }

        auto res = secondMinimumSpanningTree(gEdges, v, e);
        cout << "Output of testcase " << 3 - t << endl;
        cout << "MST weight: " << res.first << endl;
        cout << "2nd MST weight: " << res.second;
        cout << endl << endl;
    }
}
