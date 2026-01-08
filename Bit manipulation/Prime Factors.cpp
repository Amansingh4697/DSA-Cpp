class Solution {
  public:
    bool checkPrime(int n){
        if(n==1) return false;
      for(int i = 2;i<=sqrt(n);i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    vector<int> primeFac(int n) {
        // code here
        if(n==1){
            return {};
        }
        vector<int> list;
        // for(int i = 1;i<=sqrt(n);i++){
        //     if(n%i == 0) {
        //         if(checkPrime(i)){
        //             list.push_back(i);
        //         }
        //         if(checkPrime(n/i) && (n/i) != i){
        //             list.push_back(n/i);
        //         }
        //     }
        // }
        // return list;
        // for(int i = 2;i<=n;i++){
        //     if(n%i == 0){
        //         while(n%i == 0){
        //             n = n/i;
        //         }
        //         list.push_back(i);
        //     }
        // }
        // return list;
        for(int i = 2;i<=sqrt(n);i++){
            if(n%i == 0){
                while(n%i == 0){
                  n = n/i;  
                }
                list.push_back(i);
            }
        }
         if(n!=1){
                list.push_back(n);
            }
            return list;
    }
};
