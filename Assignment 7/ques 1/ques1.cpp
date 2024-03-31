#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static bool cmp(vector<int>& a, vector<int>& b){
    double r1 = (double)a[1] / (double)a[0];
    double r2 = (double)b[1] / (double)b[0];
    return r1 > r2;
}

vector<vector<int>> knapSack_greedy(int W, vector<int> weight, vector<int> value, int n){
    vector<vector<int>> pair(n);
    vector<vector<int>> seq;
    for(int i = 0; i < n; i++){
        pair[i] = {weight[i], value[i], i};
    }

    sort(pair.begin(), pair.end(), cmp);

    int ans = 0;
    int curr_wt = 0;

    for(int j = 0; j < n; j++){
        curr_wt += pair[j][0];
        if(curr_wt > W){
            curr_wt -= pair[j][0];
        }
        else{
            seq.push_back({pair[j][2], pair[j][0]});
            ans += pair[j][1];
        }
    }
    sort(seq.begin(), seq.end());
    vector<int> res;
    for(auto vec : seq){
        res.push_back(vec[0]);
    }
    return {{ans}, res};
}

vector<vector<int>> knapSack_optimized(int W, vector<int> weight, vector<int>value, int n){
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    vector<int> seq;
    vector<vector<int>> picked(n + 1, vector<int>(W + 1, false));

    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }

    for(int i = 0; i <= W; i++){
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){

            if(weight[i - 1] > j){
                dp[i][j] = dp[i - 1][j];
            }

            else{
                dp[i][j] = max(dp[i - 1][j - weight[i - 1]] + value[i - 1], dp[i - 1][j]);
                if(dp[i][j] == dp[i - 1][j - weight[i - 1]] + value[i - 1]){
                    picked[i][j] = true;
                }
            }

        }
    }
    int k = n;
    int l = W;
    while(k > 0 && l > 0){
        if(picked[k][l]){
            seq.push_back(k - 1);
            l -= weight[k - 1];
        }
        k -= 1;
    }
    sort(seq.begin(), seq.end());
    return {{dp[n][W]}, seq};
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    int t;
    cin >> t;

    while(t--){

        int W, n;
        cin >> W >> n;
        vector<int> weight(n);
        vector<int> val(n);

        for (int i = 0; i < n; i++){
            cin >> weight[i];
        }

        for (int i = 0; i < n; i++){
            cin >> val[i];
        }
        vector<vector<int>> res1 = knapSack_greedy(W, weight, val, n);
        vector<vector<int>> res2 = knapSack_optimized(W, weight, val, n);
        cout << "Output(using greedy approach) of testcase " << 5 - t << endl;
        cout << "Total cost: " << res1[0][0] << endl;
        cout << "Indices of weights taken: ";

        for(auto num : res1[1]){
            cout << num << " ";
        }

        cout << endl;
        cout << "Correct output of testcase " << 5 - t << endl;
        cout << "Total cost: " << res2[0][0] << endl;
        cout << "Indices of weights taken: ";

        for(auto num : res2[1]){
            cout << num << " ";
        }
        cout << endl << endl;
    }

    return 0;
}
