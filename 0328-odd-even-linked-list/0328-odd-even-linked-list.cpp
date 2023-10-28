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
    ListNode* oddEvenList(ListNode* head) {
        ListNode l1(0), l2(0);
        ListNode* p1 = &l1;
        ListNode* p2 = &l2;

        unsigned index = 1;
        while (head) {
            if (index++ % 2 == 1)
                p1 = p1->next = head;
            else
                p2 = p2->next = head;
            head = head->next;
        }

        p1->next = l2.next;
        p2->next = nullptr;
        return l1.next;
    }
};