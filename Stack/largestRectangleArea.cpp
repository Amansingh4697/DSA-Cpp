// TLE exceeded solution
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = INT_MIN;
        for(int i = 0;i<n;i++){
          int area  = 0;
          int width = 0;
          for(int j = i;j>=0;j--){
            if(heights[j]>=heights[i]){
                width = width + 1;
            }
            else{
                break;
            }
          }
          for(int k = i+1;k<n;k++){
            if(heights[k]>=heights[i]){
                width = width + 1;
            }
            else{
                break;
            }
          }
          area = heights[i] * width;
          if(maxArea<area){
            maxArea = area;
          }
        }
        return maxArea;
    }
};

// Brute force solution
class Solution {
public:
   vector<int> PSE(vector<int>& nums){
    int n = nums.size();
    vector<int> pse(n);
    stack<int> st;
    for(int i = 0;i<n;i++){
        while(!st.empty() && nums[st.top()]>=nums[i]){
            st.pop();
        }
        pse[i] = st.empty()?-1:st.top();
        st.push(i);
    }
    return pse;
   }
   vector<int> NSE(vector<int>& nums){
    int n = nums.size();
    vector<int> nse(n);
    stack<int> st;
    for(int i = n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i]){
            st.pop();
        }
        nse[i] = st.empty()?n:st.top();
        st.push(i);
    }
    return nse;
   }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        vector<int> nse = NSE(heights);
        vector<int> pse = PSE(heights);
        for(int i = 0;i<n;i++){
            int width = nse[i] - pse[i] -1;
            int area = heights[i]*width;
            maxArea = max(area,maxArea);
        }
        return maxArea;
    }
};
// optimal approach bit tricky but helpfull
class Solution {
public:
   
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                  int element = heights[st.top()];
                  int nseIdx = i;
                  st.pop();
                  int pseIdx = (st.empty()) ? -1 : st.top();
                  int area = element*(nseIdx - pseIdx -1);
                  maxArea = max(maxArea,area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nseIdx = n;
            int element = heights[st.top()];
            st.pop();
            int pseIdx = (st.empty()) ? -1 : st.top();
            int area = element*(nseIdx - pseIdx -1);
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};
