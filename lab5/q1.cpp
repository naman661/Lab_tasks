/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


// REMOVE BELOW 2 LINES BEFORE SUBMITTING
#include <bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
        TreeNode(int a);
        TreeNode(int a, TreeNode* p1,TreeNode* p2);
};
// TILL HERE


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int a = preorder[0];
    	
        preorder.erase(preorder.begin());
        vector <int> l;
        vector <int> r;
        bool b = true;
        for (int i = 0;i<inorder.size();i++){
        	if (inorder[i]==a) b = false;
        	else if (b) l.push_back(inorder[i]);
        	else r.push_back(inorder[i]);
        }
        vector <int> l1;
        vector <int> r1;
        for (int i = 0;i<l.size();i++){
        	l1.push_back(preorder[i]);
        }
        for (int i = l.size();i<preorder.size();i++){
        	r1.push_back(preorder[i]);
        }
        
        
        if (l1.size()==0 || r1.size()==0){
        	if (l1.size()==0 & r1.size() == 0){
        		TreeNode* T = new TreeNode(a);
        		return T;
        	}
        	else if (l1.size()==0 & r1.size() != 0){
        		TreeNode* T = new TreeNode(a,nullptr,buildTree(r1,r));
        		return T;
        	}
        	else{
        		TreeNode* T = new TreeNode(a,buildTree(l1,l),nullptr);
        		return T;
        	}
        	
        }
        else{
        	TreeNode* T = new TreeNode(a,buildTree(l1,l),buildTree(r1,r));
        	return T;
        }
        	
        }
        
    
};