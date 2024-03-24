class Solution {
public:
    int minOperations(int k) {//k=17
        int value = sqrt(k);//val=4
        int ans = value - 1;//ans=3
        int sum = value;//sum = 4
        while(sum < k){
            sum += value;//sum = 8->12->16->20
            ans++;//ans=4->5->6->7
        }
        return ans;
    }
};