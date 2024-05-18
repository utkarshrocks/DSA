#include <bits/stdc++.h>
using namespace std;

void addedge(vector<vector<int>>& adj,int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(vector<vector<int>>& adj, vector<int>& vis, int start_node)
{
    queue<int> q;

    vis[start_node] = 1;
    q.push(start_node);

    while(!q.empty())
    {
        int curr_node = q.front();
        cout<<curr_node<<" ";
        q.pop();

        for(int child : adj[curr_node])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = 1;
            }
        }
    }
}

int main()
{
    int n = 5;
    vector<vector<int>> adj(n);
    vector<int> vis(n,0);

    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,2);
    addedge(adj,1,3);
    addedge(adj,2,4);

    bfs(adj,vis,0);
}