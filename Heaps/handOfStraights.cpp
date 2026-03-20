class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
     map<int,int> mpp;
     vector<int> temp;
     for(int i = 0;i<hand.size();i++){
        mpp[hand[i]]++;
     }
     while(!mpp.empty()){
        int curr = mpp.begin()->first;
        for(int i = 0;i<groupSize;i++){
            if(mpp.find(curr + i) == mpp.end()){
                return false;
            }
            mpp[curr + i]--;
            if(mpp[curr + i] == 0){
                mpp.erase(curr + i);
            }
        }
     }
     return true;
    }
};
