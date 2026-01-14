class Solution {
    // bool validOrNot(string s,stack<char> st,int i){
    //     if(i >=s.size()){
    //         return st.empty();
    //     }
    //     if(s[i] == '{' || s[i] == '['|| s[i] == '('){
    //           st.push(s[i]);
    //           return validOrNot(s,st,i+1);
    //     }
    //     else{
    //      if(st.empty()){
    //         return false;
    //      }
    //     char top = st.top();
    //     st.pop();
    //     if((s[i] == ')' &&  top != '(' )|| s[i] == '}' &&  top != '{' ||
    //      s[i] == ']' &&  top != '['  ){
    //        return false;
    //     } 
    //     return validOrNot(s,st,i+1);
    //     }
    // }
public:
    bool isValid(string s) {
        stack<char> st;
        // return validOrNot(s,st,0);a
        for(int i =0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                char ch = st.top();
                st.pop();
                if((ch == '(' && s[i] == ')') || (ch == '{' && s[i] == '}') || (ch == '[' && s[i] == ']')){

                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};
