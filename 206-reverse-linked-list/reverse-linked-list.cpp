/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
     stack<int>st;
     ListNode *q=head;
     
     while(q!=nullptr){
        st.push(q->val);
        q=q->next;
     }   
     q=head;
     while(q!=nullptr){
        q->val = st.top();
        st.pop();
        q=q->next;
     }
     return head;
    }
};