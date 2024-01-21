#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int different_element(vector<int> vec, int num){
    while(num < vec.size() - 1 && vec[num] == vec[num + 1]){
        num++;
    }
    return num + 1;
}
int main(){

    #ifndef ONLINE_JUDGE
	    freopen("input1.txt", "r", stdin);
	    freopen("output1b.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    while(t--){
        int m, n;
        cin >> m >> n;
        vector<int> vec1(m), vec2(n), res;

        for(int i = 0; i < m; i++){
            cin >> vec1[i];
        }

        for(int i = 0; i < n; i++){
            cin >> vec2[i];
        }

        int p = 0, q = 0;

        while(p < m && q < n){

            if(vec1[p] > vec2[q]){
                res.push_back(vec2[q]);
                q = different_element(vec2, q);
            }
            else if(vec1[p] < vec2[q]){
                res.push_back(vec1[p]);
                p = different_element(vec1, p);
            }
            else if(vec1[p] == vec2[q]){
                res.push_back(vec1[p]);
                p = different_element(vec1, p);
                q = different_element(vec2, q);
            }

        }

        while(p < m){
            res.push_back(vec1[p]);
            p = different_element(vec1, p);
        }

        while(q < n){
            res.push_back(vec2[q]);
            q = different_element(vec2, q);
        }

        cout << "Output of testcase " << 5 - t << ": ";
        
        for(int num : res){
            cout << num << " ";
        }

        cout << endl;
    }
    return 0;
}

