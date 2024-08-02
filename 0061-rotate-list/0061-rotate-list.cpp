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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k==0) return head;
        ListNode *temp = head;
        int n=1;
        while(temp->next != nullptr){
            n++;
            temp=temp->next;
        }
        temp->next = head;
        k = k%n;
        int end = n-k;
        while(end--) temp=temp->next;
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
};