class Solution {
public:
    void DistinctSubsequences(string str,int index,int n,set<string> &out,string list)
    {
        if(index>=n){
            out.insert(list);
            return;
        } 
        // for taking a sequence call;
        list = list + str[index];
        DistinctSubsequences(str,index+1,n,out,list);
        //for not taking sequence call
        list.pop_back();
        DistinctSubsequences(str,index+1,n,out,list);
    }
    int distinctSubseqII(string s) {
        int n = s.size();
        set<string> out;
        string list = "";
        DistinctSubsequences(s,0,n,out,list);
        return out.size() - 1;
    }
};
