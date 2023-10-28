#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};




class Solution {
public:
    
    vector <vector <Node*>> ans; 
    vector <int> visited;
    Solution(){
        vector <Node*> a;
        ans = vector<vector<Node*>>(101,a);
        vector <int> ak(101,-1);
        visited = ak;
    }
    Node* cloneGraph(Node* node) {
        // cout<<"clone: "<<node->val<<endl;
        cc(node,this->visited);
        vector <Node*> n;
        Node* ne = new Node();
        n.push_back(ne);
        for (int i=1;i<visited.size();i++){
            if (visited[i] == -1){
                break;
            }
            else{
                Node* ne = new Node();
                n.push_back(ne);
            }
        }
        for (int i=1;i<n.size();i++){
            n[i]->val = i;
            n[i]->neighbors = ans[i];
        }
        return n[1];
    }
    void cc(Node* node,vector <int>& visited);
};
    
    
void Solution::cc(Node* node,vector<int>& visited){
    // for(int i:visited){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // cout<<"here"<<endl;
    visited[node->val] = 1;
    // cout<<"cc: "<<node->val<<endl;
    for (Node* u:node->neighbors){
        ans[node->val].push_back(u);
        if (visited[u->val] == -1){
            
            cc(u,visited);
        }

    }
}

int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    a->neighbors.push_back(b);
    a->neighbors.push_back(d);
    b->neighbors.push_back(a);
    b->neighbors.push_back(c);
    c->neighbors.push_back(b);
    c->neighbors.push_back(d);
    d->neighbors.push_back(a);
    d->neighbors.push_back(c);
    

    Solution* s = new Solution();
    s->cloneGraph(a);
    int t = 0;
    for (vector<Node*> v:s->ans){
        if (v.size() == 0 && t!=0){
            break;
        }
        for (Node* n: v){
            cout<<n->val<<" ";
        }
        t++;
        cout<< endl;
    }
}