#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool existHelper(vector<vector<char>> & board, int row, int col, int wordIdx, string word) {
    // If we have found all the letters, return true
    if(wordIdx == word.size()) return true;

    // Out of the grid, return
    if( 
    row < 0 || 
    col < 0 || 
    row >= board.size() || 
    col >= board[0].size() || 
    board[row][col] == '0' ||
    board[row][col] != word[wordIdx]
    ) return false;
    
    char localCh = board[row][col];
    cout << board[row][col] << "  " << wordIdx << endl;

    board[row][col] = '0';

    bool foundLeft = existHelper(board, row, col - 1, wordIdx + 1, word);
    bool foundRight = existHelper(board, row, col + 1, wordIdx + 1, word);
    bool foundUp = existHelper(board, row - 1, col, wordIdx + 1, word);
    bool foundDown = existHelper(board, row + 1, col, wordIdx + 1, word);
    board[row][col] = localCh;

    return foundLeft || foundDown || foundUp || foundRight;
}


bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {

            if(board[i][j] == word[0]) {
                if(existHelper(board, i, j, 0, word)) return true;
            }
        }
    }
    return false;
}
int main(){
vector<vector<char>> inputVector = { 
                                    {'A', 'B', 'C', 'E'}, 
                                    {'S', 'F', 'C', 'S'}, 
                                    {'A', 'D', 'E', 'E'} 
                                   };
bool ans= exist(inputVector, "ABCB");
cout << ans;



}

