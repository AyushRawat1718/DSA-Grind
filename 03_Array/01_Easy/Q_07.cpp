#include<bits/stdc++.h>
using namespace std;

//  Problem Statement: You are given an array of integers. Move all the zeros to the end, while maintaining the relative order of the non-zero elements.

//  Link: https://leetcode.com/problems/move-zeroes/description/

/*
 @Approach:
 - Approach 1 (Using Extra Space):  We make a new array. First, we copy all non-zero numbers into it one by one. After that, we fill the rest of the array with zeros. 

 - Approach 2 (In-Place Two-Pointer Method): We use two pointers. One goes through every element in the array. The second one keeps track of where the next non-zero number should go. When we find a non-zero number, we put it in the right place using the second pointer. After we're done, we fill the rest of the array with zeros.


 @Complexity:
 - Time Complexity:
   - Approach 1: O(n)
   - Approach 2: O(n)

 - Space Complexity:
   → Approach 1: O(n) — due to the extra array used
   → Approach 2: O(1) — in-place, constant space
*/

void printArray(vector<int> &arr){
    cout<<"Array: ";
    for (auto i:arr) cout<<i<<"  ";
    cout<<endl;
}

void approach_1(vector<int> arr){
    vector<int> req(arr.size());
    int ptr = 0;
    for (auto i : arr){
        if (i!=0){
            req[ptr] = i;
            ptr++;
        }
    }
    for (int i=ptr; i<req.size(); i++) req[i] = 0;
    cout<<"After Conversion -\n";
    printArray(req);
}

void approach_2(vector<int> arr){
    int j = 0;
    for (int i=0; i<arr.size(); i++){
        if (arr[i]!=0){
            arr[j] = arr[i];
            if (i != j){
                arr[i] = 0;
            }
            j++;
        }
    }

    cout<<"After Conversion -\n";
    printArray(arr);
}

int main(){
    int x;
    cin>>x;
    vector<int> arr(x);
    for (int i=0; i<x; i++) cin>>arr[i];
    approach_2(arr);
    
    
    return 0;
}