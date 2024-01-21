#include <iostream>
#include <vector>
using namespace std;

void merge_inplace(vector<int>& vec, int start, int m, int end){
    int second_start = m + 1;
    if(vec[m] <= vec[second_start]){
        return;
    }
    while(start <= m && second_start <= end){
        if(vec[start] <= vec[second_start]){
            start++;
        }
        else{
            int val = vec[second_start];
            int idx = second_start;
            while(idx != start){
                vec[idx] = vec[idx - 1];
                idx--;
            }
            vec[start] = val;
            start++;
            m++;
            second_start++;
        }
    }
}

int main(){
    // vector<int> vec = {2,2,2,2,2,2,2,2};
    // merge_inplace(vec, 0, 3, 8);
    // for(auto ele : vec){
    //     cout << ele << " ";
    // }
    // return 0
    #ifndef ONLINE_JUDGE
	    freopen("input2.txt", "r", stdin);
	    freopen("output2.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> vec(n);

        for(int i = 0; i < n; i++){
            cin >> vec[i];
        }
        merge_inplace(vec, 0, m - 1, n - 1);

        cout << "Output of testcase " << 5 - t << ": ";
        for(int i = 0; i < n; i++){
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}