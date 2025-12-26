class Solution {
public:
    bool checkPalindrome(string s){
        int i = 0;
        int j = s.size() - 1;
        
        while(i<=j){
            if(s[i] != s[j]){
               return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void palindromePartition(string s,int n ,int index,vector<string> path,vector<vector<string>> &out){
        if(index == n){
            out.push_back(path);
            return;
        }
    for(int i = index;i<n;i++){
        if(checkPalindrome(s.substr(index,i-index + 1))){
            path.push_back(s.substr(index,i-index + 1));
            palindromePartition(s,n,i+1,path,out);
            path.pop_back();
        }  
    }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> out;
        int n = s.size();
        palindromePartition(s,n,0,{},out);
        return out;
    }
};
