//
//  main.cpp
//  Find K-th Smallest Pair Distance
//
//  Created by Sivaprasad Tamatam on 22/09/20.
//

#include <iostream>
#include<vector>
using namespace std;
int smallestDistancePair(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());
       int l =0, r = nums.back()-nums.front();
       while(l<r){
           int m = (l+r)/2;
           int count =0;
           
           for( int i =1, j =0; i<nums.size(); ++i){
               
               while(j<i && nums[i] - nums[j] >m)
                   ++j;
               count += i-j;
               
           }
           
          
           if(count >= k)
               r = m;
           else
               l = m+1;
           
           
       }
       return l;
   
   }
int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3,6,7,10};
    int k = 8;
    cout<<smallestDistancePair(nums, k)<<endl;
    return 0;
}
