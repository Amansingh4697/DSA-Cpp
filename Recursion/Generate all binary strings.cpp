class Solution {
  public:
  void gen(int pos,string s,vector<string> &out,int n){
      if(pos == n) {out.push_back(s); return;}
      s[pos] = '0';gen(pos+1,s,out,n);
      s[pos] = '1';gen(pos+1,s,out,n);
  }
    vector<string> binstr(int n) {
        // code here
        vector<string> out ;
        string s(n,0);
        gen(0,s,out,n);
        return out;
    }
};
