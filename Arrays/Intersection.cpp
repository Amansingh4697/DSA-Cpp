class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // set<int> st1;
        // set<int> st2;
        // vector<int> res;
        // for(int i = 0;i<nums1.size();i++){
        //     st1.insert(nums1[i]);
        // }
        // for(int i = 0;i<nums2.size();i++){
        //     st2.insert(nums2[i]);
        // }
        // for(auto it : st1){
        //     if(st2.find(it) != st2.end()){
        //         res.push_back(it);
        //     }
        // }
        // return res;
        vector<int> res;
        unordered_set<int> st(nums1.begin(),nums1.end());
        unordered_set<int> seen;
        for(auto it : nums2){
            if(st.find(it) != st.end() && seen.find(it) == seen.end()){
                res.push_back(it);
                seen.insert(it);
            }
        }
        return res;
    }
};
