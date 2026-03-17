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
// leetcode problem
class MedianFinder {
public:
   vector<int> list;
    MedianFinder() {
        
    }
    priority_queue<int> left_max_heap;
    priority_queue<int, vector<int>, greater<int>> right_min_heap;
    void addNum(int num) {
         if(left_max_heap.empty() || num<left_max_heap.top()){
            left_max_heap.push(num);
         }
         else{
            right_min_heap.push(num);
         }
         if(left_max_heap.size()<right_min_heap.size()){
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
         }
         else if((left_max_heap.size() - right_min_heap.size())>1){
                right_min_heap.push(left_max_heap.top());
                left_max_heap.pop();
            }
    }
    
    double findMedian() {
        // sort(list.begin(),list.end());
        // int n = list.size();
        // if(n % 2 != 0){
        //     int index1 = n/2;
        //     double m = list[index1];
        //     return m;
        // }
        // else{
        //     int index1 = n/2-1;
        //     int index2 = n/2;
        //     double m = (list[index1] + list[index2])/2.0;
        //     return m;
        // }
        if(left_max_heap.size() == right_min_heap.size()){
            return (left_max_heap.top()+right_min_heap.top())/2.0;
        }
        return left_max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
