class Solution {
public:
    // int maxF(map<char,int> &mpp){
    //     int maxFreq = 0;
    //  for(auto &it:mpp){
    //     if(it.second>maxFreq){
    //         maxFreq = max(it.second,maxFreq);
    //     }
    //  }
    //  return maxFreq;
    // }
    int characterReplacement(string s, int k) {
    //    int maxLen = 0;
    //    int n = s.size();
    //    for(int i = 0;i<n;i++){
    //     int hash[26] = {0};
    //     int maxFreq = 0;
    //     for(int j = i;j<n;j++){
    //           hash[s[j]-'A']++;
    //        maxFreq = max(maxFreq,hash[s[j]-'A']);
    //        int len = j-i+1;
    //        int changes = len - maxFreq;
    //        if(changes <= k){
    //         maxLen = max(len , maxLen);
    //        }
    //        else{
    //         break;
    //        }
    //     }  
    //    } 
    //    return maxLen;
    // map<char,int> mpp;
    // int maxLen=0;
    // int left = 0;
    // int right = 0;
    // int n = s.size();
    // while(right<n){
    // mpp[s[right]]++;
    // int maxFreq = maxF(mpp);
    // int changes = (right-left+1)- maxFreq;
    // while(changes>k){
    //    mpp[s[left]]--;
    //    if(mpp[s[left]]==0){
    //     mpp.erase(mpp[s[left]]);
    //    } 
    //    left++;
    //    maxFreq = maxF(mpp);
    //    changes = (right-left+1)- maxFreq; 
    // }
    // if(changes<=k){
    //     maxLen = max(right-left+1, maxLen);
    // }
    // right++;
    
    // }
    // return maxLen;
    // }
    int hash[26] = {0};
    int maxLen=0;
    int left = 0;
    int right = 0;
    int n = s.size();
    int maxFreq = 0;
    while(right<n){
    hash[s[right]-'A']++;
    maxFreq = max(maxFreq,hash[s[right]-'A']);
    if((right-left+1)- maxFreq>k){
       hash[s[left]-'A']--;
       left++;
    }
    if((right-left+1)- maxFreq<=k){
        maxLen = max(right-left+1, maxLen);
    }
    right++;
    }
    return maxLen;
    }
};
