class Solution {
public:
    bool canChange(string start, string target) {
        queue<pair<char,int>> startq,targetq;
        for(int i=0;i<start.size();i++){
            if(start[i]!='_') startq.push({start[i],i});
            if(target[i]!='_')targetq.push({target[i],i});
        }
        if(startq.size() != targetq.size())return false;
        while(!startq.empty()){
            auto [it,ind] = startq.front();
            startq.pop();
            auto [targetit, targetind] = targetq.front();
            targetq.pop();
            if(it != targetit || (it == 'L' && ind<targetind) || (it == 'R' && ind > targetind)) return false;
        }
        return true;
    }
};