#include<iostream>
#include<vector>
#include <queue>
using namespace std;

bool check_bipartite(vector<vector<int>> mat, vector<int> color, int s){
    color[s] = 1;
    queue<int> qu;
    qu.push(s);

   while(!qu.empty()){
    int curr = qu.front();
    qu.pop();

    for(int i = 0; i < mat.size(); i++){
        if(mat[curr][i] && color[i] == -1){
        color[i] = 1 - color[curr];
        qu.push(i);
        }
        else if(mat[curr][i] && color[curr] == color[i]){
            return false;
        }
    }

    }

    return true;
}

bool is_bipartite(vector<vector<int>> mat){
    vector<int> color(mat.size(), -1);

    for(int i = 0; i < mat.size(); i++){

        if(color[i] == -1){
            if(!check_bipartite(mat, color, i)){
                return false;
            }
        }

    }

    return true;
}

bool has_two_cliques(vector<vector<int>> mat){
    vector<vector<int>> comp_mat(mat.size(), vector<int>(mat[0].size()));

    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[0].size(); j++){

            if(i == j){
                comp_mat[i][j] = 0;
            }
            else if(mat[i][j]){
                comp_mat[i][j] = 0;
            }
            else{
                comp_mat[i][j] = 1;
            }

        }
    }

    return is_bipartite(comp_mat);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input3.txt", "r", stdin);
        freopen("output3.txt", "w", stdout);
    #endif
    int t;
    cin >> t;

    while(t--){
        int v;
        cin >> v;
        vector<vector<int>> mat(v, vector<int>(v));

        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                cin >> mat[i][j];
            }
        }
        
        string res;
        if(has_two_cliques(mat)){
            res = "YES";
        }
        else{
            res = "NO";
        }

        cout << "Output of testcase " << 5 - t << ": " << res << endl;
    }

    return 0;
}