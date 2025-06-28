#include<bits/stdc++.h>
using namespace std;

//  Problem Statement: Given an array of size n, write a program to check if the given array is sorted in (ascending / Increasing / Non-decreasing) order or not. If the array is sorted then return True, Else return False.

//  Link: 

/*
 @Approach: First of all we would check if the size of the array is less than 2 then the array is already sorted, else we would start with the first element and keep on checking if the next element is  smaller than the current or not, we will check this until second last element and whenever the next element is smaller we would return false, else return true at the end.
 
 @Complexity:
 - Time: O(n), single traversal
 - Space: O(1), no extra container used
*/

bool approach(vector<int> arr){
    if (arr.size() < 2) return true;
    for (int i=0; i<arr.size()-1; i++) if (arr[i] > arr[i+1]) return false;
    return true;
}

int main(){
    int x;
    cin>>x;
    vector<int> arr(x);
    for (int i=0; i<x; i++) cin>>arr[i];
    (approach(arr)) ? cout<<"Array is Sorted\n" : cout<<"Array is not Sorted\n"; 
    
    return 0;
}