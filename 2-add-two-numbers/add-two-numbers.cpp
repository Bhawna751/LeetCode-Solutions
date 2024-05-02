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
        ListNode *temp = new ListNode(),*q=temp;
        int c=0;
        while(l1!=nullptr || l2!=nullptr || c==1){
            int sum=0;
            if(l1!=nullptr){
                sum += l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr){
                sum += l2->val;
                l2=l2->next;
            }
            sum += c;
            c = sum/10;
            ListNode *newNode = new ListNode(sum%10);
            q->next = newNode;
            q=q->next;
        }
        return temp->next;
    }
};