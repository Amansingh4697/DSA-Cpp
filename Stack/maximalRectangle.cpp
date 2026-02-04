class Solution {
public:
int LRA(vector<int>& heights) {
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        vector<vector<int>> preSum(n, vector<int>(m, 0)); 
        for(int i = 0;i<m;i++){
            int sum = 0;
            for(int j = 0;j<n;j++){
                sum = sum + (matrix[j][i]-'0');
              if((matrix[j][i] - '0') == 0){
                sum = 0;
              }
              preSum[j][i] = sum;
            }
        }
       int maxArea = 0;
       for(int i = 0;i<n;i++){
           maxArea = max(maxArea,LRA(preSum[i]));
       }
       return maxArea;
    }
};
