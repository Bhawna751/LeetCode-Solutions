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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /* BRUTE-FORCE:
        while(headB!=nullptr){
            ListNode *temp = headA;
            while(temp!=nullptr){
                if(temp==headB){
                    return headB;
                }
                temp=temp->next;
            }
            headB=headB->next;
        }
        return nullptr;*/
        //HASHING
        unordered_set<ListNode*> st;
        while(headA!=nullptr){
            st.insert(headA);
            headA=headA->next;
        }
        while(headB!=nullptr){
            if(st.find(headB) != st.end())return headB;
            headB=headB->next;
        }
        return nullptr;
    }
};