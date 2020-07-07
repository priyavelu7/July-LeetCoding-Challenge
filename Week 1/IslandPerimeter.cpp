/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16
*/
class Solution {
public:
int dfs(vector<vector<int>> &grid, int i, int j){
  if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size()) return 1;
  if(grid[i][j]==0) return 1;
  if(grid[i][j]==2) return 0;
  grid[i][j]=2;
  int count=0;
  count+=dfs(grid,i-1,j);
  count+=dfs(grid,i,j-1);
  count+=dfs(grid,i+1,j);
  count+=dfs(grid,i,j+1);
  return count;
}
int islandPerimeter(vector<vector<int>>& grid) {
  int n=grid.size();
  if(n==0) return 0;
  int m=grid[0].size();
  int perimeter=0,count;
  for(int i=0;i<n;i++)
  for(int j=0;j<m;j++){
    count=0;
    if(grid[i][j]==1)
      perimeter=dfs(grid,i,j);
  }
  return perimeter;
}
};

