#include<iostream>
#include<bits/stdc++.h>
using namespace std;
      
      //We will use boundary DFS to solve this problem
        
      // Let's analyze when an 'O' cannot be flipped,
      // if it has atleast one 'O' in it's adjacent, AND ultimately this chain of adjacent 'O's is connected to some 'O' which lies on boundary of board
        
      //consider these two cases for clarity :
      /*
        O's won't be flipped          O's will be flipped
        [X O X X X]                   [X X X X X]     
        [X O O O X]                   [X O O O X]
        [X O X X X]                   [X O X X X] 
        [X X X X X]                   [X X X X X]
      
      So we can conclude if a chain of adjacent O's is connected some O on boundary then they cannot be flipped
      
      */
        
void DFS(vector<vector<char>>& board, int i, int j, vector<vector<bool>> &visited) {
    int m = board.size();
    int n = board[0].size();
        if(i<0 || j<0 || i>=m || j>=n || board[i][j] != 'O' || visited[i][j] == true) {
            return;
        } 
        visited[i][j] = true;
        DFS(board, i-1, j, visited);
        DFS(board, i+1, j, visited);
        DFS(board, i, j-1, visited);
        DFS(board, i, j+1, visited);
    }
    
    void solve(vector<vector<char>>& board) {
     int m = board.size();
       if(m == 0) return;  
        
     int n = board[0].size();
     vector<vector<bool>> visited(m, vector<bool>(n, false));
     
      //Moving over first and last row   
     for(int j=0; j<n; j++) {
             DFS(board, 0, j,  visited);
             DFS(board, m-1, j,  visited);
     }
     //Moving over firts and last col  
     for(int i=0; i<m; i++) {
             DFS(board, i, 0,  visited);
             DFS(board, i, n-1,  visited);
     }
        
     for(int i=0; i<m; i++)
         for(int j=0; j<n; j++) {
             if(visited[i][j] == false && board[i][j] == 'O') {
                 board[i][j] = 'X';
             }
         }
    }
int main(){





}


