class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);
        // prefixMax[0] = height[0];
        // for(int i = 1;i<n;i++){
        //     prefixMax[i] = max(prefixMax[i-1],height[i]);
        // }
        suffixMax[n-1] = height[n-1];
         for(int i = n-2;i>=0;i--){
            suffixMax[i] = max(suffixMax[i+1],height[i]);
        }
        int leftMax = height[0];
        for(int i = 0;i<n;i++){
            leftMax = max(leftMax,height[i]); 
            int rightMax = suffixMax[i];
            if(height[i]<leftMax && height[i]<rightMax);{
                total += min(leftMax,rightMax) - height[i];
            }
        }
        return total;
    }
};
// travel lowest first (optimization)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int leftMax = height[l];
        int rightMax = height[r];
        int total = 0;
        while(l<r){
            if(height[l]<=height[r]){
                if(leftMax>height[l]){
                  total += (leftMax - height[l]);
                }else{
                    leftMax = height[l];
                }
                 l = l+1;
            }
            else{
                if(rightMax>height[r]){
                    total += (rightMax - height[r]);
                }
                else{
                    rightMax = height[r];
                }
                r = r-1;
            }
        }
        return total;

    }
};
