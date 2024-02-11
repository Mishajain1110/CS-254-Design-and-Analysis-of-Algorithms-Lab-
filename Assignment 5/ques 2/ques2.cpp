#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int min_dice_throw(vector<int>& move, int N){
    vector<bool> visited(N, false);
    queue<pair<int, int>> q;
    visited[0] = true;
    q.push(make_pair(0, 0));
    pair<int, int> entry;

    while(!q.empty()){

        entry = q.front();
        int v = entry.first;

        if(v == N - 1){
            break;
        } 

        q.pop();

        for(int i = v + 1; i <= (v + 6) && i < N; i++){

            if(!visited[i]){
                pair<int, int> mypair;
                mypair.second = entry.second + 1;
                visited[i] = true;

                if(move[i] != -1){
                    mypair.first = move[i];
                }
                else{
                    mypair.first = i;
                }
                q.push(mypair);
            }

        }
    }

    return entry.second;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input2.txt", "r", stdin);
        freopen("output2.txt", "w", stdout);
    #endif
    int t;
    cin >> t;

    while(t--){
        int N;
        cin >> N;
        vector<int> moves(N);

        for(int i = 0; i < N; i++){
           cin >> moves[i];
        }

        int res = min_dice_throw(moves, N);
        cout << "Output of testcase " << 5 - t << ": " << res << endl;
    }

    return 0;
}