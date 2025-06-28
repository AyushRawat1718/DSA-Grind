#include<bits/stdc++.h>
using namespace std;

//  Problem Statement: Given an array, we have to find the largest element in the array.

//  Link: 

/*
 @Approach:
 - Approach 1: Sort the array and pick the last element. This has a time complexity of O(n log n).
 - Approach 2: Traverse the array once, keeping track of the maximum element. This is more optimized with O(n) time complexity.

 @Complexity:
 - Time:
   - Approach 1: O(n log n)
   - Approach 2: O(n)
 - Space:
   - Both approaches: O(1) extra space (excluding input)
*/

void approach_1(vector<int> arr){
    sort(arr.begin(), arr.end());
    cout<<"The largest element of the array is: "<<arr[arr.size()-1]<<endl;
}

void approach_2(vector<int> arr){
    int maxi = INT_MIN;
    for (auto i : arr) if (i > maxi) maxi = i;
    cout<<"The largest element of the array is: "<<maxi<<endl;
}

int main(){
    int x;
    cin>>x;
    vector<int> arr(x);
    for (int i=0; i<x; i++) cin>>arr[i];
    approach_1(arr);
    approach_2(arr);
    
    return 0;
}