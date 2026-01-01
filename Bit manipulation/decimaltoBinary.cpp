// User function Template for C++

void toBinary(int n) {
    // your code here
    string res ="";
    if(n == 0) cout<<'0';
    while(n>0){
        if(n%2 == 1){
            res = '1' + res;
        }
        else{
            res = '0'+res;
        }
        n = n/2;
    }
    cout<<res;
}
