class Solution {
  public:
    bool validOrNot(string& sub, string& s2){
           int i = 0;
            int j = 0;
            while(i<sub.size()){
                if(sub[i]==s2[j]){
                    i++;
                    j++;
                }
               i++;
                if(j == s2.size()){
                    return true;
                }
            }
            return false;
    }
    string minWindow(string& s1, string& s2) {
        // Code here
        int sindex = -1;
        int minLen = INT_MAX;
        int l = 0;
        int r = 0;
        while(r<s1.size()){
            string sub = s1.substr(l,r-l+1);
            bool valid = validOrNot(sub,s2);
            while(valid){
                if((r-l+1)<minLen){
                    minLen = r-l+1;
                    sindex = l;
                }
                l++;
                sub = s1.substr(l,r-l+1);
                valid =  validOrNot(sub,s2);
           }
           r++;
     }
     return (sindex==-1)?"":s1.substr(sindex,minLen);
}
};
