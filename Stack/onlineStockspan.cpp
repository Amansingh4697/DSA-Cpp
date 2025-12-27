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
