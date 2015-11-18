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

ll memo[101][55][101];
ll lmemo[101][101];
const int CN=1001;
ll C[CN][CN];

class BearPermutations {
	public:
	ll mo;
	
	ll glmemo(int N,int S) {
		
		if(lmemo[N][S]>=0) return lmemo[N][S];
		
		ll ret=0;
		for(int i=0;i<N;i++) {
			int sc=S-(1+i);
			if(sc>=0) ret+=dpdp(N,sc,i);
		}
		return lmemo[N][S]=ret%mo;
		
	}
	
	ll dpdp(int N,int S,int left) {
		if(N<=1) return S==0;
		if(left>=N/2) left=N-1-left;
		if(memo[N][left][S]>=0) return memo[N][left][S];
		
		ll ret=0;
		if(left==0) {
			for(int i=1;i<N;i++) ret+=dpdp(N-1,S,i-1);
		}
		else {
			for(int ls=0;ls<=S;ls++) (ret+=glmemo(left,ls)*glmemo(N-left-1,S-ls))%=mo;
			(ret*=C[N-1][left])%=mo;
		}
		return memo[N][left][S]=ret%mo;
	}
	
	
	int countPermutations(int N, int S, int MOD) {
		mo = MOD;
		int i,j;
		
		FOR(i,CN) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j])%mo;
		
		MINUS(lmemo);
		MINUS(memo);
		ll ret=0;
		
		FOR(i,S+1) FOR(j,N) ret+=dpdp(N,i,j) % mo;
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 71876209; int Arg3 = 4; verify_case(0, Arg3, countPermutations(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 0; int Arg2 = 1000003; int Arg3 = 8; verify_case(1, Arg3, countPermutations(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 483128897; int Arg3 = 8; verify_case(2, Arg3, countPermutations(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 907283243; int Arg3 = 82; verify_case(3, Arg3, countPermutations(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 100; int Arg2 = 101; int Arg3 = 19; verify_case(4, Arg3, countPermutations(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 20; int Arg1 = 30; int Arg2 = 3; int Arg3 = 2; verify_case(5, Arg3, countPermutations(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BearPermutations ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
