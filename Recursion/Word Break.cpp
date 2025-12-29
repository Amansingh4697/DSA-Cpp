class Solution {
public:
    bool checkWord(string str,unordered_set<string>& dict){
    // for(int i=0;i<wordDict.size();i++){
    //   if(str == wordDict[i]) return true;
    // }
    // return false;
    return dict.find(str) != dict.end();
    }
    bool WordPartion(string s,unordered_set<string>& dict,int index){
        if(index >= s.size()) return true;
       for(int i = index;i<s.size();i++){
        if(checkWord(s.substr(index,i-index + 1),dict)){
          if(WordPartion(s,dict,i+1)){
            return true;
          }
        }
       }
       return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return  WordPartion(s,dict,0);
    }
};
