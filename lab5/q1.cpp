#include <bits/stdc++.h>
using namespace std;
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
class TreeNode;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        vector <int> a = preorder;
        vector <int> b = inorder;
        int p = a[0];
        int c = 0;
        for (int i = 0;i<b.size();i++){
            if (b[i] == p) c = i; 
        }
        vector <int> a2;
        vector <int> b2;
        for (int i = 0;i<c;i++){
            b2.push_back(b[i]);
        }
        
    }
};