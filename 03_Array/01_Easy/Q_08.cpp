#include<bits/stdc++.h>
using namespace std;

//  Problem Statement: Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

//  Link: 

/*
 @Approach: Just traverse and search.
 
 @Complexity:
 - Time: O(n)
 - Space: O(1)
*/

int approach(vector<int> arr, int x){
    for (int i=0; i<arr.size(); i++) {
        if (arr[i] == x) return i; 
    }
    return -1;
}

int main(){
    int s;
    cin>>s;
    vector<int> arr(s);
    for(int i=0; i<s; i++) cin>>arr[i];
    int x;
    cin>>x;
    int ans = approach(arr, x);
    (ans == -1) ? cout<<"Element Not found in the array\n" : cout<<"Element found in the array at "<<ans<<" index\n";
    return 0;
}