#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1c.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--){
        int m, n;
        cin >> m >> n;
        vector<int> vec1(m), vec2(n), res;

        for (int i = 0; i < m; i++){
            cin >> vec1[i];
        }

        for (int i = 0; i < n; i++){
            cin >> vec2[i];
        }

        int p = 0, q = 0;

        while (p < m && q < n){
            if (vec1[p] > vec2[q]){
                q++;
            }
            else if (vec1[p] < vec2[q]){
                p++;
            }
            else if (vec1[p] == vec2[q]){
                res.push_back(vec1[p]);
                p++;
                q++;
            }
        }
        cout << "Output of testcase " << 5 - t << ": ";
        for (int num : res){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
