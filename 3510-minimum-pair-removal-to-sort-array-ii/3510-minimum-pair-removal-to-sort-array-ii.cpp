using p = pair<long long, pair<int, pair<class Node*, class Node*>>>;
class Node{
public:
long long val;
int idx;
Node*next;
Node*prev;
 Node(long long val,int idx){
  this->val=val;
  this->idx=idx;
  next=prev=nullptr;
 }
};
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {

        priority_queue<p,vector<p>,greater<p>>pq;
        unordered_set<Node*> mp;

        int ans=0,n=nums.size(),bad_pairs=0;

        Node*dummy=new Node(-1,-1);
        Node*temp=dummy;

        for(int i=0;i<n;i++){
            Node* naya=new Node(nums[i],i);
            mp.insert(naya);
            temp->next=naya;
            naya->prev=temp;
            if(i!=0){
                if(nums[i-1]>nums[i]) bad_pairs++;
                pq.push({1LL*temp->val+naya->val,{i-1,{temp,naya}}});
            } 
            temp=temp->next;
        }

        while(bad_pairs){
            p x=pq.top();
            pq.pop();
            long long sum=x.first;
            int index=x.second.first;
            Node* l=x.second.second.first;
            Node* r=x.second.second.second;

            if(mp.find(l)==mp.end() || mp.find(r)==mp.end()) continue;
            
            ans++;
           
            if(l->val>r->val) bad_pairs--;

            if(l->prev != dummy){
           if(l->prev->val > l->val && l->prev->val <= sum) bad_pairs--;
          if(l->prev->val <= l->val && l->prev->val > sum) bad_pairs++;
            }

          if(r->next != nullptr){
          if(r->val > r->next->val && sum <= r->next->val) bad_pairs--;
           if(r->val <= r->next->val && sum > r->next->val) bad_pairs++;
              }

            mp.erase(l);
            mp.erase(r);

            Node* naya=new Node(sum,index);
             mp.insert(naya);

            l->prev->next=naya;
            naya->prev=l->prev;
            naya->next=r->next;
            if(r->next != nullptr) r->next->prev = naya;

            if(naya->prev!=dummy)
             pq.push({naya->prev->val+naya->val,{index-1,{naya->prev,naya}}}); 

            if(naya->next!=nullptr)
              pq.push({naya->next->val+naya->val,{index,{naya,naya->next}}});  

        }

        return ans;
    }
};