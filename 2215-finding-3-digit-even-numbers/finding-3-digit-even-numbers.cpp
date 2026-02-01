class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int>ans;
        vector<int> freq(10,0);
        for(int it:digits){
            freq[it]++;
        }
        for(int i=100;i<1000;i+=2){
            int d1 = i/100;
            int d2 = (i/10)%10;
            int d3 = i%10;
           vector<int>store(10,0);
           store[d1]++;
           store[d2]++;
           store[d3]++;
           bool flag=true;
           for(int j=0;j<10;j++){
            if(store[j] > freq[j]){
                flag=false;
                break;
            }

           }
           if(flag) ans.push_back(i);
        }
        return ans;
    }
};