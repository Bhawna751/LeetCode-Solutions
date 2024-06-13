class Solution {
public:
    int findmax(vector<int> arr){
        int maxi=0;
        for(int it:arr){
            if(maxi<it) maxi=it;
        }
        return maxi;
    }
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int maxi=max(findmax(seats),findmax(students));
        vector<int> diff(maxi,0);
        for(int it:seats){
            diff[it-1]++;
        }
        for(int it:students){
            diff[it-1]--;
        }
        int moves = 0;
        int unmatched = 0;
        for(int it:diff){
            moves += abs(unmatched);
            unmatched += it;
        }
        return moves;
    }
};