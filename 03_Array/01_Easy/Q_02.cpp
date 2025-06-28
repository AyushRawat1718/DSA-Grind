#include<bits/stdc++.h>
using namespace std;

//  Problem Statement: Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.

//  Link: 

/*
 @Approach: 
 - Approach 1: First of all if the size of the array is less than 2, then defenitely second largest and second smallest can't exist, so first we will check that, after that if we assume that there are no duplicate then we can sort the array and the second element would be the second smallest element and the second last element would be the second largest element
 
 - Approach 2: The above approach took O(nlogn) time complexity and it only worked for the array with no duplicate, so now we would traverse the whole array and find the largest and the smallest element [but before that is size is less than 2 then return case]. Once we got the largest and smallest then we would traverse again and this time find the element that are the largest/smallest in the array but smaller/larger than the largest/smallest element to get the second largest and second smallest element.

 - Approach 3: The second approach is good, but in that we are traversing the array twice, now in this we would traverse once to get the correct answer

 @Complexity:
 - Time: 
   - Approach 1: O(n log n)
   - Approach 2: O(n)
   - Approach 3: O(n)
 - Space: O(1) for all 
*/

pair<int, int> approach_1(vector<int> arr){
    if (arr.size() < 2) return {-1,-1};
    sort(arr.begin(), arr.end());
    int sec_lar = arr[arr.size()-2];
    int sec_small = arr[1];
    return {sec_small, sec_lar};
}

pair<int, int> approach_2(vector<int> arr){
    if (arr.size() < 2) return {-1,-1};
    int largest = INT_MIN;
    int smallest = INT_MAX;
    for (auto i : arr){
        if (i > largest) largest = i;
        if (i < smallest) smallest = i;
    }
    int sec_lar = INT_MIN;
    int sec_small = INT_MAX;
    for (auto i : arr){
        if (i < largest && i > sec_lar) sec_lar = i;
        if (i > smallest && i < sec_small) sec_small = i;
    }
    sec_lar = (sec_lar == INT_MIN) ? -1 : sec_lar;
    sec_small = (sec_small == INT_MAX) ? -1 : sec_small;
    return {sec_small, sec_lar};
}

pair<int, int> approach_3(vector<int> arr){
    if (arr.size() < 2) return {-1,-1};
    int largest, smallest, sec_lar, sec_small;
    largest = INT_MIN;
    sec_lar = INT_MIN;
    smallest = INT_MAX;
    sec_small = INT_MAX;

    for (auto i : arr){
        if (i > largest) {
            sec_lar = largest;
            largest = i;
        } else if (i != largest && i > sec_lar) {
            sec_lar = i;
        }

        if (i < smallest) {
            sec_small = smallest;
            smallest = i;
        } else if (i != smallest && i < sec_small) {
            sec_small = i;
        }
    }

    sec_small = (sec_small == INT_MAX) ? -1 : sec_small;
    sec_lar = (sec_lar == INT_MIN) ? -1 : sec_lar;

    return {sec_small, sec_lar};
}

int main() {
    vector<int> arr = {5,5,5,5, 1};
    
    auto res1 = approach_1(arr);
    auto res2 = approach_2(arr);
    auto res3 = approach_3(arr);

    cout << "Approach 1 -> Second Smallest: " << res1.first << ", Second Largest: " << res1.second << endl;
    cout << "Approach 2 -> Second Smallest: " << res2.first << ", Second Largest: " << res2.second << endl;
    cout << "Approach 3 -> Second Smallest: " << res3.first << ", Second Largest: " << res3.second << endl;

    return 0;
}
