#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int start, int end){
    int pivot = arr[start];
    int i = start; 
    int j = end;

    while(i < j){
        while(i < end && arr[i] <= pivot){
            i++;
        }
        while(j > start && arr[j] > pivot){
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[start], arr[j]);
    return j;
}
int kth_largest(vector<int>& arr, int k){
    int left = 0;
    int right = arr.size() - 1;

    if(left == right){
        return arr[0];
    }

    while(left <= right){
        int pivot = partition(arr, left, right);
        if(pivot == arr.size() - k){
            return arr[pivot];
        }
        else if(pivot > arr.size() - k){
            right = pivot - 1;
        }
        else if(pivot < arr.size() - k){
            left = pivot + 1;
        }
    }

    return -1;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input3.txt", "r", stdin);
        freopen("output3.txt", "w", stdout);
    #endif
    int t;
    cin >> t;

    while(t--){
        int N, k;
        cin >> N >> k;
        vector<int> nums(N);

        for(int i = 0; i < N; i++){
            cin >> nums[i];
        }

        int res = kth_largest(nums, k);
        cout << "Output of testcase " << 5 - t << ": " << res << endl;
    }
    
    return 0;
}