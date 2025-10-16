class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        vector<int> freq(value,0);//  1 2 0 1 0 0 2
        int end=0;
        for(int it:nums){
            freq[(it % value + value) % value]++;
        }
        for(int i=1;i<value;i++){//i=2
            if(freq[i] < freq[end]) end=i;//end=2
        }
        return value  * freq[end] + end;
    }
};