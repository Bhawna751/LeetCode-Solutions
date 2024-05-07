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
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp=head;
        stack<ListNode*> st;
        while(temp!=nullptr){
            st.push(temp);
            temp=temp->next;
        }
        int carry=0;
        while(!st.empty()){
            ListNode *q= st.top();
            st.pop();
            int k = (q->val*2)+carry;
            q->val = k%10;
            carry = k/10;
        }
        if(carry>0){
            ListNode *newHead = new ListNode(carry,head);
            head=newHead;
        }
        return head;
    }
};