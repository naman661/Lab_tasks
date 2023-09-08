

//REMOVE THE BELOW BLOCK BEFORE SUBMITTING

//The tree node has data, left child and right child 
#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node* left;
        Node* right;
};
// TILL HERE DELETE


  
    Node *lca(Node *root, int v1,int v2) {
        vector <int> l1;
        vector <int> l2;
        Node *a = root;
        while (true){
            if (a->data == v1) {
                l1.push_back(v1);
                break;
            }
            else if (a->data < v1){
                l1.push_back(a->data);
                a = a->right;
            }
            else {
                l1.push_back(a->data);
                a = a->left;
            }
        }
        Node *b = root;
        while (true){
            if (b->data == v2) {
                l2.push_back(v2);
                break;
            }
            else if (b->data < v2){
                l2.push_back(b->data);
                b = b->right;
            }
            else {
                l2.push_back(b->data);
                b = b->left;
            }
        }
        reverse(l1.begin(),l1.end());
        reverse(l2.begin(),l2.end());
        int c;
        bool q = false;
        for (int i = 0;i<l1.size();i++){
            int d = l1[i];
            for (int j = 0;j<l2.size();j++){
                if (l2[j] == d){
                    c = d;
                    q = true;
                    break;
                }
            }
        if (q) break;
        }
        Node* r = root;
        while (true) {
            if (r->data == c){
                return r;
                break;
            }
            else if (r->data < c){
                r = r->right;
            }
            else{
                r = r->left;
            }
        }

        
        
        
        
    }