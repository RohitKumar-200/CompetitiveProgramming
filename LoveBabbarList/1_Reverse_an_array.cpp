// Write a program to reverse an array or string
// https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

# include<bits/stdc++.h>
# define endl '\n'
using namespace std;
int main()
{
	int t;
	for(cin>>t; t--;) {
	    string s;
	    cin>>s;
	    for(int i=0, j=s.size()-1; i<j; i++, j--) {
	        int tmp = s[i];
	        s[i]=s[j];
	        s[j]=tmp;
	    }
	    cout<<s<<endl;
	}
	return 0;
}