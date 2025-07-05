#include<bits/stdc++.h>
using namespace std;

//  Problem Statement: Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.

//  Link: https://leetcode.com/problems/missing-number/description/

/*
 @Approach:
 - Approach_1: Store the frequency of each element in the array, and then after that check which ever element is missing

 - Approach_2: Sum all the elements of the array, and then use the formula of sum of 'n' natural numbers, to get the missing element

 - Approach_3: Concept of XOR => a^a = 0 and a^0 = a, so first of all we would take xor of all the elements of array, then again xor of all n natural numbers, to get the missing number 
 
 @Complexity:
 - Time: 
    - Approach_1: O(n) => Traversing the array once
    - Approach_2: O(n) => Traversing the array once
    - Approach_3: O(n) + O(n) => O(n) => Traversing the array twice
 
 - Space:
    - Approach_1: O(n) => For hash array
    - Approach_2: O(1)
    - Approach_3: O(1)
*/

void approach_1(vector<int>& arr, int N){
    vector<int> hash(N+1); // as we want indexes from 1 to N
    hash[0] = -1; //never used
    for(auto i : arr) hash[i]++;
    for (int i=1; i<=N; i++){
        if (!hash[i]) {
            cout<<"Missing number is "<<i<<endl;
            return;
        }
    }
}

void approach_2(vector<int>& arr, int N){
    int sum = 0;
    for (auto i : arr) sum += i;
    int req_sum = N*(N+1)/2;
    cout<<"Missing number is "<<req_sum-sum<<endl;
}

void approach_3(vector<int>& arr, int N){
    int xor1 = 0;
    int xor2 = 0;
    for (auto i : arr) xor1 ^= i;
    for (int i=1; i<=N; i++) xor2 ^= i;
    cout<<"Missing number is "<<(xor1^xor2)<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n-1);
    for (int i=0; i<n-1; i++) cin>>arr[i];
    approach_1(arr, n);
    approach_2(arr, n);
    approach_3(arr, n);
    
    return 0;
}