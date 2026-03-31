class Solution {
public:
    int minCandy(vector<int>& ratings){
        int i = 1;int n = ratings.size();
        int sum = 1;
        while(i<n){
            if(ratings[i] == ratings[i-1]){
            sum = sum + 1;
            i++;
            continue;
        }
        int peek = 1;
        while(i<n && ratings[i]>ratings[i-1]){
            peek += 1;sum += peek; i++;
        } 
        int down = 1;
        while(i<n && ratings[i]<ratings[i-1]){
            sum += down; down++; i++;
        }
        if(down>peek){
            sum = sum + (down - peek);
        }
        }
        return sum;
    }
    int candy(vector<int>& ratings) {
        // int n = ratings.size();
        // int left[n];
        // // int right[n];
        // left[0] = 1;
        // // right[n-1] = 1;
        // for(int i = 1;i<n;i++){
        //     if(ratings[i] > ratings[i-1]){
        //         left[i] = left[i-1] + 1;
        //     }
        //     else{
        //         left[i] = 1;
        //     }
        // }
        // for(int i =n-2;i>=0;i--){
        //     if(ratings[i] > ratings[i+1]){
        //         right[i] = right[i+1] + 1;
        //     }
        //     else{
        //         right[i] = 1;
        //     }
        // }
        // int total = 0;
        // for(int i = 0;i<n;i++){
        //     total += max(left[i],right[i]);
        // }
        // return total;
        // int crr = 1,right = 1;
        // int total = max(left[n-1],right);
        // for(int i = n-2;i>=0;i--){
        //     if(ratings[i] > ratings[i+1]){
        //         right = right + 1;
        //     }
        //     else{
        //         right = 1;
        //     }
        //     total += max(left[i],right);
        // }
        // return total;
        return minCandy(ratings);
    }
};
