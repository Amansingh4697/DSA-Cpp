class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
//         int n = bills.size();
//         int i = 0;
//         if(i == 0 && bills[0] != 5) return false;
//         int freq[21] = {0};
//         while(i<n){
//             int amount = bills[i];
//             if(bills[i] == 5){
//                 freq[bills[i]]++;
//             }
//             else{
//                 freq[bills[i]]++;
//                 while(amount>5){
//                     if(freq[10] != 0 && amount > 10){
//                         amount = amount - 10;
//                         freq[10]--;
//                     }
//                     else if(freq[5] != 0 && amount>5){
//                         amount = amount - 5;
//                         freq[5]--;
//                     }
//                     else{
//                         return false;
//                     }
//                 }
//             }
//             i++;
//         }
// return true;
int n = bills.size();
int five = 0;
int ten = 0;
int i = 0;
while(i<n){
    if(bills[i] == 5){
        five++;
    }
    else{
        if(bills[i] == 10){
            if(five){
                five--;
                ten++;
            }
            else{
                return false;
            }
        }
        else{
            if(ten && five){
                five--;
                ten--;
            }
            else if(five>=3){
                five -= 3;
            }
            else{
                return false;
            }
        }
    }
    i++;
}
return true;
    }
};
