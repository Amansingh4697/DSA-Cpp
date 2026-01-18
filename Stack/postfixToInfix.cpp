// User function Template for C++

class Solution {
  public:
    string postToInfix(string &exp) {
        // Write your code here
        int i = 0;
        stack<string> st;
        while(i<exp.size()){
            string ans = "";
            if((exp[i]>='A' && exp[i]<='Z')|| (exp[i]>='a' && exp[i]<='z')
            || (exp[i]>='0' && exp[i]<='9')){
                st.push(string(1,exp[i]));
            }
            else {
                 string opr2 = st.top();st.pop();
                 string opr1 = st.top();st.pop();
                 ans = "(" + opr1 + string(1,exp[i]) +opr2+ ")";
                 st.push(ans);
            }
            i++;
            }
            return st.top();
        }
};
