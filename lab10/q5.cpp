#include <iostream>
using namespace std;
#include<algorithm>
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


void solve(){
    int n;
    cin>>n;
    Graph* g = new Graph(n);
    for (int i=0;i<n;i++){
        int b;
        cin>>b;
        g->addedge(i,(i+b+1)%n);
    }
    g->SCC();
    vector <vector <int>> v = g->sccs;
    int c=0;
    for (int i=0;i<v.size();i++){
        if (v[i].size()>1){
            c+=v[i].size();
        }
        else{
            int id = v[i][0];
            if (count(g->adjlist[id].begin(),g->adjlist[id].end(),id)){
                c++;
            }
        }
    }
    cout<<c<<endl;
}



int main() {
	int t;
    cin>>t;
    while(t--){
        solve();
    }
	return 0;
}