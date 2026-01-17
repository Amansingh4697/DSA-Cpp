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
    string infixToPrefix(string &s) {
        // code here
        reverse(s.begin(),s.end());
        for (char &c : s) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
      }
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
                if(s[i] == '^'){
                    while(!st.empty() && (priorty(s[i]) <= priorty(st.top()))){
                        ans = ans + st.top();
                        st.pop();
                    }
                }
                else{
                    while(!st.empty() && (priorty(s[i])<priorty(st.top()))){
                        ans = ans + st.top();
                        st.pop();
                    }
                }

                  st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
