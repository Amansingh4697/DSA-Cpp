// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         bool sign = true;
//         if(divisor == dividend) return 1;
//         if(divisor==0) return INT_MAX;
//         if(dividend>=0 && divisor<0) sign = false;
//         if(dividend<0 && divisor>0) sign = false;
//         if (dividend == INT_MIN && divisor == -1)
//             return INT_MAX;
//         long n = llabs((long long)dividend);
//         long d = llabs((long long)divisor);
//         long ans = 0;
//         while(n>=d){
//             int cnt = 0;
//             while(n>= (d<<(cnt+1))){
//                 cnt++;
//             }
//           ans = ans + (1<<cnt);
//           n = n -(d<<cnt);
//         }
//         if(ans>=INT_MAX && sign == true ) return INT_MAX;
//         if(ans>=INT_MAX && sign == false) return INT_MIN;
//         return sign?ans:-1*ans;
//     }
// };
class Solution {
public:
    int divide(int dividend, int divisor) {

        // Division by zero
        if (divisor == 0) return INT_MAX;

        // Only overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool sign = (dividend < 0) ^ (divisor < 0);

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long ans = 0;

        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            ans += (1LL << cnt);
            n -= (d << cnt);
        }

        return sign ? -ans : ans;
    }
};
