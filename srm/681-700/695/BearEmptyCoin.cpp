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

static const int N_=100;
static ll C_[N_][N_];
int yes[101];

class BearEmptyCoin {
	public:
	long long winProbability(int K, int S) {
		S=abs(S);
		if(S%K==0) return 1LL<<K;
		int i,j,x,y,z;
		
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j]);
		for(i=1;i<=K;i++) yes[i]=(__gcd(S,i)%__gcd(K,i)==0);
		
		ll ret=yes[K];
		for(j=1;j<=K-1;j++) {
			ll ret2=0;
			for(x=0;x<=K-(1+j);x++) if(yes[x+1]) ret2 = max(ret2,C_[K-(1+j)][x]);
			ret += ret2;
		}
		return ret*2;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 17; long long Arg2 = 2LL; verify_case(0, Arg2, winProbability(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = -50; long long Arg2 = 4LL; verify_case(1, Arg2, winProbability(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = -49; long long Arg2 = 2LL; verify_case(2, Arg2, winProbability(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 42; long long Arg2 = 8LL; verify_case(3, Arg2, winProbability(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = -123456789; long long Arg2 = 6LL; verify_case(4, Arg2, winProbability(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 18; int Arg1 = 123456; long long Arg2 = 49870LL; verify_case(5, Arg2, winProbability(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 60; int Arg1 = 0; long long Arg2 = 1152921504606846976LL; verify_case(6, Arg2, winProbability(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BearEmptyCoin ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
