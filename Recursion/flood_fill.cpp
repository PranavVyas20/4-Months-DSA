#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void floodFillHelper(vector<vector<int>> &img, int totalRow, int totalCol, int sr, int sc, int color, int oldColor) {
// Base cases here
if(sr >= totalRow || sr < 0 || sc >= totalCol || sc < 0 ) {
    return;
}

img[sr][sc] = color;

floodFillHelper(img, totalRow, totalCol, sr - 1, sc, color, oldColor); // up
floodFillHelper(img, totalRow, totalCol, sr + 1, sc, color, oldColor); // down
floodFillHelper(img, totalRow, totalCol, sr, sc - 1, color, oldColor); // left
floodFillHelper(img, totalRow, totalCol, sr, sc + 1, color, oldColor); // right
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if(color == image[sr][sc]) return image; // starting point is already covered so no need to color more
    floodFillHelper(image, image.size(), image[0].size(), sr, sc, color, image[sr][sc]);
    return image;
}

int main(){





}


