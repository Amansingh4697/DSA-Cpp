class StockSpanner {
    Stack<int[]> stc = new Stack<>();
    public StockSpanner() {
        
    }
    
    
    public int next(int price) {
        int span = 1;
        while(!stc.isEmpty() && stc.peek()[0] <= price){
            span += stc.peek()[1];
            stc.pop();
        }
        stc.push(new int[]{price,span});
        return span;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
// another optimal approach
class StockSpanner {
public:
    stack<pair<int,int>> st;
    int idx = -1;
    StockSpanner() {
    }
    
    int next(int price) {  
        idx = idx + 1; 
        while( !st.empty() && st.top().first<=price){
          st.pop();
        }
        int span = idx - (st.empty() ? -1: st.top().second);
        st.push({price,idx});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
