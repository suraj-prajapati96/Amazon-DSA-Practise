#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&grid, int i, int j, int row, int col){
    if(i<0 || j<0 || i>=row || j>=col || grid[i][j]!=1){
        return;
    }
    if(grid[i][j]==1){
        grid[i][j]=0;
        dfs(grid, i-1,j,row,col);
        dfs(grid,i+1,j,row,col);
        dfs(grid,i,j+1,row,col);
        dfs(grid,i,j-1,row,col);
    }
}

int countIslands(vector<vector<int>>&grid){
    int row = grid.size();
    int col = grid[0].size();
    int count=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(grid[i][j]==1){
                count++;
                dfs(grid,i,j,row,col);
            }
        }
    }
    return count;
}
int main(){
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };
    cout<<countIslands(grid);
    return 0;
}