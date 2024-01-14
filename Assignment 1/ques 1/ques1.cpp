#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution{
public:
    int maxsum(vector<int> &nums){

        int largest = INT_MIN;
        int second_largest = INT_MIN;

        for (int i = 0; i < nums.size(); i++){

            if (largest <= nums[i]){
                second_largest = largest;
                largest = nums[i];
            }
            else if (second_largest < nums[i] && largest >= nums[i]){
                second_largest = nums[i];
            }
        }

        return largest + second_largest;
    }
};

int main(){
    ifstream inputFile("ques1_input.txt");

    if (!inputFile.is_open()){
        cerr << "Error(input file)!" << endl;
        return 1;
    }

    Solution calculator;
    ofstream outputFile("ques1_output.txt");

    for (int i = 1; i <= 5; i++){

        int n;
        inputFile >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++){
            inputFile >> arr[i];
        }

        int result = calculator.maxsum(arr);

        if (!outputFile.is_open()){
            cerr << "Error(output file)!" << endl;
        }

        outputFile << "Maximum sum in testcase " << i << ": " << result << endl;
    }

    return 0;
}