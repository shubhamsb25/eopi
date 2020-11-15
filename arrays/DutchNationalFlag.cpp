#include<bits/stdc++.h>
using namespace std;
//Dutch national flag problem partitions array based on a pivot element

void PartitionWithTwoPass(vector<int> ar,int pivotIndex){
    int size=ar.size();
    int pivotElement=ar[pivotIndex];
    //Pass 1: push smaller elements to start
    int nextSmall=0;
    int nextBig=size-1;
    for (int i = 0; i < size; i++)
    {
        if(ar[i]<pivotElement){
            swap(ar[nextSmall],ar[i]);
            nextSmall++;
        }
    }
    //Pass 2: Push elements larger than pivot to end
    while(nextSmall<nextBig){
        if(ar[nextSmall]>pivotElement){
            swap(ar[nextBig],ar[nextSmall]);
            nextBig--;
        }else 
        {
            nextSmall++;
        }
    }
    for(auto i:ar){
        cout<<i<<" ";
    }
    cout<<endl;
}

void PartitionWithOnePass(vector<int> ar,int pivotIndex){
    int size=ar.size();
    int pivotElement=ar[pivotIndex];
    int smaller=0;
    int equal=0;
    int bigger=size-1;
    while(equal<bigger){
        if(ar[equal]<pivotElement){
            swap(ar[equal],ar[smaller]);
            equal++;
            smaller++;
        }
        else if (ar[equal]==pivotElement){
            equal++;
        }
        else{
            swap(ar[bigger],ar[equal]);
            bigger--;
        }
    }
    for(auto i:ar){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> nums={2,2,2,1,1,1,0,1,0,1,1,2,2,0,1,2,0,2,1,1,2,2,2,2,1,1,1,1,1,1,0,0,0,0,0,0,0};
    int pivotIndex=3;
    PartitionWithTwoPass(nums,pivotIndex);
    PartitionWithOnePass(nums,pivotIndex);
    return 0;
}