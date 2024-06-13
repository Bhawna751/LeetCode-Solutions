class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n=students.size();
        sort(students.begin(),students.end());
        sort(seats.begin(),seats.end());
        int moves=0;
        for(int i=0;i<n;i++){
            moves += abs(seats[i]-students[i]);
        }
        return moves;
    }
};