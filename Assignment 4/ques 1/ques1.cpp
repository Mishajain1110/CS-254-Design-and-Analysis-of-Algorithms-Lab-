#include <iostream>
#include <vector>
using namespace std;

long long int merge_arr(vector<long long>& arr, long long low, long long mid, long long high){
    long long i = low;
    long long j = mid + 1;
    long long inv_count = 0;
    vector<long long int> temp;

    while(i <= mid && j <= high){
        if(arr[i] > arr[j]){
           inv_count += (mid + 1 - i);
           temp.push_back(arr[j]);
           j++; 
        }
        else{
            temp.push_back(arr[i]);
            i++;
        }
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= high){
        temp.push_back(arr[j]);
        j++;
    }

    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
    return inv_count;
}

long long int inversion_helper(vector<long long>& arr, long long low, long long high){
    if(low >= high){
        return 0;
    }

    long long count = 0;

    int mid = low + (high - low) / 2;
    count += inversion_helper(arr, low, mid);
    count += inversion_helper(arr, mid + 1, high);
    count += merge_arr(arr, low, mid, high);

    return count;
}

long long int count_inversion(vector<long long>& nums, long long int n){
    return inversion_helper(nums, 0, n - 1);
}

int main(){
     #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    int t;
    cin >> t;

    while(t--){
        int N;
        cin >> N;
        vector<long long> nums(N);

        for(int i = 0; i < N; i++){
            cin >> nums[i];
        }

        long long res = count_inversion(nums, N);
        cout << "Output of testcase " << 5 - t << ": " << res << endl;
    }
    
    return 0;
}