//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    

    int find(int n, int m, int nm){
        //cout<<nm<<" j ";
        int newnm = nm*10 + (nm%10), ans = 0;
        if(nm%10 != 9 && newnm+1 <= m){
            ans +=  (newnm+1 >=n)+find(n, m, newnm+1);
        }
        if(nm%10 != 0 && newnm-1 <= m){
            ans +=  (newnm-1 >= n)+find(n, m, newnm-1);
        }
        return ans;
    }
    int steppingNumbers(int n, int m)
    {
        // Code Here
        int ans = 0;
        for(int i = 0; i<= 9; i++){
            if(i>= n && i <= m){
                ans += 1;
            }
            if(i !=0)ans += find(n, m, i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends