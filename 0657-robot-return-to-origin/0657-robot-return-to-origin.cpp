class Solution {
public:
    bool judgeCircle(string moves) {
        int fU=0,fD=0,fR=0,fL=0;
        for(int i=0;i<moves.length();i++){
           if(moves[i]=='U') fU++;
           else if(moves[i]=='D') fD++;
           else if(moves[i]=='R') fR++;
           else fL++;
             
        }
        if(fU==fD && fR==fL){
            return true;
        }
        return false;
    }
};