//
//  main.cpp
//  Find K-th Smallest Pair Distance
//
//  Created by Sivaprasad Tamatam on 22/09/20.
//

#include <iostream>
#include<vector>
using namespace std;
int pair_less_than_or_equal(const vector<int>& nums, int m){
       int count =0;
       for( int i =1, j =0; i<nums.size(); ++i){
           cout<<"---"<<i<<endl;
           while(j<i && nums[i] - nums[j] >m)
               ++j;
           count += i-j;
       }
       return count;
   }
   int smallestDistancePair(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());
       int l =0, r = nums.back()-nums.front();
       
       cout<<l<<"   "<<r<<endl;
       while(l<r){
           int m = (l+r)/2;
           cout<<m<<endl;
           if(pair_less_than_or_equal(nums, m) >= k)
               r = m;
           else
               l = m+1;
       }
       return l;
   
   }
int smallestDistancePair1(vector<int>& nums, int k) {
        int min =0;
        int max = 10;
        vector<int> count(max);
        int n = nums.size();
        
        for( int i =0; i<n; ++i){
            for( int j = i+1; j<n; ++j){
                ++count[abs(nums[i] - nums[j])];
            }
        }
        int sum =0;
        for( int i =0; i<max; i++){
            sum += count[i];
            
            if(sum>= k){
                return i;
            }
        }
        return -1;
    }
int main(int argc, const char * argv[]) {
    vector<int> nums = {1,3,1};
    int k = 2;
    cout<<smallestDistancePair1(nums, k)<<endl;
    return 0;
}
