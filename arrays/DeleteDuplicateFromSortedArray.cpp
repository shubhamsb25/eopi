#include<bits/stdc++.h>
using namespace std;

/*
Approaches: 
1. Easy way out

    Create new Array
    On new Element (we know it is new because of sortedness) 
        copy element to new array
    If duplicate (we can check the last element of new array) 
        do nothing

    =========================================================

    Time complexity: O(n)
    Space complexity: O(n) (coz of new array)

2. In place (Dividing array into two parts, i.e Non duplicate and incoming raw elements)

    Traverse whole array
    keep track of last index of non duplicate part of array
    when whole array is traversed we can use this index to create new array with only unique elements from original array

    =========================================================

    Time complexity: O(n)
    Space complexity: O(1) coz we didn't use any extra space to find out unique elements
*/

int removeDuplicateFromSortedArray(vector<int> &ar){
    int newEmptyIndex=1;
    for (int i = 1; i < ar.size(); i++)
    {
        //check if last non duplicate element is same or different than new element
        if(ar[newEmptyIndex-1]!=ar[i]){
            swap(ar[i],ar[newEmptyIndex]);
            newEmptyIndex++;
        }
    }
    return newEmptyIndex-1;  //last known index of unique element part of array
}

int main(){
    vector<int> nums={1,1,1,1,2,3,3,3,3,3,3,4,5,5,5,5,5,6,7,8,8,9,9,10};
    int lastIndex=removeDuplicateFromSortedArray(nums);
    for (int i = 0; i <= lastIndex; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}