class Node{
    public:
    int data;
    int i;
    int j;
    Node(int data,int row, int col){
        this->data = data;
        i = row;
        j = col;
    }
};
class compare{
    public:
    bool operator()(Node* a , Node* b){
        return a->data>b->data;
    }
};
class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        priority_queue<Node*,vector<Node*> ,compare> pq;
        vector<int> ans;
        int k = mat.size();
        // step1; insert sarre first elements of each arrays
        for(int i = 0;i<k;i++){
            Node* temp = new Node(mat[i][0],i,0);
            pq.push(temp);
        }
        // step2;insert top element into ans arrays than move to next element of same array if exist
        while(pq.size()>0){
            Node* temp = pq.top();
            ans.push_back(temp->data);
            int i = temp->i;
            int j = temp->j;
            pq.pop();
            if(j+1<mat[i].size()){
                pq.push(new Node(mat[i][j+1],i,j+1));
            }
        }
        return ans;
    }
};
