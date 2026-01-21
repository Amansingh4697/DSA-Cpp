//leetCode
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
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       stack<int> st;
       unordered_map<int,int> mp;
       for(int i = nums2.size()-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums2[i]){
            st.pop();
        }
        mp[nums2[i]] = st.empty() ?  -1 : st.top();
        st.push(nums2[i]);
       }
       vector<int> ans;
       for(int x : nums1){
         ans.push_back(mp[x]);
       }
       return ans;
    }
};

// gfg or striver
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        stack<int> st;
        vector<int> ans;
        for(int i = arr.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(!st.empty()) ans.push_back(st.top());
            else ans.push_back(-1);
            st.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

