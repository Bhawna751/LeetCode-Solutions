class Solution {
public:
    double epsilon= 0.1;
    bool solve(vector<double>&nums ){
        int n=nums.size();
        if(n==1) return abs(nums[0]-24) <= epsilon;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                vector<double>temp;
                for(int k=0;k<n;k++){
                    if(k!=i && k!=j) temp.push_back(nums[k]);
                }
                double a = nums[i];
                double b  = nums[j];
                vector<double>possible = {a-b,b-a,a*b,a+b};
                if(abs(b)>0.0) possible.push_back(a/b);
                if(abs(a)>0.0) possible.push_back(b/a);
                for(auto it: possible){
                    temp.push_back(it);
                    if(solve(temp)) return true;
                    temp.pop_back();
                }

            }

        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for(int i=0;i<4;i++){
            nums.push_back((double)cards[i]);
        }
        return solve(nums);
    }
};