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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return nullptr;
        while(lists.size()>1){
            lists.push_back(merge(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    ListNode* merge(ListNode *node1,ListNode *node2){
        if(node1 == nullptr)return node2;
        if(node2 == nullptr)return node1;
        if(node1->val <= node2->val){
            node1->next = merge(node1->next,node2);
            return node1;
        }
        else{
            node2->next = merge(node1,node2->next);
            return node2;
        }
    }
};