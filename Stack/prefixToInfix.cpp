// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        int i = pre_exp.size()-1;
        stack<string> st;
        while(i>=0){
            if((pre_exp[i]>='A' && pre_exp[i]<='Z')|| (pre_exp[i]>='a' && pre_exp[i]<='z')
            || (pre_exp[i]>='0' && pre_exp[i]<='9')){
                st.push(string(1,pre_exp[i]));
            }else{
                string top1 = st.top();st.pop();
                string top2 = st.top();st.pop();
                string temp = '('+top1+pre_exp[i]+top2+')';
                st.push(temp);
            }
            i--;
        }
        return st.top();
    }
};
