#include<bits/stdc++.h>
using namespace std;

//  Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k. [The array would have only positive elements] 

//  Link: 

/*
 @Approach: The first two approaches used earlier (brute force and prefix sum with map) still work here, but since the array contains only positive elements, we can optimize it further. The idea is based on the sliding window (or two pointer) technique. 

 We initialize two pointers left and right and a variable to store the current sum. Initially, both pointers are at the beginning of the array. We keep expanding the right pointer and keep adding elements to the current sum. If at any point the sum becomes greater than k, we move the left pointer to the right (shrinking the window) and subtract from the current sum. Since all elements are positive, once the sum exceeds k, the only way to reduce it is by shrinking the window. Whenever the current sum equals k, we check and update the maximum length.

 This approach works in linear time because each element is added and removed from the sum at most once.

 @Complexity:
 - Time: 
    - O(n) => Each element is visited at most twice (once by right, once by left)
 - Space: 
    - O(1) => Constant extra space used
*/

vector<int> arrayInput(){
    int s;
    cin>>s;
    vector<int> arr(s);
    for (int i=0; i<s; i++) cin>>arr[i];
    return arr;
}

void approach(vector<int> arr, int k){
    int left = 0;
    int right = 0;
    int sum = arr[0];
    int len = 0;
    while (right < arr.size()){
        while(sum > k && left <= right){
            sum -= arr[left];
            left++;
        }
        if (sum == k) len = max(len, right - left + 1);
        right++;
        if (right < arr.size()) sum += arr[right];
    }
    (len == 0) ? cout<<"No Valid subarray with sum "<<k<<"\n" :cout<<"Length of longest subarray with sum "<<k<<" is: "<<len<<"\n";

}

int main(){
    vector<int> arr = arrayInput();
    int k;
    cin>>k;    
    approach(arr, k);
    return 0;
}