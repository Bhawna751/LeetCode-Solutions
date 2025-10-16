class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        vector<int> freq(value,0);
        int end=0;
        for(int it:nums){
            freq[(it % value + value) % value]++;
        }
        for(int i=0;i<value;i++){
            if(freq[i] < freq[end]) end=i;
        }
        return value  * freq[end] + end;
    }
};