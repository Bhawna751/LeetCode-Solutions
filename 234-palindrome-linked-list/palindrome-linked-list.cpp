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
    ListNode *reverse(ListNode *head){
        ListNode*prev=nullptr,*next=nullptr;
        while(head!=nullptr){
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return true;
        ListNode *fast=head,*slow=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast = fast->next->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        while(slow!=nullptr){
            if(head->val!=slow->val)return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};