#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Solution{
public:
    int knapSack(int W, vector<int> &weight, vector<int> &val, int N){
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));

        for (int i = 0; i < W + 1; i++){
            dp[0][i] = 0;
        }

        for (int j = 0; j < N + 1; j++){
            dp[j][0] = 0;
        }

        for (int i = 1; i < N + 1; i++){

            for (int j = 1; j < W + 1; j++){

                if (weight[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j - weight[i - 1]] + val[i - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[N][W];
    }
};

int main()
{
    ifstream inputFile("ques2_input.txt");

    if (!inputFile.is_open()){
        cerr << "Error(input file)!" << endl;
        return 1;
    }

    Solution knapsack_calc;
    ofstream outputFile("ques2_output.txt");

    for (int i = 1; i <= 5; i++){

        int W, N;
        inputFile >> W >> N;
        vector<int> weight(N);
        vector<int> val(N);

        for (int i = 0; i < N; i++){
            inputFile >> weight[i];
        }

        for (int i = 0; i < N; i++){
            inputFile >> val[i];
        }

        int result = knapsack_calc.knapSack(W, weight, val, N);

        if (!outputFile.is_open()){
            cerr << "Error(output file)!" << endl;
        }

        outputFile << "Maximum total value in testcase " << i << ": " << result << endl;
    }

    return 0;
}
