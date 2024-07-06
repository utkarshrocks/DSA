#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int n;
    vector<vector<int>> adj;

    public:
    // we are only declaring the constructor and member functions inside class and will define outside the class using scope resolution operator
    Graph(int n); // parameterized constructor to take no. of nodes as input during object creation

    void addedge(int u, int v);

    void bfs(int start_node);
};

Graph::Graph(int n) // :: is scope resolution operator used for defining methods outside the class
{
    this -> n = n;
    adj.resize(n);
}

void Graph::addedge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::bfs(int start_node)
{
    vector<int> vis(n,0);
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
                vis[child] = 1;
                q.push(child);
            }
        }
    }
}

int main()
{
    Graph g(5);

    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(2,4);

    g.bfs(0);
}