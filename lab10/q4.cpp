
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
            int alt =  e.weight;
            int d = max(alt,dist[current.id]);
            if (d<dist[e.to]){
                dist[e.to] = d;
                pq.push({e.to,dist[e.to]});
            }
        }
    }
    return dist;
}



class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int a = heights.size();
        int b = heights[0].size();

        Graph* g = new Graph(a*b);
        for (int i=0;i<a;i++){
            for (int j=0;j<b;j++){
                if(i-1>=0){
                    g->addedge(b*i+j,b*(i-1)+j,abs(heights[i][j] - heights[i-1][j]));
                }
                if (i+1<=a-1){
                    g->addedge(b*i+j,b*(i+1)+j,abs(heights[i][j] - heights[i+1][j]));
                }
                if (j+1<=b-1){
                    g->addedge(b*i+j,b*(i)+j+1,abs(heights[i][j] - heights[i][j+1]));
                }
                if (j-1>=0){
                    g->addedge(b*i+j,b*(i)+j-1,abs(heights[i][j] - heights[i][j-1]));
                }
            }
        }

        vector <int> d = g->dks(0);
        return d.back();

    }
};

