class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        // moves non space character to the front
        // auto newend = remove(s.begin(),s.end(),' ');
        // // erase extra spaces 
        // s.erase(newend,s.end());
        // return s;
        int n = s.size();
        int i = 0;
        int j = 0;
        while(j<n){
            if(s[j] != ' '){
                swap(s[i],s[j]);
                i++;
                j++;
            }
            else if(s[j] == ' '){
                j++;
            }
        }
        // it will remove everthing after this index
        s.erase(i);
        return s;
        
    }
};
