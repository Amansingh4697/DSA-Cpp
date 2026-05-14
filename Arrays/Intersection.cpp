class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // int n1 = nums1.size();
        // int n2 = nums2.size();
        // vector<int> res;
        // for(int i = 0;i<n1;i++){
        //     for(int j = 0;j<n2;j++){
        //         if(nums1[i] == nums2[j]){
        //             res.push_back(nums1[i]);
        //             nums2.erase(nums2.begin()+j);
        //             n2 = nums2.size();
        //             break;
        //         }
        //     }
        // }
        // return res;
        // map<int,int> freq;
        // vector<int> res;
        // for(int i  = 0;i<nums1.size();i++){
        //     freq[nums1[i]]++;
        // }
        // for(auto it:nums2){
        //     if(freq[it]>0){
        //         res.push_back(it);
        //         freq[it]--;
        //     }
        // }
        // return res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> res;
        int i = 0;
        int j = 0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] ==  nums2[j]){
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return res;
    }
};
