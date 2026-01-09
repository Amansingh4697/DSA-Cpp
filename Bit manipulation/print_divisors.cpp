class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        vector<int> list;
        for(int i = 1;i*i<=n;i++){
            if(n%i == 0){
                list.push_back(i);
                if((n/i) != i){
                    list.push_back(n/i);
                }
            }
        }
        sort(list.begin(),list.end());
        for(int i = 0;i<list.size();i++){
            cout<<list[i]<<" ";
        }
    }
};
