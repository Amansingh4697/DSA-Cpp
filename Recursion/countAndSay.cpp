class Solution {
    string  countandsay(int n){
        if(n == 1){
            return "1";
        }
        string prev = countandsay(n-1);
        string result = "";
        int count = 1;
        for(int i = 1;i<prev.length();i++){
            if(prev[i-1] == prev[i]){
                count++;
            }
            else{
               string val = to_string(count);
                result = result + val + prev[i-1];
                count = 1;
            }
        }
        result += to_string(count);
        result += prev.back();
        return result;
        
    }
public:
    string countAndSay(int n) {
        string say = countandsay(n);
        return say;
    }
};
