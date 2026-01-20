class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
       for(int i=0;i<nums1.size();i++){
        bool flag = false;
        int index = -1;
        for(int j=0;j<nums2.size();j++){
            if(nums2[j] == nums1[i]){
                flag = true;
            }
            if(flag){
                if(nums2[j]>nums1[i]){
                     index = j;
                    break;
                }
            }
        }
        if(index == -1){
            ans.push_back(-1);
        }
        else{
            ans.push_back(nums2[index]);
        }
       } 
       return ans;
    }
};
