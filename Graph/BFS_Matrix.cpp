#include<bits/stdc++.h>
using namespace std;

vector<int> dir_row = {0,1,0,-1};
vector<int> dir_col = {1,0,-1,0};

bool isValid(vector<vector<int>>& vis,int x,int y,int r,int c)
{
    if(x < 0 or x >= r or y < 0 or y >= c)
    {
        return false;
    }
    if(vis[x][y])
    {
        return false;
    }
    return true;
}

void bfs(vector<vector<int>>& matrix,vector<vector<int>>& vis,int start_row,int start_col,int r,int c)
{
    queue<pair<int,int>> q;

    vis[start_row][start_col] = 1;
    q.push({start_row,start_col});

    while(!q.empty())
    {
        pair<int,int> curr_node = q.front();
        int curr_row = curr_node.first;
        int curr_col = curr_node.second;
        cout<<matrix[curr_row][curr_col]<<" ";
        q.pop();

        for(int i=0;i<4;i++)
        {
            int child_row = curr_row + dir_row[i];
            int child_col = curr_col + dir_col[i];

            if(isValid(vis,child_row,child_col,r,c))
            {
                vis[child_row][child_col] = 1;
                q.push({child_row,child_col});
            }
        }
    }
}

int main()
{
    int r = 4, c = 4;
    vector<vector<int>> matrix(r,vector<int>(c));
    vector<vector<int>> vis(r,vector<int>(c,0));

    matrix = { { 1, 2, 3, 4 },
               { 5, 6, 7, 8 },
               { 9, 10, 11, 12 },
               { 13, 14, 15, 16 } };
    
    bfs(matrix,vis,0,0,r,c);

}