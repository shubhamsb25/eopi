#include<bits/stdc++.h>
using namespace std;

void EvenOdd(vector<int> nums){
    int nextEven=0;
    int nextOdd=nums.size()-1;
    int current=0;

    while(nextEven<nextOdd){
        if(nums[nextEven]%2==0){
            nextEven++;
        }
        else{
            swap(nums[nextEven],nums[nextOdd]);
            nextOdd--;
        }
    }

    for(auto i:nums){
        cout<<i<<" ";
    }
    cout<<endl;
    
}

int main(){
    vector<int> nums={1,2,3,4,5,6,7,8,9};
    EvenOdd(nums);
    return 0;
}