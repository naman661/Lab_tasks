#include <iostream>
using namespace std;
#include <vector>
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





class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        Graph* g = new Graph(V);
        for (vector <int> v:prerequisites){
            if (v[1]==v[0]){
                return false;
            }
            g->addedge(v[1],v[0]);
        }
        g->SCC();
        vector <vector <int>> s = g->sccs;
        for (vector<int> v:s){
            if (v.size()>1){
                return false;
            }
        }
        return true;

    }
};
