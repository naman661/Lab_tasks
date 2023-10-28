#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <stack>

class Graph{
    public:
        int V;
        vector <vector <int>> adjlist;
        int time = 0;
        stack <int> S;
        vector <int> instack;
        vector <int> visited;
        vector <int> ll;
        vector <int> index;
        vector <vector <int> > sccs;
        void tarjan(int v);
        void SCC();
        Graph(int V){
            this->V = V;
            for (int i=0;i<V;i++){
                vector <int> v;
                adjlist.push_back(v);
                instack.push_back(-1);
                visited.push_back(-1);
                ll.push_back(-1);
                index.push_back(-1);
            }

        }

        void addedge(int v1,int v2){
            // cout<<"added edge "<<v1<<" "<<v2<<endl;
            adjlist[v1].push_back(v2);
        }


};

void Graph::tarjan(int v){
    // cout<<"tarjan: "<<v<<endl;
    ll[v] = index[v] = time;
    time++;
    visited[v] = 1;
    instack[v] = 1;
    S.push(v);

    for (int u:adjlist[v]){
        // cout<<"u "<<u<<endl;
        // cout<<"visited[u] = "<<visited[u]<<endl;
        if (visited[u] == -1){

            tarjan(u);
            ll[v] = min(ll[v],ll[u]);
        }

        else if(instack[u] == 1){
            ll[v] = min(ll[v],index[u]);
        }
    }

    if (ll[v] == index[v]){
        
        vector <int> scc;
        while (S.top() != v){
            int t = S.top();
            S.pop();
            scc.push_back(t);
            // cout << t << " ";

            instack[t] = -1;

        }
        int t = S.top();
        S.pop();
        scc.push_back(t);
        // cout << t << "\n";
        instack[t] = -1;
        sort(scc.begin(),scc.end());
        sccs.push_back(scc);

    } 
}

void Graph::SCC(){
    // cout<<"in SCC"<<endl;
    for (int i=0;i<V;i++){
        if (visited[i] == -1){
            tarjan(i);
        }
    }
}

class Solution
{
	public:
    
    vector<vector<int>> tarjans(int V, vector<int> adj[]){
        Graph* g = new Graph(V);
        for (int i=0;i<V;i++){
            for (auto j:adj[i]){
                g->addedge(i,j);
            }
        }
        g->SCC();
        vector <vector <int>> s = g->sccs;
        sort(s.begin(),s.end());
        return s;

    }
};




// int main() {
//     // Example usage:
//     Graph g(5);
//     g.addedge(1, 0);
//     g.addedge(0, 2);
//     g.addedge(2, 1);
//     g.addedge(0, 3);
//     g.addedge(3, 4);
//     cout<<"adjlist: ..................."<<endl;
//     for (int i=0;i<5;i++){
//         for (int j:g.adjlist[i]){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<"adjlist: ..................."<<endl;

//     g.SCC();
   

//     return 0;
// }

