class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        if((num&(1<<i-1 ))!= 0){
            cout<<1;
        }else{
            cout<<0;
        }
        cout<<" ";
         cout<<(num|(1<<i-1));
         cout<<" ";
         cout<<(num&(~(1<<i-1)));
    }
};
