class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
         long firstMax = LONG_MIN;
        long secondMax = LONG_MIN;
        long thirdMax = LONG_MIN;
        for(auto it : nums){
            if(it>firstMax){
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = it;  
            }
            if(it>secondMax && it != firstMax){
                thirdMax = secondMax;
                secondMax = it;
            }
            if(it>thirdMax && it != secondMax && it != firstMax){
                thirdMax= it;
            }
        }
        if(thirdMax == LONG_MIN){
            return firstMax;
        }
        return thirdMax;
    }
};
