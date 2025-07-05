#include<bits/stdc++.h>
using namespace std;

//  Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.

//  Link: https://leetcode.com/problems/max-consecutive-ones/description/

/*
 @Approach: Create a counter and max_counter, and then traverse the whole array, whenver got 1, then update counter, and whenver got 0, then update max_counter and also counter, at the end to handle edge case again update the max_counter
 
 @Complexity:
 - Time: O(n)
 - Space: O(1)
*/

vector<int> arrayInput(){
    int s;
    cin>>s;
    vector<int> arr(s);
    for (int i=0; i<s; i++) cin>>arr[i];
    return arr;
}

void approach_1(vector<int> arr){
    int ctr = 0;
    int max_ctr = 0;
    for (auto i : arr){
        if (i) ctr++;
        else{
            max_ctr = max(max_ctr,ctr);
            ctr = 0;
        }
    }
    max_ctr = max(max_ctr, ctr);
    cout<<"Maximum number of consecutive 1's in the array are "<<max_ctr<<endl;
}

int main(){
    vector<int> arr = arrayInput();
    approach_1(arr);
    
    
    return 0;
}