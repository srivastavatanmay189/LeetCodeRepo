//{ Driver Code Starts
// Initial Template for C++

// Initial Template for C++
// Back-end complete function Template for C++
// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long lcmTriplets(long long N) {
        // code here
         long long int ans=1;

        if(N<=2)

        return N;

        if(N&1)

        {

            ans=ans*N*(N-1)*(N-2);

            return ans;

        }

        else

        {

            long long int p,q,lcm1,lcm2,maxi,r,s,lcm3,lcm4,t,u,lcm5,lcm6;

            

            p=__gcd(N,N-1);

            lcm1=N*(N-1)/p;

            q=__gcd(lcm1,N-2);

            lcm2=lcm1*(N-2)/q;

            

            r=__gcd(N,N-1);

            lcm3=N*(N-1)/r;

            s=__gcd(lcm3,N-3);

            lcm4=lcm3*(N-3)/s;

            

            t=__gcd(N-2,N-1);

            lcm5=(N-1)*(N-2)/t;

            u=__gcd(lcm5,N-3);

            lcm6=lcm5*(N-3)/u;

            

            maxi=max({lcm2,lcm4,lcm6});

            return maxi;

        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.lcmTriplets(N) << "\n";
    }
}
// } Driver Code Ends