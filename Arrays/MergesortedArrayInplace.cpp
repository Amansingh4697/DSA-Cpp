class Solution {
    // nums1 and nums2
    void swapifGreaterDiffArray(vector<int>& nums1,vector<int>& nums2,int left,int right){
     if(nums1[left]>nums2[right]){
        swap(nums1[left],nums2[right]);
     }
    }
    // nums1 and nums1
    void swapifGreaterSameNums1(vector<int>& nums1,int left,int right){
     if(nums1[left]>nums1[right]){
        swap(nums1[left],nums1[right]);
     }
    }
    // nums2 and nums2
    void swapifGreaterSameNums2(vector<int>& nums2,int left,int right){
     if(nums2[left]>nums2[right]){
        swap(nums2[left],nums2[right]);
     }
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         if(n==0) return;
//     int len = n+m;
//    int gap = (len)/2 + (len)%2;
//    while(gap>0){
//     int left = 0;
//    int right = left + gap;
//    while(right<len){
//     // nums1 and nums2
//     if(left<m && right>=m){
//        swapifGreaterDiffArray(nums1,nums2,left,right-m);
//     }
//     // nums2 and nums2
//     else if(left>=m){
//          swapifGreaterSameNums2(nums2,left-m,right-m);
//     }
//     // nums1 and nums1
//     else{
//       swapifGreaterSameNums1(nums1,left,right);
//     }
//     left++;
//     right++;
//    }
// if(gap == 1) break;
// gap = (gap/2) + (gap%2);
//    }
//    int j = 0;
//    for(int i = m;i<len;i++){
//      nums1[i] = nums2[j];
//      j++;
//    }
if(m == 0 || n == 0){
    for(int i = 0;i<n;i++){
        nums1[i] = nums2[i];
    }
    return;
}
int i = m-1;
int j = n-1;
int k= n+m-1;
while(j>=0 && i>=0){
    if(nums1[i]>=nums2[j]){
        nums1[k] = nums1[i];
        i--;
    }
    else{
        nums1[k] = nums2[j];
        j--;
    }
    k--;
}
while(i>=0 && k>=0){
    nums1[k] = nums1[i];
    i--;
    k--;
}
while(j>=0 && k>=0){
    nums1[k] = nums2[j];
    j--;
    k--;
}
}
};
