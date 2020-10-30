// Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.
// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0

#include<bits/stdc++.h>
# define endl '\n'
using namespace std;
int main()
 {
     int t;
	for(cin>>t;t--;){
	    int n, n0=0,n1=0,n2=0, k;
	    cin>>n;
	    while(n--) {
	        cin>>k;
	        if(k==0) n0++;
	        else if(k==1) n1++;
	        else if(k==2) n2++;
	    }
	    while(n0--) cout<<0<<" ";
        while(n1--) cout<<1<<" ";
        while(n2--) cout<<2<<" ";
        cout<<endl;
	}
	return 0;
}