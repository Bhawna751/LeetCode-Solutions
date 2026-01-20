class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int>answer(n);

        for(int i = 0; i< n; i++){

            if(nums[i] % 2 ==0){

                answer[i] = -1;
            }else{

                int x = nums[i];

                int remove = 0;

                while(x % 2 !=0){

                      remove <<= 1;

                      remove |= 1;

                      x /= 2;
                }

                answer[i] = (nums[i]- remove) + (remove >> 1);
            }
        }

        return answer;
    }
};