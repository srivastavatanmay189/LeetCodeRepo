//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int>ans;
    unordered_map<int,int>um;
    void check(vector<int>& pre, vector<int>& in, int sp, int ep , int si, int ei){
        if(sp>ep)return;
        if(sp == ep){
            ans.push_back(pre[sp]);
            return;
        }
        
        int ii = um[pre[sp]];
        check(pre, in, sp+1, sp+ii-si, si, ii-1);
        check(pre, in, sp+ii-si+1, ep, ii+1, ei);
    }
    vector<int> leafNodes(int arr[],int N) {
        // code here
        vector<int>in(N);
        vector<int>pre(N);
        
        for(int i = 0; i<N; i++){
            in[i] = arr[i];
            pre[i] = arr[i];
        }
        sort(in.begin(), in.end());
        for(int i = 0; i<N; i++){
            um[in[i]] = i;
        }
        check(pre, in, 0, N-1, 0, N-1);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends