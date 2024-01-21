#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& vec, int low, int high){
    int l = vec[high];
    int i = low;
    int j = low;
    while(j < high){
        if(vec[j] < l){
            swap(vec[i], vec[j]);
            i++;
        }
        j++;
    }
    swap(vec[i], vec[j]);
    return i;
}

int random(vector<int>& vec, int low, int high){
    int n = high - low + 1;
    int pivot = rand() % n;
    swap(vec[low + pivot], vec[high]);
    return partition(vec, low, high);
}

void median_use(vector<int>& vec, int low, int high, int k, int& p, int& q){
    if(low <= high){
        int index = random(vec, low, high);
        if(index == k){
            q = vec[index];
            if(p != -1){
                return;
            }
        }
        else if(index == k - 1){
            p = vec[index];
            if(q != -1){
                return;
            }
        }
        if(index >= k){
            return median_use(vec, low, index - 1, k, p, q);
        }
        else{
            return median_use(vec, index + 1, high, k, p, q);
        }
    }
    return;
}
int median(vector<int>& vec, int size){
    int res;
    int p = -1, q = -1;
    if(size % 2 != 0){
        median_use(vec, 0, size - 1, size / 2, p, q);
        res = q;
    }
    else{
        median_use(vec, 0, size - 1, size / 2, p, q);
        res = (p + q) / 2;
    }
    return res;
}
int main(){
   #ifndef ONLINE_JUDGE
	    freopen("input4.txt", "r", stdin);
	    freopen("output4.txt", "w", stdout);
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
        int res = median(vec, n);
        cout << res << endl;
    }
    return 0;
}
