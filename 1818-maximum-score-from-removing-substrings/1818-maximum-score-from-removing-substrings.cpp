class Solution {
public:
    string remove(string &substr,string &pair){//c d b c a b    "ab"
        stack<char> st;// 
        for(char it : substr){
            if(it == pair[1] && !st.empty() && st.top() == pair[0]){
                st.pop();
            }else{
                st.push(it);
            }
        }
        string remaining;
        while(!st.empty()){
            remaining += st.top();//c b d c
            st.pop();
        }
        reverse(remaining.begin(),remaining.end());//c d b c 
        return remaining;
    }
    int maximumGain(string s, int x, int y) {
        int total=0;
        string moreScoring = x > y ? "ab" : "ba";// ba
        string lessScoring = moreScoring == "ab" ? "ba" : "ab";//ab
        string removingMore = remove(s,moreScoring);//c d b c a b
        int removed = (s.length() - removingMore.length()) / 2;// 6/2 = 3
        total += removed * max(x,y);//total = 15
        string removingLess  = remove(removingMore,lessScoring);// c d b c
        removed = (removingMore.length() - removingLess.length()) / 2;// 1
        total += removed * min(x,y);//15+4=19
        return total;
    }
};