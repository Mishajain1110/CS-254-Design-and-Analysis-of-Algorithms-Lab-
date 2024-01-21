#include <iostream>
#include <vector>
using namespace std;

void merge_inplace(vector<int>& vec, int start, int mid, int end){
    int second_start = mid + 1;
    if(vec[mid] <= vec[second_start]){
        return;
    }
    while(start <= mid && second_start <= end){
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
            mid++;
            second_start++;
        }
    }
}

void merge_sort(vector<int>& vec, int low, int high){
    if(low == high){
        return;
    }
    int mid = low + (high - low) / 2;
    merge_sort(vec, low, mid);
    merge_sort(vec, mid + 1, high);
    merge_inplace(vec, low,mid, high);
}

void inplace(vector<int>& vec, int n){
    merge_sort(vec, 0, n - 1);
}
int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input3.txt", "r", stdin);
	    freopen("output3.txt", "w", stdout);
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
        inplace(vec, n);

        for(auto element : vec){
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}