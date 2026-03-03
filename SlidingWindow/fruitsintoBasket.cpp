class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right  = 0;
        map<int,int> mpp;
        int maxFruits = 0;
        while(right<fruits.size()){
             mpp[fruits[right]]++;
            while(mpp.size() > 2){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]] == 0){
                    mpp.erase(fruits[left]);
                }
                left++;
            }
            int cntFruits = right-left+1;
            maxFruits = max(maxFruits,cntFruits);
            right++;
        }
        return maxFruits;
    }
};
