#include <bits/stdc++.h>
using namespace std;

//Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

//The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	};
vector <int> values1;
void inorder (Node* root){
    if (root != nullptr){
        inorder(root->left);
        values1.push_back(root->data);
        inorder(root->right);
    }
}

bool checkBST(Node* root) {
    bool valid = false;
    int s = values1.size();
    for (int i=0; i<s-1;i++){
        if (!(values1[i]<values1[i+1])){
            valid = false;
            return false;
            break;
        }
    }
    valid = true;
	return valid;
}