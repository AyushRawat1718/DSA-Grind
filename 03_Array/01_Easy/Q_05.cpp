#include<bits/stdc++.h>
using namespace std;

//  Problem Statement: Given an array of N integers, left rotate the array by one place.

//  Link: https://leetcode.com/problems/rotate-array/description/

/*
 @Approach: As we only have to rotate the array to left by one place, so the only change would be that the first element would come to last place and all elements shift forward by one position. So store the first element in a variable, and shift all the other elements and then update the last element.
 
 @Complexity:
 - Time: O(n)
 - Space: O(1) 
*/

void approach(vector<int> &arr){
    if (arr.empty()) return;
    int temp = arr[0];
    for (int i=0; i<arr.size()-1; i++){
        arr[i] = arr[i+1];
    }
    arr[arr.size()-1] = temp;
}

void printArray(vector<int> &arr){
    cout<<"Array: ";
    for (auto i:arr) cout<<i<<"  ";
    cout<<endl;
}

int main(){
    int x;
    cin>>x;
    vector<int> arr(x);
    for(int i=0; i<x; i++) cin>>arr[i];
    cout<<"Before Rotation\n";
    printArray(arr);
    approach(arr);
    cout<<"After Rotation\n";
    printArray(arr);
    
    return 0;
}