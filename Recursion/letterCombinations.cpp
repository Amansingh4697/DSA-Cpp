class Solution {
public:
    void allCombinations(string digits,int index,string output,vector<string> &res,string mapping[]){
        if(index>=digits.size()){
            res.push_back(output);
            return;
        }
        int number = digits[index] - '0';
        string value = mapping[number];
        for(int i = 0;i<value.size();i++){
            output.push_back(value[i]);
            // output = output + value[i];
           allCombinations(digits,index+1,output,res,mapping);
           output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
         string mapping[10] = {
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
         };
         string output = "";
         vector<string> res;
         allCombinations(digits,0,output,res,mapping);
         return res;
    }
};
