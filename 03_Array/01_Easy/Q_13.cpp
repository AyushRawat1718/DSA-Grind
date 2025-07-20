#include<bits/stdc++.h>
using namespace std;

//  Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k. [The array could have both positive and negative elements]

//  Link: 

/*
 @Approach:
 - Approach_1: The first and most basic approach would be to generate all possible subarrays using two nested loops, and then check the sum of each subarray. If the sum matches k, we update the maximum length found so far. 
 
 - Approach_2: To optimize the above approach, we use the prefix sum technique. The intuition is that a subarray ending at index j can either start from the beginning (which can be directly calculated using prefix sum), or it can start from some index i > 0. Now, if the current prefix sum is preSum, and we want the sum of some subarray to be k, then there must exist a previous prefix sum equal to preSum - k. If we’ve seen this value before, it means that the subarray from that earlier index to the current index adds up to k. To track this, we use a map to store the earliest occurrence of each prefix sum, which helps us find the required subarray in O(n) time (on average).
 
 @Complexity:
 - Time: 
    - Approach_1: O(n²) => Nested loop traversal
    - Approach_2: O(n) => average case as using unordered_map, but worst-case can be O(n log m) due to hash collisions, m = size of map

 - Space: 
    - Approach_1: O(1)
    - Approach_2: O(n) => Map used
*/

vector<int> arrayInput(){
    int s;
    cin>>s;
    vector<int> arr(s);
    for (int i=0; i<s; i++) cin>>arr[i];
    return arr;
}

void approach_1(vector<int> arr, int k){
    int len = 0;
    int sum = 0;
    for (int i=0; i<arr.size(); i++){
        sum = 0;
        for (int j=i; j<arr.size(); j++){
            sum += arr[j];
            if (sum == k) {
                len = max(len, j-i+1);
            }
        
        }
    }
    (len == 0) ? cout<<"No Valid subarray with sum "<<k<<"\n" :cout<<"Length of longest subarray with sum "<<k<<" is: "<<len<<"\n"; 
}

void approach_2(vector<int> arr, int k){
    unordered_map<int, int> prefixSumIndex;
    int sum = 0;
    int len = 0;
    for (int i=0; i<arr.size(); i++){
        sum += arr[i];
        if (prefixSumIndex.find(sum) == prefixSumIndex.end()) prefixSumIndex.insert({sum, i});
        if (sum == k) len = max(len, i+1);
        if (prefixSumIndex.find(sum - k) != prefixSumIndex.end()) len = max(len, i-prefixSumIndex[sum-k]);
    }
    (len == 0) ? cout<<"No Valid subarray with sum "<<k<<"\n": cout<<"Length of longest subarray with sum "<<k<<" is: "<<len<<"\n";

}


int main(){
    vector<int> arr = arrayInput();
    int k;
    cin>>k;    
    approach_1(arr, k);
    approach_2(arr, k);
    return 0;
}