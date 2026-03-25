class Solution {
public:
    // bool checkCombinations(string s, int i ,int cnt,int n){
    //     if(cnt == -1) return false;
    //     if(i == n){
    //         return (cnt == 0);
    //     }
    //    if(s[i] == '(') return checkCombinations(s,i+1,cnt+1,n);
    //    if(s[i] == ')') return checkCombinations(s,i+1,cnt-1,n);
    //    if(s[i] == '*') return (checkCombinations(s,i+1,cnt+1,n) || checkCombinations(s,i+1,cnt-1,n) || checkCombinations(s,i+1,cnt,n));
    //    return false;
    // }
    bool checkValidString(string s) {
        // int n = s.size();
        // return checkCombinations(s,0,0,n);
        int min = 0;
        int max = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(') {
                min += 1;
                max += 1;
            }
            else if(s[i] == ')'){
                min -= 1;
                max -= 1;
            }
            else{
                min -= 1;
                max  += 1;
            }
            if(min<0) min = 0;
            if(max<0) return false;
        }
        return (min == 0);
        // stack approach
        // stack<pair<int,int>> pstack;
        // stack<pair<int,int>> starstack;
        // for(int i = 0;i<s.size();i++){
        //     if(s[i] == '('){
        //         pstack.push({i,'('});
        //     }
        //     else if(s[i] == ')'){
        //         if(!pstack.empty()){
        //             pstack.pop();
        //         }
        //         else if(!starstack.empty()){
        //             starstack.pop();
        //         }
        //         else{
        //             return false;
        //         }
        //     }
        //     else{
        //        starstack.push({i,'*'}); 
        //     }
        // }
        // while(!pstack.empty()){
        //      if(starstack.empty()) return false;
        //      if(pstack.top().first > starstack.top().first) return false;
        //      pstack.pop();
        //      starstack.pop();
        // }
        // return true;
    }
};
