#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int A[101010];
int P[101010];
vector<int> E[101010];
ll dp[101010];
ll mo=1000000007;
int rev2=(mo+1)/2;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class TreeWalker {
	public:
	
	int calc(int N, int A0, int B, int C, int MOD) {
		int i;
		
		ZERO(dp);
		
		A[0]=A0;
		FOR(i,N) E[i].clear();
		for(i=1;i<=N-1;i++) {
			A[i] = (1LL*B*A[i-1] + C)%MOD;
			P[i]= A[i-1]%i;
			E[P[i]].push_back(i);
		}
		
		ll ret=0;
		for(i=N-1;i>=0;i--) {
			dp[i]=1;
			FORR(r,E[i]) ret += dp[i]*dp[r]%mo, (dp[i]+=dp[r])%=mo;
			dp[i] = dp[i]*rev2%mo;
			ret %= mo;
		}
		
		return ret*modpow(2,N)%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 0; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1000; int Arg5 = 34; verify_case(0, Arg5, calc(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 1; int Arg5 = 13824; verify_case(1, Arg5, calc(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 16; int Arg1 = 15; int Arg2 = 1; int Arg3 = 1; int Arg4 = 16; int Arg5 = 917506; verify_case(2, Arg5, calc(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 385498676; int Arg2 = 349131547; int Arg3 = 115776323; int Arg4 = 614879544; int Arg5 = 245566366; verify_case(3, Arg5, calc(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 100000; int Arg1 = 111222333; int Arg2 = 444555666; int Arg3 = 777888999; int Arg4 = 123456789; int Arg5 = 119729770; verify_case(4, Arg5, calc(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TreeWalker ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
