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
ll dp[205][205];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class LineMSTDiv2 {
	public:
	ll dodo(int N,int M,int L) {
		if(dp[N][M]>=0) return dp[N][M];
		if(N==1) return 1;
		if(M==0) return 0;
		
		ll ret=dodo(N,M-1,L);
		for(int x=1;x<N;x++) ret += dodo(x,M-1,L)*dodo(N-x,M,L) %mo * modpow(L-M+1,x*(N-x)-1) % mo;
		return dp[N][M] = (ret%mo);
	}
	int count(int N) {
		MINUS(dp);
		ll ret=dodo(N,2,2);
		for(int i=3;i<=N;i++) ret = ret*i%mo;
		return (int)ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 15; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arg0 = 16; int Arg1 = 682141922; verify_case(2, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LineMSTDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
