class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long ans=-1e15,temp_sum=0;
        int n=nums.size();
        bool p1,p2,p3;
        p1=p2=p3=false;
        long long inc_total=0;
        long long inc_positive=0;
        
        int e1=-1,e2=-1;

        for(int i=0;i<=n;i++){
            if(i==n){
                  if(p3){
                    ans=max(ans,temp_sum+inc_total);
                    if(e2!=-1) ans=max(ans,temp_sum+inc_total+nums[e2]);
                  }
            }
            else if(i==0 || nums[i]==nums[i-1] || (nums[i-1]>nums[i] && !p1 && !p2)){
                if(p3)ans=max(ans,temp_sum+inc_total);
                if(e2!=-1) ans=max(ans,temp_sum+inc_total+nums[e2]);
                temp_sum=inc_total=inc_positive=0;
                inc_total=nums[i];
                if(nums[i]>0) inc_positive=nums[i];
                p1=p2=p3=false;
                // cout<<"1"<<endl;
                // cout<<inc_positive<<" "<<inc_total<<endl;
            }
            else if(!p2 && !p3  && nums[i]>nums[i-1]){
                p1=true;
                inc_total+=nums[i];
                if(nums[i]>0) inc_positive+=nums[i];
                // cout<<"2"<<endl;
                // cout<<inc_positive<<" "<<inc_total<<endl;
            }
            else if(p2 && nums[i]>nums[i-1]){
                p2=false;
                p1=p3=true;
                // if(nums[i-1]>0){
                    e2=e1;
                    e1=i-1;
                // }
                inc_total=nums[i];
                if(nums[i]>0) inc_positive=nums[i];
                ans=max(ans,temp_sum+inc_total);
                if(e2!=-1) ans=max(ans,temp_sum+inc_total+nums[e2]);
                // cout<<"3"<<endl;
                // cout<<inc_positive<<" "<<inc_total<<endl;
            }
            else if(p3 && nums[i]>nums[i-1]){
                inc_total+=nums[i];
                if(nums[i]>0) inc_positive+=nums[i];
                ans=max(ans,temp_sum+inc_total);
                if(e2!=-1) ans=max(ans,temp_sum+inc_total+nums[e2]);
                // cout<<"4"<<endl;
                //  cout<<inc_positive<<" "<<inc_total<<endl;
            }
            else if(p1 && nums[i]<nums[i-1]){
                if(p3){
                    p1=p3=false;
                    p2=true;
                    ans=max(ans,temp_sum+inc_total);
                }
                else {
                    p2=true;
                    p1=false;
                }
                if(nums[i-1]<=0){
                    temp_sum=nums[i-1]+nums[i-2];
                }
                else{
                    temp_sum=inc_positive;
                    if(nums[i-2]<0) temp_sum+=nums[i-2];
                }
                temp_sum+=nums[i];
                inc_total=inc_positive=0;
                // cout<<"5"<<endl;
                // cout<<inc_positive<<" "<<inc_total<<" "<<temp_sum<<endl;
            }
            else if(p2 && nums[i]<nums[i-1]){
                temp_sum+=nums[i];
                // cout<<"6"<<endl;
                // cout<<temp_sum<<endl;
            }
        }
        return ans;
    }
};