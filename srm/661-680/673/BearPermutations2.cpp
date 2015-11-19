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

ll memo[105][105];
ll fact[201];
const int CN=401;
ll C[CN][CN];


class BearPermutations2 {
	public:
	ll mo;
	
	ll dpdp(int N,int L) {
		
		if(N<=1) return 0;
		if(memo[N][L]>=0) return memo[N][L];
		
		int i;
		ll ret=0;
		
		if(L==0 || L==N-1) {
			FOR(i,N-1) ret+=dpdp(N-1,i);
		}
		else {
			int i;
			int R=N-L-1;
			FOR(i,L) {
				ret += (i+1)*fact[L-1] % mo * fact[R] % mo;
				ret += dpdp(L,i) * fact[R] % mo;
			}
			FOR(i,R) {
				ret += (i+1)*fact[R-1] % mo * fact[L] % mo;
				ret += dpdp(R,i) * fact[L] % mo;
			}
			ret = ret % mo * C[N-1][L];
		}
		
		
		return memo[N][L]=ret%mo;
	}
	
	int getSum(int N, int MOD) {
		mo = MOD;
		
		int i,j;
		fact[0]=1;
		FOR(i,100) fact[i+1]=fact[i]*(i+1)%mo;
		FOR(i,CN) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j])%mo;
		
		MINUS(memo);
		ll ret=0;
		FOR(i,N) ret += dpdp(N,i);
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 502739849; int Arg2 = 4; verify_case(0, Arg2, getSum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1000003; int Arg2 = 0; verify_case(1, Arg2, getSum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 973412327; int Arg2 = 38; verify_case(2, Arg2, getSum(Arg0, Arg1)); }
	//void test_case_3() { int Arg0 = 100; int Arg1 = 89; int Arg2 = 49; verify_case(3, Arg2, getSum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 973412327; int Arg2 = 2868; verify_case(3, Arg2, getSum(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BearPermutations2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
