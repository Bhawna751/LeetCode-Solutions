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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* cur = head->next;
        ListNode* newHead=cur;
        while (newHead) {
            int sum = 0;
            while (newHead->val != 0) {
                sum += newHead->val;
                newHead = newHead->next;
            }
            cur->val = sum;
            newHead = newHead->next;
            cur->next = newHead;
            cur = cur->next;
        }
        return head->next;
    }
};