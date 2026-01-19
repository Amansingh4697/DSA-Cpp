// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        int i = 0;
        stack<string> st;
        while(i<post_exp.size()){
            if((post_exp[i]>='A' && post_exp[i]<='Z')|| (post_exp[i]>='a' && post_exp[i]<='z')
            || (post_exp[i]>='0' && post_exp[i]<='9')){
                st.push(string(1,post_exp[i]));
            }else{
                string top1 = st.top();st.pop();
                string top2 = st.top();st.pop();
                string temp = post_exp[i]+top2+top1;
                st.push(temp);
            }
            i++;
        }
        return st.top();
    }
};
