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

ll dp[601][601][50];
ll mo=1000000007;
ll r100;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class HockeyPlayoff {
	public:
	int AW,BW,W;
	ll hoge(int A,int B,int T) {
		if(A==W||T==20) return 1;
		if(B==W||T==-20) return 0;
		if(dp[A][B][T+25]>=0) return dp[A][B][T+25];
		
		int awin;
		if((A+B)%4<2) awin=AW;
		else awin=100-BW;
		awin=min(100,max(0,awin+T*5));
		
		ll ret=0;
		dp[A][B][T+25]=0;
		if(awin) ret+=awin*hoge(A+1,B,min(20,max(0,T)+1));
		if(awin<100) ret+=(100-awin)*hoge(A,B+1,max(-20,min(0,T)-1));
		ret=ret%mo*r100%mo;
		
		return dp[A][B][T+25]=ret;
	}
	
	int winProbability(int winsNeeded, int AwinHome, int BwinHome) {
		AW=AwinHome;
		BW=BwinHome;
		W=winsNeeded;
		MINUS(dp);
		r100=modpow(100);
		
		ll ret=hoge(0,0,0);
		int i;
		FOR(i,2*W-1) ret=ret*100%mo;
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 100; int Arg3 = 0; verify_case(0, Arg3, winProbability(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 100; int Arg2 = 0; int Arg3 = 999300007; verify_case(1, Arg3, winProbability(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 600; int Arg1 = 50; int Arg2 = 50; int Arg3 = 594375906; verify_case(2, Arg3, winProbability(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 53; int Arg2 = 57; int Arg3 = 942200194; verify_case(3, Arg3, winProbability(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 7; int Arg1 = 93; int Arg2 = 87; int Arg3 = 545426737; verify_case(4, Arg3, winProbability(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  HockeyPlayoff ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

