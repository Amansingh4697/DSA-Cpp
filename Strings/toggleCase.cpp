class Solution {
  public:
    string toggleCase(string &s) {
        // code here
        for(int i = 0;i<s.size();i++){
            if(isupper(s[i])){
                s[i] = tolower(s[i]);
            }
            else if(islower(s[i])){
                s[i] = toupper(s[i]);
            }
        }
        return s;
    }
};
