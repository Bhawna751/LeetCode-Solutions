class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int stcnt=students.size(),cir=0,sq=0;
        for(int i=0;i<students.size();i++){
            if(students[i]==0) cir++;
            else sq++;
        }
        for(int i=0;i<sandwiches.size();i++){
            if(sandwiches[i]==0){
                if(cir>0){
                    stcnt--;
                    cir--;
                }
                else return stcnt;
            }
            else{
                if(sq>0){
                    stcnt--;
                    sq--;
                }
                else return stcnt;
            }
        }
        return stcnt;
    }
};