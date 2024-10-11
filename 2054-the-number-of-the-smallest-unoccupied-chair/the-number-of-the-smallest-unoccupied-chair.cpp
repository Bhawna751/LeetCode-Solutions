class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();//[[4,5],[6,8],[8,10],[1,8]]  target = 2   output = 0
        vector<pair<int,int>> arrivalAndDeparture;// (4,0) (5,-1) (6,1) (8,-2) (8,2) (10,-3) (1,3) (8,-4)
        for(int i=0;i<n;i++){
            arrivalAndDeparture.push_back({times[i][0],i});
            arrivalAndDeparture.push_back({times[i][1],~i});
        }
        sort(arrivalAndDeparture.begin(), arrivalAndDeparture.end());//(1,3)(4,0)(5,-1)(6,1)(8,-4)(8,-2)(8,2)(10,-3)
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> occupied;
        for(int i=0;i<n;i++){
            available.push(i);//1 2 3 
        }
        for(auto& it: arrivalAndDeparture){
            int time = it.first;//time = 8
            int friendInd = it.second;// friendind = 2
            while(!occupied.empty() && occupied.top().first <= time){
                available.push(occupied.top().second);
                occupied.pop();
            }
            if(friendInd >= 0){
                int ch = available.top();// ch = 0
                available.pop();
                if(friendInd == targetFriend) return ch;//0
                occupied.push({times[friendInd][1], ch});//occupied-> (10,0)
            } 
        }
        return -1;
    }
};