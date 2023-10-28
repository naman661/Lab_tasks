#include <bits/stdc++.h>
using namespace std;

struct edge{
    int to;
    int weight;
};

struct node{
    int val;
    int distance;
    bool operator>(const node& other) const{
        return distance>other.distance;
    }
};

class Graph{
    public:
        vector <vector <edge>> adjlist;

        Graph(int V) : adjlist(V){}

        void addedge(int v1, int v2, int w){
            adjlist[v1].push_back({v2,w});
        }

        vector <int> dks(int source);
};

vector <int> Graph::dks(int source){
    int V = adjlist.size();
    int N = sqrt(V);
    vector<int> visited(V,-1);
    vector <int> dist(V,INT_MAX);
    priority_queue<node,vector<node>,greater<node>> pq;

    dist[source] = 0;
    pq.push({source,0});

    while(!pq.empty()){
        node n = pq.top();
        pq.pop();   

        if(visited[n.val] == 1) continue;
        // cout<<"visiting: "<<n.val/N<<" "<<n.val%(N)<<endl;
        visited[n.val] = 1;

        for (edge e:adjlist[n.val]){
            if(visited[e.to] == 1) continue;
            int a = e.weight;
            if (dist[n.val]>e.weight){
                dist[e.to] = dist[n.val];
            }
            else{
                dist[e.to] = e.weight;
            }
            // cout<<"e: "<<e.to/N<<" "<<e.to%(N)<<": "<<dist[e.to]<<endl;

            pq.push({e.to,dist[e.to]});
            
        }
    }
    return dist;
}
    






class Solution {
public:
    vector <int> swimInWater(vector<vector<int>>& heights) {
        int a = heights.size();
        int b = heights[0].size();

        Graph* g = new Graph(a*b);
        for (int i=0;i<a;i++){
            for (int j=0;j<b;j++){
                if(i-1>=0){
                    g->addedge(b*i+j,b*(i-1)+j,heights[i-1][j]);
                }
                if (i+1<=a-1){
                    g->addedge(b*i+j,b*(i+1)+j,heights[i+1][j]);
                }
                if (j+1<=b-1){
                    g->addedge(b*i+j,b*(i)+j+1,heights[i][j+1]);
                }
                if (j-1>=0){
                    g->addedge(b*i+j,b*(i)+j-1,heights[i][j-1]);
                }
            }
        }

        vector <int> d = g->dks(0);
        return d;
    }
};

int main(){
    Solution* s = new Solution();
    vector <vector <int>> v = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    vector <int> d = s->swimInWater(v);
    for (int i=0;i<d.size();i++){
        cout<<i<<":"<<d[i]<<"  ";
    }
    cout<<endl;
}
