class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        int mini = INT_MAX;
        ListNode* prev = head;
        ListNode* cur = head->next;
        int ind = 1;
        int prevInd = 0;
        int first = 0;

        while (cur->next != nullptr) {            
            if ((cur->val < prev->val && cur->val < cur->next->val) ||
                (cur->val > prev->val && cur->val > cur->next->val)) {
                if (prevInd == 0) {
                    prevInd = ind;
                    first = ind;
                } else {
                    mini = min(mini, ind - prevInd);
                    prevInd = ind;
                }
            }
            ind++;
            prev = cur;
            cur = cur->next;
        }
        if (mini != INT_MAX) {
            int maxDistance = prevInd - first;
            ans = {mini, maxDistance};
        }
        return ans;
    }
};