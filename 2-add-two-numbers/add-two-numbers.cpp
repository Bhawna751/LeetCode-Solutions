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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p=l1,* q=l2;
        ListNode* ans = new ListNode();
        ListNode* temp=ans;
        int carry=0;
        while(p!=nullptr || q!=nullptr || carry){
            int sum=0;
            if(p!=nullptr){
                sum += p->val;
                p=p->next;
            }
            if(q!=nullptr){
                sum += q->val;
                q=q->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode *node = new ListNode(sum%10);
            temp->next = node;
            temp=temp->next;
        }

        return ans->next;
    }
};