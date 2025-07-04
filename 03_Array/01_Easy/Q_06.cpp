#include<bits/stdc++.h>
using namespace std;

//  Problem Statement: Given an array of integers and an integer k, rotate the array by k positions to left and right

//  Link: 

/*
 @Approach:
 - Approach_1: Using an extra array, and placing the elements at their correct position.
 - Approach_2: Using the reversal approach, for rotating the array in-place
 
 @Complexity:
 - Time:
   - Approach 1: O(n)
   - Approach 2: O(n)
 - Space:
   - Approach 1: O(n)
   - Approach 2: O(1)
*/

void reverse(vector<int> &arr, int start, int end){
    while (start < end){
        swap(arr[start++], arr[end--]);
    }
}

void printArray(vector<int> &arr){
    cout<<"Array: ";
    for (auto i:arr) cout<<i<<"  ";
    cout<<endl;
}

vector<int> approach_1_right(vector<int> arr, int k){
    k = k%arr.size();
    if (k == 0 || arr.empty()) return arr;
    int n = arr.size();
    vector<int> r_rot(n);
    for (int i=0; i<n; i++){
        r_rot[(i+k)%n] = arr[i]; //To get the new position of arr[i], in r_rot we add the k to the current i to shift that many place, then mod n to wrap in the valid range
    }
    return r_rot;
}

vector<int> approach_1_left(vector<int> arr, int k){
    k = k%arr.size();
    if (k == 0 || arr.empty()) return arr;
    int n = arr.size();
    vector<int> l_rot(n);
    for (int i=0; i<n; i++){
        l_rot[i] = arr[(i+k)%n]; //In this we try reverse approach, rather than finding where would be the new position of the current element, we find from which position does the rotated/shifted element would come from original array

        // l_rot[((i-k)+n)%n] = arr[i]; //First we get correct position by i-k, then to ensure valid index i.e. non-negative we add n, then to wrap in the index range we do mod with n 
    }
    return l_rot;
}

void approach_1(vector<int> arr, int k){
    cout<<"Right Rotation-\n";
    vector<int> r_rot = approach_1_right(arr, k);
    printArray(r_rot);
    cout<<"Left Rotation-\n";
    vector<int> l_rot = approach_1_left(arr, k);
    printArray(l_rot);
}

vector<int> approach_2_right(vector<int> arr, int k){
    k = k%arr.size();
    if (k == 0 || arr.empty()) return arr;
    reverse(arr, 0, arr.size()-1-k);
    reverse(arr, (arr.size()-1-k)+1, arr.size()-1);
    reverse(arr, 0, arr.size()-1);
    return arr;
}

vector<int> approach_2_left(vector<int> arr, int k){
    k = k%arr.size();
    if (k == 0 || arr.empty()) return arr;
    reverse(arr, 0, k-1);
    reverse(arr, (k-1)+1, arr.size()-1);
    reverse(arr, 0, arr.size()-1);
    return arr;
}

void approach_2(vector<int> arr, int k){
    cout<<"Right Rotation-\n";
    vector<int> r_rot = approach_2_right(arr, k);
    printArray(r_rot);
    cout<<"Left Rotation-\n";
    vector<int> l_rot = approach_2_left(arr, k);
    printArray(l_rot);
    
}

int main(){
    int s,k;
    cin>>s>>k;
    vector<int> arr(s);
    for (int i=0; i<s; i++) cin>>arr[i];
    cout<<"Before Rotation-\n";
    printArray(arr);
    cout<<"After Rotation by "<<k<<" positions-\n";
    approach_1(arr, k);
    

}