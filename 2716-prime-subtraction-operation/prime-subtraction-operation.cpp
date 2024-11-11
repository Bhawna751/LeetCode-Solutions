class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();//n = 3 5,1,3

        vector<bool> primes(1001,true);//t t t t f t f t f 
        for(int i=2;i<=1000;i++){
            for(int j=2; ;j++){
                if(i*j > 1000)break;
                primes[i*j] = false;
            }
        }

        for(int i=n-2;i>=0;i--){
            if(nums[i] >= nums[i+1]){
                bool prime = false;
                int j=2;
                while(j<nums[i]){
                    if(primes[j] && nums[i]-j < nums[i+1]){
                        prime = true;
                        nums[i] = nums[i] - j;
                        break;
                    }
                    else j++;
                }
                if(!prime)return false;
            }
        }
       
        return true;
    }
};