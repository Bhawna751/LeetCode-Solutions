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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int> (n,-1));
        int left = 0, right = n-1, top = 0, bottom = m-1;
        while(head != nullptr){
            for(int col = left;col<=right && head;col++){
                matrix[top][col] = head->val;
                head=head->next;
            }
            top++;
            for(int row = top;row<=bottom && head;row++){
                matrix[row][right] = head->val;
                head = head->next;
            }
            right--;
            for(int col = right;col >= left && head; col--){
                matrix[bottom][col] = head->val;
                head=head->next;
            }
            bottom--;
            for(int row= bottom;row>= top && head; row--){
                matrix[row][left] = head->val;
                head=head->next;
            }
            left++;
        }
        return matrix;
    }
};