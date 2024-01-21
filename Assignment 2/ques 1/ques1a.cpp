#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
	    freopen("input1.txt", "r", stdin);
	    freopen("output1a.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    while(t--){
        int m, n;
        cin >> m >> n;
        vector<int> vec1(m), vec2(n), res(m + n);

        for(int i = 0; i < m; i++){
            cin >> vec1[i];
        }

        for(int i = 0; i < n; i++){
            cin >> vec2[i];
        }

        int p = 0, q = 0, r = 0;

        while(p < m && q < n){
            if(vec1[p] > vec2[q]){
                res[r] = vec2[q];
                q++;
                r++;
            }
            else if(vec1[p] <= vec2[q]){
                res[r] = vec1[p];
                p++;
                r++;
            }
        }

        while(p < m){
            res[r] = vec1[p];
            p++;
            r++;
        }
        
        while(q < n){
            res[r] = vec2[q];
            q++;
            r++;
        }
        cout << "Output of testcase " << 5 - t << ": ";
        for(int k = 0; k < m + n; k++){
            cout << res[k] << " ";
        }
        cout << endl;
    }
    return 0;
}

