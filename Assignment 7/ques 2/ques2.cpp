#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

static bool cmp(vector<int>& a, vector<int>& b){
    return a[2] > b[2];
}
// greedy algorithm gives optimal solution but will not work for large test cases
vector<vector<int>> jobScheduling_greedy(vector<vector<int>> job, int n){
    sort(job.begin(), job.end(), cmp);
    vector<int> visited(n + 1, 0);
    int max_profit = 0;
    vector<int> res(n);
    for(int i = 0; i < n; i++){

        if(!visited[job[i][1]]){
            visited[job[i][1]] = 1;
            max_profit += job[i][2];
            res[job[i][1]] = i;
        }

        else{
            for(int j = job[i][1] - 1; j >= 1; j--){

                if(!visited[j]){
                    visited[j] = 1;
                    res[j] = i;
                    max_profit += job[i][2];
                    break;
                }

            }
        }

    }
    vector<vector<int>> seq;
    for(int i = 0; i <= n; i++){
        if(visited[i]){
            seq.push_back({job[res[i]][1], job[res[i]][0]});
        }
    }
    sort(seq.begin(), seq.end());
    vector<int> ans;
    for(auto vec : seq){
        ans.push_back(vec[1]);
    }
    return {{max_profit}, ans};
}

vector<vector<int>> jobScheduling_optimal(vector<vector<int>> job, int n){
    map<int, vector<vector<int>>> m;
    vector<vector<int>> sequence; 

    for(int i = 0; i < n; i++){
        m[job[i][1]].push_back({job[i][2], job[i][1], job[i][0]});
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    for(auto pair : m){

        for(auto num : pair.second){
            pq.push(num);
        }
        while(pq.size() > pair.first){
            pq.pop();
        }

    }
    int max_profit = 0;

    while(!pq.empty()){
        max_profit += pq.top()[0];
        sequence.push_back({pq.top()[1], pq.top()[2]});
        pq.pop();
    }

    vector<int> seq;
    sort(sequence.begin(), sequence.end());

    for(auto pair : sequence){
        seq.push_back(pair[1]);
    }

    return {{max_profit}, seq};
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input2.txt", "r", stdin);
        freopen("output2.txt", "w", stdout);
    #endif
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> jobs(n);

        for(int i = 0; i < n; i++){
            int a, b, c;
            cin >> a >> b >> c;
            jobs[i] = {a, b, c};
        }

        vector<vector<int>> res1 = jobScheduling_greedy(jobs, n);
        vector<vector<int>> res2 = jobScheduling_optimal(jobs, n);
        cout << "Output(using greedy approach) of testcase " << 5 - t << endl;
        cout << "Maximum Profit: " << res1[0][0] << endl;
        cout << "Maximum profit job sequence: ";

        for(auto num : res1[1]){
            cout << num << " ";
        }

        cout << endl;
        cout << "Correct output of testcase " << 5 - t << endl;
        cout << "Maximum Profit: " << res2[0][0] << endl;
        cout << "Maximum profit job sequence: ";

        for(auto num : res2[1]){
            cout << num << " ";
        }
        cout << endl << endl;
}

return 0;
}
