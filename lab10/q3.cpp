#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct edge{
    int to;
    int weight;
};


struct node{
    int id;
    int distance;
    bool operator>(const node& other) const{
        return distance > other.distance;
    }
};



class Graph{
    public:
        vector<vector <edge>> adjlist;

        Graph(int V) : adjlist(V) {}

        void addedge(int v1, int v2, int w){
            adjlist[v1].push_back({v2,w});
        }

        vector <int> dks(int source);
};

vector <int> Graph::dks(int source){
    int V = adjlist.size();
    vector<int> visited(V,-1);
    vector<int> dist(V,INT_MAX);
    priority_queue <node, vector<node>,greater<node>> pq;
    dist[source] = 0;
    pq.push({source,0});

    while(!pq.empty()){
        node current = pq.top();
        pq.pop();
        
        if (visited[current.id] == 1) continue;

        visited[current.id] = 1;

        for (edge e:adjlist[current.id]){
            int alt = dist[current.id] + e.weight;
            if (alt<dist[e.to]){
                dist[e.to] = alt;
                pq.push({e.to,dist[e.to]});
            }
        }
    }
    return dist;
}

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        Graph* g = new Graph(V);
        for (int i=0;i<V;i++){
            int v1 = i;
            for (int j=0;j<adj[i].size();j++){
                int v2 = adj[i][j][0];
                int w = adj[i][j][1];
                g->addedge(v1,v2,w);
            }
            
        }
        vector <int> dist = g->dks(S);
        return dist;
    }
};


