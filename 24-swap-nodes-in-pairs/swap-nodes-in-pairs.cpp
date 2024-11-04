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
    ListNode* swapPairs(ListNode* head) {//[1,2,3,4] temp = null
        ListNode *temp = head;//2->1->4->3
        ListNode q(0,head);//q = 0->1
        ListNode* prev = &q;//prev = 3
        while(temp && temp->next){
            ListNode *next = temp->next->next;//next  = null
            ListNode *sec = temp->next;// sec = 4
            sec->next = temp;// 
            temp->next = next;
            prev->next = sec;
            prev = temp;
            temp = next;
        }
        return q.next;
    }
};