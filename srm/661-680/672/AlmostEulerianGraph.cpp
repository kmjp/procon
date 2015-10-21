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

ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

const int N_=2020;
ll C_[N_][N_];
ll E[2020];
ll D[2020];

class AlmostEulerianGraph {
	public:
	int calculateGraphs(int n) {
		int i,j,k;
		
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
		
		E[0]=D[0]=1;
		for(i=1;i<=2000;i++) {
			E[i]=D[i]=modpow(2,(i-1)*(i-2)/2);
			for(k=1;k<=i-1;k++) E[i]-=C_[i-1][k-1]*E[k]%mo*D[i-k]%mo;
			E[i]=(mo+E[i]%mo)%mo;
		}
		
		return E[n]*(1+n*(n-1)/2)%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; verify_case(0, Arg1, calculateGraphs(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 0; verify_case(1, Arg1, calculateGraphs(Arg0)); }
	void test_case_2() { int Arg0 = 42; int Arg1 = 29010676; verify_case(2, Arg1, calculateGraphs(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AlmostEulerianGraph ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
