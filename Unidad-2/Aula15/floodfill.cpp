#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/flood-fill/

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor){
    int p = image[sr][sc];
    image[sr][sc] = newColor;
    if(sr > 0 && image[sr - 1][sc] == p) floodFill(image, sr - 1, sc, newColor);
    if(sr + 1 < image.size() && image[sr + 1][sc] == p) floodFill(image, sr + 1, sc, newColor);
    if(sc > 0 && image[sr][sc - 1] == p) floodFill(image, sr, sc - 1, newColor);
    if(sc + 1 < image[sr].size() && image[sr][sc + 1] == p) floodFill(image, sr, sc + 1, newColor);
}

int main(){
    vector<vector<int>> x = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, newColor = 2;
    floodFill(x, sr, sc, newColor);

    return 1;
}