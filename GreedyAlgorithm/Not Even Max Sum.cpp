#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long maxSum(int N,vector<int> &arr){
long long maxOddsum = 0;
int smallestOdd = INT_MAX;
for(int i = 0;i<N;i++){
	if(arr[i] % 2 != 0){
      smallestOdd = min(arr[i],smallestOdd);
	}
	maxOddsum = maxOddsum + arr[i];
}
if(maxOddsum % 2 != 0) return maxOddsum;

if(smallestOdd == INT_MAX) return 0;

return maxOddsum - smallestOdd;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<int> arr(n,0);
	for(int i = 0;i<n;i++){
     cin>>arr[i];
	}
	cout<<maxSum(n,arr)<<endl;
	}
	return 0;
}
