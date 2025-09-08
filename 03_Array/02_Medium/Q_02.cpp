#include<bits/stdc++.h>
using namespace std;

//  Problem Statement: Given an array nums containing numbers as 0,1,2. Sort them in-place, without using any built-in function

//  Link: https://leetcode.com/problems/sort-colors/description/

/*
 @Approach:
 - Approach: Create three pointers i.e. l, m, r and in starting l = 0, m = 0, r = size -1. Now iterate till m <= r. Whenever we found 0, swap l,m and increment both pointer, when found 1 just increment m, when found 2, just swap m,r and decrement r. At the end all 0 would be behind or at l, all 2 would be ahead or at r and in between would be all 1
 
 @Complexity:
 - Time:  O(n)
 - Space: O(1)
*/

void printArray(vector<int> &arr){
    cout<<"Array: ";
    for (auto i:arr) cout<<i<<"  ";
    cout<<endl;
}

vector<int> arrayInput(){
    int s;
    cin>>s;
    vector<int> arr(s);
    for (int i=0; i<s; i++) cin>>arr[i];
    return arr;
}

void approach(vector<int> &arr){
    int l = 0;
    int m = 0;
    int r = arr.size()-1;
    while (m <= r){
        if (arr[m] == 0){
            swap(arr[m], arr[l]);
            m++;
            l++;
        }
        else if (arr[m] == 1){
            m++;
        }
        else{
            swap(arr[m], arr[r]);
            r--;
        }
    }
}

int main(){
    vector<int> arr = arrayInput();
    approach(arr);
    printArray(arr);
    return 0;
}
