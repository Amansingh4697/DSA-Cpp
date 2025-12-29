class Solution {
  public:
    void Solve(vector<vector<int>>& maze,int i ,int j,string &path,vector<string> &out){
        if(i<0 || i>=maze.size() || j<0 || j>=maze.size() || maze[i][j] != 1){
            return;
        }
        if(i == maze.size()-1 && j == maze.size()-1) {
            out.push_back(path);
            return;
        }
         maze[i][j] = 0;
         path.push_back('D');
         Solve(maze,i+1,j,path,out);
         path.pop_back();
         path.push_back('L');
         Solve(maze,i,j-1,path,out);
         path.pop_back();
         path.push_back('R');
         Solve(maze,i,j+1,path,out);
         path.pop_back();
         path.push_back('U');
         Solve(maze,i-1,j,path,out);
         path.pop_back();
         maze[i][j] = 1;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
         string path = "";
         vector<string> out;
         Solve(maze,0,0,path,out);
         return out;
    }
};
