// Move all negative numbers to beginning and positive to end with constant extra space
// https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {-12, 11, -13, -5, 6, -7, 5, -3, 11};
    int n = sizeof(a) / sizeof(a[0]);
    for(int i=0, j=n-1;i<j;) {
        if(a[i]>0 && a[j]<0) {
            swap(a[i], a[j]);
            i++, j--;
        }
        if(a[i]<0) i++;
        if(a[j]>0) j--;
    }
    for(auto it:a) cout<<it<<" ";
    cout<<endl;
}