class Solution {
 static bool comparator(pair<int,int> val1,pair<int,int> val2){
     if((val1.first/(double)val1.second)>(val2.first/(double)val2.second)){
         return true;
     }
     return false;
 }
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
       vector<pair<int,int>> items;
       for(int i = 0;i<val.size();i++){
           items.push_back({val[i],wt[i]});
       }
       sort(items.begin(),items.end(),comparator);
       double total = 0;
       for(int i = 0;i<items.size();i++){
           if(items[i].second<=capacity){
               total = total + items[i].first;
           capacity = capacity - items[i].second;
           }
           else{
               double temp = (items[i].first/(double)items[i].second);
               total = total + temp*capacity;
               break;
           }
       }
       return total;
    }
};
