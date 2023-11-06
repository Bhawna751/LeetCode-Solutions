class Solution {
public:
        int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int n = cardPoints.size();
        vector<int> cummulativeSumFromFront(n+1, 0);
        vector<int> cummulativeSumFromBehind(n+1, 0);
        for (int i=0; i<n; i++) {
            sum += cardPoints[i];
            cummulativeSumFromFront[i+1] = sum;
        }
        sum = 0;
        for (int i=n-1; i>=0; i--) {
            sum += cardPoints[i];
            cummulativeSumFromBehind[i] = sum;
        }
        reverse(cummulativeSumFromBehind.begin(), cummulativeSumFromBehind.end());
        int answer = 0;
        for(int i=0; i<=k; i++) {      
            answer = max(answer,cummulativeSumFromFront[i] + cummulativeSumFromBehind[k-i]); 
        }
        return answer;
    }
};