#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits.h>


using namespace std;

const int maximum = INT_MAX;

class Solution{
public:
    int tsp(int mask, int pos, const vector<vector<int>> &cost, vector<vector<int>> &dp){
        int n = cost.size();

        if (mask == (1 << n) - 1){
            return cost[pos][0];
        }

        if (dp[mask][pos] != -1){
            return dp[mask][pos];
        }
        int res = maximum;

        for (int i = 0; i < n; i++){

            if ((mask & (1 << i)) == 0){

                int newmask = mask | (1 << i);
                res = min(res, cost[pos][i] + tsp(newmask, i, cost, dp));
            }
        }
        return dp[mask][pos] = res;
    }

    int solve(const vector<vector<int>> &cost){
        int n = cost.size();
        vector<vector<int>> dp(1 << n, vector<int>(n, -1));
        return tsp(1, 0, cost, dp);
    }
};

int main(){
    ifstream inputFile("ques3_input.txt");

    if (!inputFile.is_open()){
        cerr << "Error(input file)!" << endl;
        return 1;
    }

    Solution tsp_calc;

    ofstream outputFile("ques3_output.txt");

    for (int i = 1; i <= 5; i++){
        int num_cities;
        inputFile >> num_cities;

        vector<vector<int>> cost(num_cities, vector<int>(num_cities));

        for (int i = 0; i < num_cities; i++){

            for (int j = 0; j < num_cities; j++){
                inputFile >> cost[i][j];
            }
        }

        int minimum_cost = tsp_calc.solve(cost);

        if (!outputFile.is_open()){
            cerr << "Error(output file)!" << endl;
        }

        outputFile << "Minimum cost in testcase " << i << ": " << minimum_cost << endl;
    }

    return 0;
}