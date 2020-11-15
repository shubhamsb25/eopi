#include<bits/stdc++.h>
using namespace std;

/*
 time complexity: O(n) 
 space complexity: O(1)
*/
bool CanReachEnd(vector<int> reachability){
    int destinationIndex=reachability.size()-1;
    int currMaximumReach=-1;
    for (int i = 0; i < reachability.size(); i++)
    {
        currMaximumReach=max(currMaximumReach,i+reachability[i]);
        if(currMaximumReach>=destinationIndex){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> nums={2,4,1,1,0,2,3};
    bool isEndReachable=CanReachEnd(nums);
    cout<<(isEndReachable? "Possible":"Not Possible")<<endl;

    vector<int> nums1={3,3,1,0,2,0,1};
    bool isEndReachable1=CanReachEnd(nums1);
    cout<<(isEndReachable1? "Possible":"Not Possible")<<endl;
    return 0;
}