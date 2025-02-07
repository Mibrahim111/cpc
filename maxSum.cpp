#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

const int MAXN = 500 + 1;
const int MAXT = 2000 + 1;

int mem[MAXN][MAXT];
bool flag = 0;

bool dp(int i,int n,int sum,int target,const vector<int>& values){
    if(sum > target)
        return 0;

    if(i == n)
        return 0;

    if(sum == target)
        return 1;

    auto &ret = mem[i][sum];
    if(ret != -1)
        return ret;
    
   bool  take_it = dp(i+1,n,sum+values[i],target,values),
         leave_it = dp(i+1,n,sum,target,values);

    return ret = (take_it || leave_it);
}

bool subset_sum(const vector<int> &values, int target)
{
    int n = (int)values.size();
    memset(mem,-1,sizeof(mem));

    vector<bool> dp(target + 1,0);
    dp[0] = 1;
   
   for(int i = 0;i < n;i++){
        for(int j = target;j >= values[i];j--){
            dp[j] = dp[j] || dp[j - values[i]];
        }
   }

    return dp[target];

}


void process_case(const vector<int> &values, int target, bool expected) {
    
	bool answer = subset_sum(values, target);

	if (answer != expected) {
		cout << "Wrong results: \t";
		for (int i = 0; i < (int) values.size(); ++i)
			cout << values[i] << " ";

		cout << "\tWith target: " << target<<"\n\n";
	}
}

int main(){
  int big = 1e8;
	process_case( { 3, 12, 4, 12, 5, 2 }, 9, true);
	process_case( { 3, 40, 4, 12, 5, 2 }, 30, false);
	process_case( { 10, 20, 30, 40, 50 }, 60, true);
	process_case( { 10, 20, 30, 40, 50 }, 100, true);
	process_case( { 10, 20, 30, 40, 50 }, 90, true);
	process_case( { 10, 20, 30, 40, 50 }, 70, true);
	process_case( { 10, 20, 30, 40, 50 }, 200, false);
	process_case( { 200 }, 300, false);
	process_case( { 200 }, 200, true);
	process_case( { big, big, big, big, big }, 60, false);
	process_case( { 1, 2, 3}, 6, true);

	cout<<"Done\n";
  
}
