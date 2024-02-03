#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

double median_sorted_arrays(vector<int>& arr1, vector<int>& arr2){
    int m = arr1.size();
    int n = arr2.size();

    if(m > n){
        return median_sorted_arrays(arr2, arr1);
    }

    int start = 0;
    int end = m;

    while(start <= end){

        int i1 = start + (end - start) / 2;
        int i2 = (m + n + 1) / 2 - i1;

        int min1, min2, max1, max2;

        min1 = (i1 < m) ? arr1[i1] : INT_MAX;
        max1 = (i1 > 0) ? arr1[i1 - 1] : INT_MIN;
        min2 = (i2 < n) ? arr2[i2] : INT_MAX;
        max2 = (i2 > 0) ? arr2[i2 - 1] : INT_MIN;

        if(max1 <= min2 && max2 <= min1){
            if((m + n) % 2 != 0){
                double ans = max(max1, max2);
                return ans;
            }
            else{
                double res = (max(max1, max2) + min(min1, min2)) / 2.0;
                return res;
            }
        }

        if(max1 > min2){
            end = i1 - 1;
        }

        else{
            start = i1 + 1;
        }
    }

    return 0.0;
}

int main(){
     #ifndef ONLINE_JUDGE
        freopen("input2.txt", "r", stdin);
        freopen("output2.txt", "w", stdout);
    #endif
    int t;
    cin >> t;

    while(t--){
        int M, N;
        cin >> M >> N;
        vector<int> nums1(M);
        vector<int> nums2(N);

        for(int i = 0; i < M; i++){
            cin >> nums1[i];
        }

        for(int i = 0; i < N; i++){
            cin >> nums2[i];
        }

        int res = median_sorted_arrays(nums1, nums2);
        cout << "Output of testcase " << 5 - t << ": " << res << endl;
    }
    
    return 0;
}