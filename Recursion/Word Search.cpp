class Solution {
public:
     bool searchWordSequence(string &word,int index,int n,int i ,int j, vector<vector<char>>& board){
      if(index>=n){
        return true;
      }
      if(i<0 || i>=board.size()|| j<0 || j>=board[0].size() || board[i][j] != word[index]) return false;
       char temp = board[i][j];
        board[i][j] = '#';
     bool found = searchWordSequence(word,index+1,n,i-1,j,board)
       || searchWordSequence(word,index+1,n,i+1,j,board) ||
       searchWordSequence(word,index+1,n,i,j-1,board)
       || searchWordSequence(word,index+1,n,i,j+1,board) ;
       board[i][j] = temp;
      return found;
      }

    bool exist(vector<vector<char>>& board, string word) {
        int n= word.size();
       for(int i = 0;i<board.size();i++){
          for(int j = 0;j<board[0].size();j++){
              if(board[i][j] == word[0]){
                if(searchWordSequence(word,0,n,i ,j,board)) return true;
              }
        }
       }
       return false;
    }
};
