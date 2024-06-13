class Solution {
public:
    int findmax(vector<int> arr){
        int maxi=0;
        for(int it:arr){
            if(maxi<it) maxi=it;
        }
        return maxi;
    }
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {//3 1 5      2 7 4
        int maxi=max(findmax(seats),findmax(students));//maxi = max(5,7) = 7
        vector<int> diff(maxi,0);//0 0 1 0 0 0 0
        for(int it:seats){
            diff[it-1]++;//
        }
        for(int it:students){
            diff[it-1]--;
        }
        int moves = 0;
        int empty = 0;
        for(int it:diff){
            moves += abs(empty);
            empty += it;
        }
        return moves;
    }
};