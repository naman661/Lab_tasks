#include <bits/stdc++.h>
using namespace std;


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; 

void reverse(ListNode* n){
    if (n->next != NULL){
        reverse(n->next);
        n->next->next = n;
    }
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* f = head;
        ListNode* l = head;
        ListNode* m = head;
        int size = 0;
        while (f != NULL){
            size++;
            l = l->next;
        }

        for (int i=0;i<(size/2);i++){
            m = m->next;
        }
        reverse(m);

        bool valid = true;
        for (int i=0;i<size/2;i++){
            if (f->val!=l->val){
                valid = false;
                break;
            }
        }
        return valid;
    }
};
