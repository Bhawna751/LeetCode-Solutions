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
    int gcd(int a,int b){
        if(b==0) return a;
        else return gcd(b, a % b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL) return head;
        ListNode *p = head, *q = head->next;
        while(q != NULL){
            int gcdval = gcd(p->val, q->val);
            ListNode *gcdNode = new ListNode(gcdval);
            p->next = gcdNode;
            gcdNode -> next = q;
            p= q;
            q=q->next;
        }
        return head;
    }
};