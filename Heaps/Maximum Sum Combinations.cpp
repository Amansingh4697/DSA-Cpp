vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    priority_queue<int,vector<int>, greater<int>> minHeap;
    for(int i = 0;i<A.size();i++){
        for(int j = 0;j<B.size();j++){
            int sum = A[i] + B[j];
            minHeap.push(sum);
            if(minHeap.size()>C){
                minHeap.pop();
            } 
        }
    }
    vector<int> ans;
    while(minHeap.size()){
        ans.push_back(minHeap.top());
        minHeap.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
