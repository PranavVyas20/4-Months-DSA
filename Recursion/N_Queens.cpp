#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;

bool isSafeToPlace(vector<vector<int>> chessBoard, int row, int col) {
    // Check upwards
    for(int i = row ; i >= 0; i--) {
        if (chessBoard[i][col] == 1) return false;
    }
    // Check rightDiagnol
    for(int i = row, j = col; i >= 0 && j <= chessBoard.size() - 1; i--, j++) {
        if (chessBoard[i][j] == 1) return false;
    }
    // Check leftDiagnol
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (chessBoard[i][j] == 1) return false;
    }
    return true;
}
void nQueensHelper(vector<vector<int>> &chessBoard, int row, vector<string> &localAns) {
    // Base cases
    if(row == chessBoard.size()) {
        ans.push_back(localAns);
        return;
    }

    string str(chessBoard.size(),'.');

    for(int col = 0; col < chessBoard.size(); col++) {
        
        if(isSafeToPlace(chessBoard, row, col)) {

            chessBoard[row][col] = 1;
            str[col] = 'Q';
            localAns.push_back(str);

            nQueensHelper(chessBoard, row + 1, localAns);

            chessBoard[row][col] = 0;
            str[col] = '.';
            localAns.pop_back();

        }
    }
}


int main(){
 vector<vector<int>> chessBoard(4, vector<int> (4, 0));
        vector<string> localAns;
        nQueensHelper(chessBoard, 0, localAns);




}

