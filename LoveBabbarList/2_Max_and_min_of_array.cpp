// Given three distinct numbers A, B and C. Find the number with value in middle (Try to do it with minimum comparisons)
// https://practice.geeksforgeeks.org/problems/middle-of-three2926/1


// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++

class Solution{
  public:
    int middle(int A, int B, int C){
        int n1 = max(A, B);
        int n2 = min(n1, C);
        int ans = max(n2, A+B-n1);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
}  // } Driver Code Ends