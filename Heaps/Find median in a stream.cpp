class Solution {
  public:
    int sigmoid(int a ,int b){
        if(a == b){
            return 0;
        }
        else if(a>b){
            return 1;
        }
        else{
            return -1;
        }
    }
    void findMedian(int element,priority_queue<int> &LMaxHeap,
    priority_queue<int,vector<int>, greater<int>> &RMinHeap,
    double &median,vector<double>& ans){
        switch(sigmoid(LMaxHeap.size(),RMinHeap.size())){
            case 0:// same size heap
            if(element>median){
                RMinHeap.push(element);// Rmin heap becomes more size than left heap
                median = RMinHeap.top();
                ans.push_back(median);
            }
            else{
                LMaxHeap.push(element);
                median = LMaxHeap.top();
                ans.push_back(median);
            }
            break;
            case 1://maxHeap>minHeap
            if(element>median){
                RMinHeap.push(element);// Rmin heap becomes more size than left heap
                median = (RMinHeap.top() + LMaxHeap.top())/2.0;
                ans.push_back(median);
            }
            else{
                int n = LMaxHeap.top();
                LMaxHeap.pop();
                RMinHeap.push(n);
                LMaxHeap.push(element);
                median = (LMaxHeap.top() + RMinHeap.top())/2.0;
                ans.push_back(median);
                
            }
            break;
            case -1://maxHeap<minHeap
             if(element>median){
                int n = RMinHeap.top();
                RMinHeap.pop();
                LMaxHeap.push(n);
                RMinHeap.push(element);// Rmin heap becomes more size than left heap
                median = (RMinHeap.top()+LMaxHeap.top())/2.0;
                ans.push_back(median);
            }
            else{
                LMaxHeap.push(element);
                median = (RMinHeap.top() + LMaxHeap.top())/2.0;
                ans.push_back(median);
            }
            break;
        }
    }
    vector<double> getMedian(vector<int> &arr) {
        // code here
       priority_queue<int> leftMaxHeap;
       priority_queue<int,vector<int>,greater<int>> rightMinHeap;
       vector<double> ans;
       double median = arr[0];
       for(int i = 0;i<arr.size();i++){
           findMedian(arr[i],leftMaxHeap,rightMinHeap,median,ans);
       }
       return ans;
    }
};
