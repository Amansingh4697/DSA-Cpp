class Node{
    public:
    int data;
    int row;
    int col;
    Node(int data,int row,int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};
class compare{
    public:
    bool operator()(Node* a ,Node* b){
        return a->data>b->data;
    }
};
class Solution {
public:
 priority_queue<Node*,vector<Node*>, compare> pq;
 int maxi = INT_MIN;
 int mini = INT_MAX;
 int ansStart ;
 int ansEnd ;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        for(int i = 0;i<nums.size();i++){
          Node* newNode = new Node(nums[i][0],i,0);
          pq.push(newNode);
          maxi = max(maxi,nums[i][0]);
        }
        ansStart = pq.top()->data;
        ansEnd = maxi;
        while(pq.size()){
            Node* temp  = pq.top();
            mini = temp->data;
            int row = temp->row;
            int col = temp->col;
            pq.pop();
            if((maxi - mini)<(ansEnd - ansStart)){
                ansEnd = maxi;
                ansStart = mini;
            }
            if(col + 1<nums[row].size()){
                maxi = max(maxi,nums[row][col + 1]);
                pq.push(new Node(nums[row][col+1],row,col+1));
            }
            else{
                break;
            }
        }
        return {ansStart,ansEnd};
    }
};
