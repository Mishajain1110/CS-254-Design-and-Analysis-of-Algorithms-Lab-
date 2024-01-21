#include <iostream>
#include <vector>
#include <fstream>
#include <limits.h>
using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
	    freopen("input5.txt", "r", stdin);
	    freopen("output5.txt", "w", stdout);
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

        int minima = INT_MAX;
        int second_minima = INT_MAX;

        for(int i = 0; i < n; i++){
            if(vec[i] < minima){
                second_minima = minima;
                minima = vec[i];
            }
            else if(second_minima > vec[i]){
                second_minima = vec[i];
            }
        }
        cout << "Output of testcase " << 5 - t << ": ";
        cout << "minima: " << minima << " " << "second_minima: " << second_minima << endl;
    }
    
}