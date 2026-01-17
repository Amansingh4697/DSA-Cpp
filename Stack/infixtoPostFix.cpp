class Solution {
  public:
    int priorty(char ch){
        if(ch == '^'){
            return 3;
        }
        else if(ch=='*' || ch == '/') return 2;
        else if(ch=='+' || ch == '-') return 1;
        else{
            return -1;
        }
    }
    string infixToPostfix(string& s) {
        // code here
        stack<char> st;
        string ans = "";
        int i  = 0;
        while(i<s.size()){
            if((s[i]>='A'&& s[i]<='Z') || (s[i]>='a' && s[i]<='z')
            || (s[i]>='0' && s[i]<='9')
            ){
                ans = ans+s[i];
            }
            else if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                while(!st.empty() && st.top() !='('){
                    ans = ans+st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                 while(!st.empty() &&( (priorty(s[i]) < priorty(st.top())) 
                 || ((priorty(s[i]) == priorty(st.top())) && s[i] != '^'))
                     
                 ){
                     ans = ans+st.top();
                     st.pop();
                  }
                  st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }
        return ans;
    }
};
