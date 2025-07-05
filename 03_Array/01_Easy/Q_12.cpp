#include<bits/stdc++.h>
using namespace std;

//  Problem Statement: Find the number that appears once, and the other numbers twice

//  Link: https://leetcode.com/problems/single-number/description/

/*
 @Approach:
 - Approach_1: We could perform hashing using map instead of array, as it would be more relevant
 
 - Approach_2: Use the concept of XOR, i.e a^a = 0 and a^0 = a, traverse in the whole array and xor all the elements, The numbers that appear twice will cancel each other using XOR (a^a = 0), and we’ll be left with the one that appears only once.

 @Complexity:
 - Time: 
    - Approach_1: O(N*logM) + O(M)=>Traversing the array and inserting in map, and then traversing map, m is the size of map
    - Approach_2: O(n)
 - Space: 
    - Approach_1: O(m) => m is the size of map, m would be approx (n/2) + 1
    - Approach_2: O(1)
*/

vector<int> arrayInput(){
    int s;
    cin>>s;
    vector<int> arr(s);
    for (int i=0; i<s; i++) cin>>arr[i];
    return arr;
}

void approach_1(vector<int> &arr){
    map<int, int> mp;
    for (auto i : arr) mp[i]++;
    for (auto i : mp){
        if (i.second == 1) {
            cout<<"Single Appearing number is "<<i.first<<endl;
            return;
        }
    }
}

void approach_2(vector<int> &arr){
    int ans = 0;
    for (auto i : arr) ans ^= i;
    cout<<"Single Appearing number is "<<ans<<endl;
}

int main(){
    vector<int> arr = arrayInput();
    approach_1(arr);
    approach_2(arr);
    
    return 0;
}