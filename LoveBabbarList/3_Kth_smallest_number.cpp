// Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.
// https://practice.geeksforgeeks.org/problems/kth-smallest-element/0

# include<bits/stdc++.h>
# define endl '\n'
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--) {
	    int n,k, ans;
	    cin>>n;
	    int a[n],i,j;
	    for(i=0; i<n;i++) cin>>a[i];
	    cin>>k;
	    int l = *min_element(a, a+n);
	    int h = *max_element(a, a+n);
	    while(l<=h) {
	        int m = l + (h-l)/2;
	        int cless = 0, cequal = 0;
	        for(i=0;i<n;i++) {
	            if(a[i]<m) cless++;
	            else if(a[i]==m) cequal++;
	        }
	        if(cless < k && (cless+cequal) >= k) {
	         ans = m; break;
	        } else if(cless < k && (cless+cequal) < k) {
	            l = m+1;
	        } else if(cless >= k) {
	            h = m-1;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}