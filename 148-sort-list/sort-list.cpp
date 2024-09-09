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
    ListNode *findMid(ListNode *head){
        if(head == NULL || head->next == NULL) return head;
        ListNode *slow = head, *fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *mergeLL(ListNode *left, ListNode *right){
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        while(left != NULL && right != NULL){
            if(left->val <= right->val){
                temp->next = left;
                left = left->next;
            }
            else{
                temp->next = right;
                right= right->next;
            }
            temp=temp->next;
        }
        if(left!=NULL)temp->next = left;
        else temp->next = right;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *mid = findMid(head);
        ListNode *right = mid->next;
        mid->next = NULL;
        ListNode *left = head;
        left = sortList(left);
        right = sortList(right);
        return mergeLL(left,right);
    }
};