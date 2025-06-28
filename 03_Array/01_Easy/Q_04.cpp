#include<bits/stdc++.h>
using namespace std;

//  Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.

// If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.

// At the end, your target is to return the number of unique elements, and update the original array such that, first there are k unique elements and after that any (array.siz() - k) elements, that means any number could come in these places

//  Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

/*
 @Approach:
 - Approach_1: The goal is to count unique elements and update the original array in-place. We use a `set` to automatically filter out duplicates since it only stores unique values. After collecting the unique elements in the set, we overwrite the original array from the beginning using these values. Any remaining positions in the array can be ignored, as their content doesn't matter per the problem statement.

 - Approach_2: The previous approach had a time complexity of O(n log n) due to set insertions and an additional O(n) for array updates, along with O(n) space usage. To optimize, we now use a two-pointer technique. The first pointer keeps track of the last unique element placed, while the second pointer scans the array for the next distinct element. This method allows us to update the array in-place in a single pass, with constant space.

 @Complexity:
 - Time:
   - Approach 1: O(n log n)
   - Approach 2: O(n)
 - Space:
   - Approach 1: O(n)
   - Approach 2: O(1)
*/


//Using set
int approach_1(vector<int> &arr){
    set<int> st;
    for (auto i : arr) st.insert(i);
    int index = 0;
    for (auto i : st){
        arr[index++] = i;
    }
    return st.size();
}

// Using two pointer approach
int approach_2(vector<int> &arr){
    if (arr.empty()) return 0;
    int p1 = 0;
    for (int p2 = 1; p2 < arr.size(); ++p2) {
        if (arr[p2] != arr[p1]) {
            arr[++p1] = arr[p2];
        }
    }
    return p1 + 1;
}

void printArray(vector<int> arr){
    cout<<"Array: ";
    for (auto i:arr) cout<<i<<"  ";
    cout<<endl;
}

int main(){
    vector<int> arr = {0,0,1,1,1,2,2,3,3,4};
    cout<<"Before Updation\n";
    printArray(arr);
    cout<<"After Updation\n";
    cout<<"Unique Elements -> "<<approach_1(arr)<<endl;
    printArray(arr);
    return 0;
}