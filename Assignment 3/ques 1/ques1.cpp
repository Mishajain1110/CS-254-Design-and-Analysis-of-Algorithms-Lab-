#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void transform_matrix(vector<vector<int>> &matrix, int maximum, int m, int n ){
    
    int p = 0;
    while(maximum > (pow(2, p))){
        p++;
    }
    maximum = pow(2, p);
    for(int i = 0; i < maximum; i++){
        if(i < m){

            for(int j = n; j < maximum; j++){
                matrix[i].push_back(0);
            }
        }
        else{
            vector<int> v(maximum);
            matrix.push_back(v);
        }
    }
    return;
}

void matrix_Addition(vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>>& ans, int row, int col,int len,int width){
    for(int i = row; i < (row + len); i++){
        for(int j = col; j < (col + width); j++){
            ans[i][j] = A[i][j] + B[i][j];
        }
    }
    return;
}

vector<vector<int>> matrix_Multiplication(vector<vector<int>> A,vector<vector<int>> B, int row, int col, int row1, int col1, int row2, int col2, int len, vector<vector<int>>& result){
    if(len == 1){
        result[row][col] = A[row1][col1] * B[row2][col2];
        return result;
    }
    if(len == 2){

        result[row][col] = A[row1][col1] * B[row2][col2] + A[row1][col1+1] * B[row2+1][col2];

        result[row][col+1] = A[row1][col1] * B[row2][col2+1] + A[row1][col1+1] * B[row2+1][col2+1];

        result[row+1][col] = A[row1+1][col1] * B[row2][col2] + A[row1+1][col1+1] * B[row2+1][col2];

        result[row+1][col+1] = A[row1+1][col1] * B[row2][col2+1] + A[row1+1][col1+1] * B[row2+1][col2+1];
        return result;
        
    }

    matrix_Addition(matrix_Multiplication(A, B, row, col, row1, col1, row2, col2, len / 2, result), matrix_Multiplication(A, B, row, col, row1, col1 + len / 2, row2 + len / 2, col2, len / 2, result), result, row, col, len / 2, len / 2);

    matrix_Addition(matrix_Multiplication(A, B, row, col + len / 2, row1, col1, row2, col2 + len / 2, len / 2, result), matrix_Multiplication(A, B, row, col + len / 2, row1, col1 + len / 2, row2 + len / 2, col2 + len / 2, len / 2, result), result, row, col + len / 2, len / 2, len / 2);

    matrix_Addition(matrix_Multiplication(A, B, row + len / 2, col, row1 + len / 2, col1, row2, col2, len / 2, result), matrix_Multiplication(A, B, row + len / 2, col, row1 + len / 2, col1 + len / 2, row2 + len / 2, col2 + len / 2, len / 2, result), result, row + len / 2, col, len / 2, len / 2);

    matrix_Addition(matrix_Multiplication(A, B, row + len / 2, col + len / 2, row1 + len / 2, col1, row2, col2 + len / 2, len / 2, result), matrix_Multiplication(A, B, row + len / 2, col + len / 2, row1 + len / 2, col1 + len / 2, row2 + len / 2, col2 + len / 2, len / 2, result), result, row + len / 2, col + len / 2, len / 2, len / 2);

    return result;
}


void print(vector<vector<int>> matrix, int row, int col, int len, int width){

    for(int i = row;i < (row + len); i++){
        for(int j = col; j < (col + width); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void print(vector<vector<int>> matrix){

    int m = matrix.size();
    int n = matrix[0].size();

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int m, n, p, q;
        cin >> m >> n >> p >> q;
        vector<vector<int>> A(m, vector<int>(n, 0)), B(p, vector<int>(q, 0)), res(m, vector<int>(q, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }
        for(int i = 0; i < p; i++){
            for(int j = 0; j < q; j++){
                cin >> B[i][j];
            }
        }
        int maximum = max(max(m, n), max(p, q));
        transform_matrix(res, maximum, m, q);
        transform_matrix(A, maximum, m, n);
        transform_matrix(B, maximum, p, q);

        cout << "Output of testcase " << 5 - t << ": " << endl;
        res = matrix_Multiplication(A, B, 0, 0, 0, 0, 0, 0, res.size(), res);
        print(res, 0, 0, m, q);
    }
}