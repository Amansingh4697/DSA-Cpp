class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<int> knowMe(n,0);
        vector<int> Iknow(n,0);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if((i != j) &&mat[i][j] == 1){
                    knowMe[j]++;
                    Iknow[i]++;
                }
            }
        }
        for(int i = 0;i<n;i++){
            if(knowMe[i] == n-1 && Iknow[i] == 0){
                return i;
            }
        }
        return -1;
    }
};

// Optimal Soltion
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int top = 0;
        int down = n-1;
        while(top<down){
            if(mat[top][down] == 1){
                top++;
            }
            else if(mat[down][top] == 1){
                down--;
            }
            else{
                top++;
                down--;
            }
        }
        if(top>down){
            return -1;
        }
        else if(top == down){
            for(int i =0;i<n;i++){
                if(top == i){
                    continue;
                }
                if((mat[top][i] == 0) && (mat[i][top] == 1)){
                }
                else{
                    return -1;
                }
            }
        }
        return top;
    }
};
