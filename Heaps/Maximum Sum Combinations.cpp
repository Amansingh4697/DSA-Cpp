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
//optimal approach
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int> ans;
    priority_queue<pair<int,int>> pq;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i = 0;i<A.size();i++){
        pq.push({(A[i]+B[B.size()-1]),B.size()-1});
    }
    while(!pq.empty() && C--){
        int sum = pq.top().first;
        int index = pq.top().second;
        ans.push_back(sum);
        pq.pop();
        if(index-1>=0){
            pq.push({sum-B[index]+B[index-1],index-1});
        }
    }
    return ans;
}

