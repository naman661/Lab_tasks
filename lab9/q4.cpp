#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector <vector<int>>& adjlist, vector<int>& visited){
    // cout<<"dfs: "<<v<<endl;
    visited[v] = 1;
    for (int u:adjlist[v]){
        // cout<<"u: "<<u<<endl;
        if (visited[u] == -1){
            dfs(u,adjlist,visited);
        }
    }
}


bool possible(vector<vector<int>>& rooms){
    int V = rooms.size();
    vector <int> v;
    vector <vector <int>> adjlist(V,v);

    for (int i=0;i<V;i++){
        for (int j:rooms[i]){
            adjlist[i].push_back(j);
        }
    }
    vector <int> visited(V,-1);
    dfs(0,adjlist,visited);
    bool t = true;
    for (int i=0;i<visited.size();i++){
        if (visited[i] == -1){
            return false;
        }
    }
    return true;
}


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        return possible(rooms);
    }
};

// int main(){
//     Solution* s = new Solution();
//     vector <vector <int>> v = {{1},{},{0,3},{1}};
//     cout<<s->canVisitAllRooms(v)<<endl;
// }