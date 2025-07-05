#include<bits/stdc++.h>
using namespace std;

//  Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays. The union of two arrays can be defined as the common and distinct elements in the two arrays

//  Link: 

/*
 @Approach:
 - Approach_1: Use a set to store all elements from both arrays. Since a set only keeps unique elements and maintains sorted order, we simply insert elements from both arrays one by one. In the end, the set will contain the union of both arrays. However, this approach is not the most efficient, as inserting into a set takes extra time which is not efficient.

 - Approach_2: The new approach is to use two pointer approach one pointer each for both arrays, and an empty array for the union of both, and then keep on comparing while entering the elements in the array and make sure the order is maintained along with the uniqueness of the elements in union, at the end enter all the remaining elements of array.
 
 @Complexity:
 - Time: 
    - Approach_1: Insertion in set takes O(logn) time, n is total number of elements, So here O((n*log(m+n))) + O(m*log(m+n)) => O((n+m)*log(m+n))

    - Approach_2: O(m+n) => Traversing both array once
 - Space: 
    - Approach_1: O(m+n)
    - Approach_2: O(m+n)
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

void approach_1(vector<int>& arr1, vector<int>& arr2){
    set<int> st;
    for (auto i : arr1) st.insert(i);
    for (auto i : arr2) st.insert(i);
    vector<int> res;
    for (auto i : st) res.push_back(i);
    printArray(res);
}

void approach_2(vector<int>& arr1, vector<int>& arr2){
    int p1 = 0;
    int p2 = 0;
    vector<int> res;
    while (p1 < arr1.size() && p2 < arr2.size()){
        if (arr1[p1] <= arr2[p2]){
            if (res.empty() || res.back() != arr1[p1]) res.push_back(arr1[p1]);
            p1++;
        }
        else{
            if (res.empty() || res.back() != arr2[p2]) res.push_back(arr2[p2]);
            p2++;
        }
    }

    while(p1 < arr1.size()){
        if (res.empty() || res.back() != arr1[p1]) res.push_back(arr1[p1]);
        p1++; 
    }
    
    while(p2 < arr2.size()){
        if (res.empty() || res.back() != arr2[p2]) res.push_back(arr2[p2]);
        p2++; 
    }

    printArray(res);
}

int main(){
    vector<int> arr1 = arrayInput();
    vector<int> arr2 = arrayInput();
    approach_2(arr1, arr2);

    return 0;
}