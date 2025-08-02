#include<bits/stdc++.h>
using namespace std;

//  Problem Statement: Given an array of integers arr[] and an integer target. Return indices of the two numbers such that their sum is equal to the target. Otherwise, return {-1, -1}. Note: You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

//  Link: https://leetcode.com/problems/two-sum/description/

/*
 @Approach:
 - Approach_1 : Use a nested loop and for every element find the valid pair to get the required target

 - Approach_2: The above approach is O(n²) time complexity, to optimise it we could use a map structure in which for every element we would check whether the current element's valid pair exist in it or not. If it exists, then return the solution; if not, then insert the current element with its index in the map.

 @Complexity:
 - Time: 
    - Approach_1: O(n²)
    - Approach_2: O(n) on average case, O(n*logn) in worst case

 - Space: 
    - Approach_1: O(1)
    - Approach_2: O(n) => Map used
*/

void approach_1(vector<int> arr, int k){
    pair<int, int> ans = {-1,-1};
    bool found = false;
    for (int i=0; i<arr.size(); i++){
        for (int j=i+1; j<arr.size(); j++){
            if (arr[i] + arr[j] == k) {
                ans.first = i;
                ans.second = j;
                found = true;
                break;
            }
        }
        if (found) break;
    } 
    (ans.first == -1 || ans.second == -1) ? cout<<"Solution Not exist\n" : cout<<"Target found for index "<<ans.first<<" and "<<ans.second<<"\n";
}

void approach_2(vector<int> arr, int k){
    unordered_map<int, int> req;
    pair<int, int> ans = {-1,-1};
    for (int i=0; i<arr.size(); i++){
        if (req.find(k-arr[i]) == req.end()) req[arr[i]] = i;
        else{
            ans.first = req[k-arr[i]];
            ans.second = i;
            break;
        }
    }
    (ans.first == -1 || ans.second == -1) ? cout<<"Solution Not exist\n" : cout<<"Target found for index "<<ans.first<<" and "<<ans.second<<"\n";
}

vector<int> arrayInput(){
    int s;
    cin>>s;
    vector<int> arr(s);
    for (int i=0; i<s; i++) cin>>arr[i];
    return arr;
}

int main(){
    vector<int> arr = arrayInput();
    int k;
    cin>>k;
    approach_1(arr, k);
    approach_2(arr, k);
    
    return 0;
}