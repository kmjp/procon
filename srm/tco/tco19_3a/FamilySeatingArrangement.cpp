#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll dp[1010][1010];
ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class FamilySeatingArrangement {
	public:
	int countWays(vector <int> a, int k) {
		int N=a.size();
		ZERO(dp);
		int i,j;
		dp[0][0]=1;
		FOR(i,N) {
			FOR(j,N) {
				(dp[i+1][j]+=dp[i][j]*j)%=mo;
				if(j<k) (dp[i+1][j+1]+=dp[i][j]*(k-j))%=mo;
			}
		}
		
		ll ret=0;
		for(i=1;i<=k;i++) {
			int ok=1+(k-i);
			ll pat=dp[N][i];
			FOR(j,N) (pat*=modpow(ok,a[j]))%=mo;
			ret+=pat;
		}
		return ret%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,1}	; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 18; verify_case(0, Arg2, countWays(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 129; verify_case(1, Arg2, countWays(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 989021965; verify_case(2, Arg2, countWays(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 604306839; verify_case(3, Arg2, countWays(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}	; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 211; int Arg2 = 775937801; verify_case(4, Arg2, countWays(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FamilySeatingArrangement ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

