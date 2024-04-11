/*

Flood Fill
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.

Constraints:

m == image.length

n == image[i].length

1 <= m, n <= 50

0 <= image[i][j], newColor < 2^16

0 <= sr < m

0 <= sc < n



Example:



Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
 
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.


Expected Time Complexity: O(N), where N is the number of pixels in the image. We might process every pixel.

*/


#include<iostream>
#include<vector>
using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
int R;
int C;

void floodFillColour(vector<vector<int>> &area, int x, int y, int colour) {
    if(x >= 0 && x < R && y >= 0 && y < C)
        area[x][y] = colour;
    for(int k = 0; k < 4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];

        if(nx >= 0 && nx < R && ny >= 0 && ny < C && area[nx][ny] == 1) {
            floodFillColour(area, nx, ny, colour);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int newColor){
   R = image.size();
   C = image.size();
   floodFillColour(image, sr, sc, newColor);
   return image;
}