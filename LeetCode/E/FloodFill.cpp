#include <bits/stdc++.h>
using namespace std;

void Fx(vector<vector<int>> &image, int i, int j, int newColor, int origin) {
    if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != origin) return;
    image[i][j] = newColor;
    Fx(image, i-1, j, newColor, origin);
    Fx(image, i, j+1, newColor, origin);
    Fx(image, i+1, j, newColor, origin);
    Fx(image, i, j-1, newColor, origin);
} 

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {   
    if (image[sr][sc] == newColor) return image;
    Fx(image, sr, sc, newColor, image[sr][sc]);
    return image;    
}

int main(int argc, char const *argv[]) {
    vector<vector<int>> x = {{1,1,1}, {1,1,0}, {1,0,1}};
    floodFill(x, 1, 1, 2);

    for (auto i : x) {
        for (int j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }

    return 0;
}
