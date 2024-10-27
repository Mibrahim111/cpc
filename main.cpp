#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef vector <vector<int>> vvi;
typedef vector <bool> vb;

#define  pb  push_back
#define  mp  make_pair
#define sz(x) (int)x.size()
#define lp(i,k,n) for(int i = k; i < n ; i++)
#define rlp(i,n) for(int i = n-1 ; i>=0 ;i--)
#define rep(i,x) for(int i = 0; (int)i < sz(x); i++)
#define clr(v,d) memset(v,d,sizeof(v))
#define all(x) x.begin() , x.end()
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
constexpr auto pi = 3.14159265358979323846264338327950288419716939937510;

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}
long long lcm(long long a, long long b) {
	return (a * b / gcd(a, b));
}

constexpr auto N = 540000;
constexpr auto OO = (ll)0x3f3f3f3f;
const  double EPS = 1e-8;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };



int main() {
	FAST

	ll n , k , ans=0;
	cin>>n>>k;
	vector<long long> a(n) , b(n);

	lp(i,0,n)
	cin>>a[i];

	lp(i,0,n)
	cin>>b[i];

	ll l = 0 , r = 2000000000;

	while(l<=r)
    {
        ll mid = l+(r-l)/2;
        ll kk = k , i;
        for(i = 0;i<n;i++)
        {
            if(mid*a[i]>b[i])
                kk-=(mid*a[i]-b[i]);
             if(kk<0)
             break;
        }
        if(i==n)
        {
            l = mid+1;
            ans = max(mid,ans);
        } else{
          r = mid-1;

        }
    }

	cout << ans << '\n';

//	system("pause");
	return 0;
}
