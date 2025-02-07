#include <vector>
#include <iostream>

using namespace std;

const int MAX_N = 100 + 1;
const int MAX_V = 200 + 1;

class Solution {

    bool dp(int i,int sum,int n,int target,const vector<int> &v,vector<vector<int>> &mem){
        if(sum > target)
            return 0;
        if(sum == target)
            return 1;
        if(i >= n)
            return 0;
    
        if(mem[i][sum] != -1)
            return mem[i][sum];
        
        int pick_it = dp(i+1,sum+v[i],n,target,v,mem) 
           ,leave_it = dp(i+1,sum,n,target,v,mem);

        return mem[i][sum] = (pick_it || leave_it);
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums) {
            sum += num;
        }   
        if(sum&1)
            return 0;
        
        int target = sum/2;
        vector<vector<int>> mem((int)nums.size()+1,vector<int>(target+1,-1));

        return dp(0,0,nums.size(),target,nums,mem);
    }
};

void test(const vector<int> &v){

    
}

int main(){


}
