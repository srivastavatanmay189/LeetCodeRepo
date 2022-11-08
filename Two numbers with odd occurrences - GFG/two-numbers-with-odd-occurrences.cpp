//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        // code here
        long long int ans=0;
        for(long long int i=0;i<n;i++)
           ans= ans^arr[i];
        
        int pos=0;
        while(ans){
            if(ans & 1)
                break;
            pos++;
            ans= ans>>1;
        }
        long long int ans1=0,ans2=0;
        for(long long int i=0;i<n;i++){
            if(arr[i]&(1<<pos))
                ans1=ans1^arr[i];
            else
                ans2=ans2^arr[i];
        }
        return {max(ans1,ans2),min(ans1,ans2)};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends