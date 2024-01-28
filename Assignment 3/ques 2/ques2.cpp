#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int max_subarray_sum(vector<int>& vec, int start, int end){
    if(start == end){
        return vec[start];
    }
    if(start > end){
        return INT_MIN;
    }
    int max_sum;
    int mid = start + (end - start) / 2;

    int left = max_subarray_sum(vec, start, mid - 1);
    int right = max_subarray_sum(vec, mid + 1, end);

    int left_sum = 0;
    int max_left = vec[mid];

    for(int i = mid; i >= start; i--){
        left_sum += vec[i];
        max_left = max(left_sum, max_left);
    }

    int right_sum = 0;
    int max_right = vec[mid + 1];

    for(int i = mid + 1; i <= end; i++){
        right_sum += vec[i];
        max_right = max(right_sum, max_right);
    }
    int max_middle = max(max_left, max(max_right, max_left + max_right));
    max_sum = max(left, max(right, max_middle));
    return max_sum;

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
        vector<int> vec(n);

        for(int i = 0; i < n; i++){
            cin >> vec[i];
        }

        cout << "Output of testcase " << 5 - t << ": ";
        int ans = max_subarray_sum(vec, 0, n - 1);
        cout << ans << endl;
    }
    return 0;
}