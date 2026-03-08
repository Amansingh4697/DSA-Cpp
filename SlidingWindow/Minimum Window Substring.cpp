class Solution {
public:
    string minWindow(string s, string t) {
        // map<char,int> tfreq;
        // map<char,int> sfreq;
        // string ans = "";
        // int minLen = INT_MAX;
        // for(char c : t){
        //  tfreq[c]++;
        // }
        // for(int i = 0;i<s.size();i++){
        //    for(int j = i;j<s.size();j++){
        //     string sub = s.substr(i,j-i+1);
        //      for(char c : sub){
        //         sfreq[c]++;
        //      }
        //      bool valid = true;
        //      for(auto it : tfreq){
        //         if(sfreq[it.first] < it.second){
        //           valid = false;
        //           break;
        //         }
        //      }
        //      if(valid){
        //         if(sub.size()<minLen){
        //             minLen = sub.size();
        //             ans = sub;
        //         }
        //      }
        //      sfreq.clear();
        //    }
        // }
        // return ans;
        // }
        // int minLen = INT_MAX;
        // int sindex  = -1;
        // for(int i = 0;i<s.size();i++){
        //     int hash[256] = {0};
        //     for(int j = 0;j<t.size();j++){
        //         hash[t[j]]++;
        //     }
        //     int cnt = 0;
        //     for(int j = i;j<s.size();j++){
        //      if(hash[s[j]]>0){
        //         cnt++;
        //         hash[s[j]]--;
        //      }
        //      if(cnt == t.size()){
        //         if((j-i+1)<minLen){
        //             minLen = j-i+1;
        //             sindex = i;
        //             break;
        //         }
        //      }
        //     }
        // }
        // if(sindex == -1) return "";
        // return s.substr(sindex,minLen);
        int minLen = INT_MAX;
        int sindex  = -1;
        int hash[256] = {0};
        for(int i = 0;i<t.size();i++){
            hash[t[i]]++;
        }
        int l = 0;
        int r = 0;
        int cnt = 0;
        while(r<s.size()){
            if(hash[s[r]]>0){
                cnt++;
            }
            hash[s[r]]--;
            while(cnt == t.size()){
                if((r-l+1)<minLen){
                    minLen = r-l+1;
                    sindex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        if(sindex == -1) return "";
        return s.substr(sindex,minLen);
    }
};
