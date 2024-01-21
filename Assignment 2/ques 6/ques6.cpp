#include<iostream>
#include<vector>
using namespace std;

int find_pivot_index(vector<int>& vec, int start, int end){
    int mid = start + (end - start) / 2;
    int maximum = max(start, max(mid, end));
    if(maximum == start){
        return max(mid, end);
    }
    if(maximum == end){
        return max(start, mid);
    }
    return max(start, end);
}

int partition(vector<int>& vec, int start, int end){
    int pivot_index = find_pivot_index(vec, start, end);
    int pivot_value = vec[pivot_index];
    int target = start;
    swap(vec[pivot_index], vec[end]);
    int pivot_temp = end;

    for(int i = start; i < pivot_temp; i++){
        int curr = vec[i];
        if(curr < pivot_value){
            swap(vec[i], vec[target]);
            target++;
        }
    }
    swap(vec[target], vec[pivot_temp]);
    return target;
}

void quick_sort(vector<int>& vec, int start, int end){
    if(start >= end){
        return;
    }
    int index = partition(vec, start, end);
    quick_sort(vec, start, index - 1);
    quick_sort(vec, index + 1, end);
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input6.txt", "r", stdin);
	    freopen("output6.txt", "w", stdout);
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
        quick_sort(vec, 0, n - 1);
        cout << "Output of testcase " << 5 - t << ": ";

        for(int i = 0; i < n; i++){
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}