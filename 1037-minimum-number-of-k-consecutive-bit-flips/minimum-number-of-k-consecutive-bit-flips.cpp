class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        queue<int> q;
        int flip=0;
        for(int i =0;i<n;i++){
            while(!q.empty() && i > q.front() + k - 1){
                q.pop();
            }
            if((nums[i] + q.size())%2 == 0){
                if(i+k>n)return -1;
                flip++;
                q.push(i);
            }
        }
        return flip;
    }
};