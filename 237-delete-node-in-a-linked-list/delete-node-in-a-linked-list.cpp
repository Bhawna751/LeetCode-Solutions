/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
       while(true){
        if(node->next!=nullptr){
            int data = node->next->val;
            node->val=data;
        }
        if(node->next->next==nullptr){
            node->next = nullptr;
            break;
        }
        node = node->next;
       }

    }
};