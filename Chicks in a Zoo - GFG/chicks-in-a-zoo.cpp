//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    // Code here
	    vector<long long int>chick(n,0);
	    
	    chick[0] = 1;
	    long long int tot = 1;
	    
	    for(int i = 1; i<n; i++){
	        if(i >= 6)
	           tot -= chick[i-6];
	        chick[i] = tot*2;
	        tot += chick[i];
	    }
	    return tot;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends