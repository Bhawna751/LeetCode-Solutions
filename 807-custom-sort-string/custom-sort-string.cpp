class Solution {
public:
    string customSortString(string order, string s) {
        std::unordered_map<char,int> mpp;
        for(char it:order){
            mpp[it]=0;
        }
        for(char iter:s){
            if(mpp.find(iter)!=mpp.end()){
                mpp[iter]++;
            }
        }
        std::string sortedS;
        for(char c: order){
            sortedS.append(mpp[c],c);
        }
        for(char it:s){
            if(mpp.find(it) == mpp.end()){
                sortedS.push_back(it);
            }
        }
        return sortedS;
    }
};