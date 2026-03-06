class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxScore = 0;
        int lsum = 0;
        int rsum = 0;
        int rindex = n-1;
        for(int i = 0;i<=k-1;i++){
            lsum = lsum + cardPoints[i];
        }
        maxScore = lsum;
        for(int i = k-1;i>=0;i--){
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[rindex];
            rindex--;
            maxScore = max(maxScore,lsum+rsum);
        }
        return maxScore;
    }
};
