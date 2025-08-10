/*
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.
*/

// solution 
/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //brute force
        // int n =  nums.size();
        // int sum =INT_MIN;
        // int curr_sum = 1;
        // if(n==1) return nums[0];
        // for(int i =0; i<n;i++){
        //     for(int j = i;j<n;j++){
        //         curr_sum*=nums[j];
        //         sum = max(sum,curr_sum);
        //     }
        //     curr_sum =1;
        // }
        // return sum;


        // prefix and suffix method  // one more method is there but that is not intutive
        

    int n = nums.size();
    int pre= 1;
    int suff = 1;
    int anser =  INT_MIN;
    for(int i = 0 ; i<n;i++){
        pre*=nums[i];
        suff*=nums[n-1-i];
        anser =  max(anser, max(pre, suff));
        if(suff==0) suff =1;
        if(pre==0) pre =1;
       
    }
    return anser;
       
    }
};

*/