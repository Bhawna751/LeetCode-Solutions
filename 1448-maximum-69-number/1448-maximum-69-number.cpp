class Solution {
public:
    int maximum69Number (int num) {
        string copy = to_string(num);
        for(int i=0;i<copy.size();i++){
            if(copy[i] =='6'){
                copy[i] = '9';
                break;
            }
        }
        return stoi(copy);
    }
};