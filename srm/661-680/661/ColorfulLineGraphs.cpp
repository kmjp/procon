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

int pre[1010101];
ll tot[1010101];
ll tmul[1010101];
ll modpow(ll a, ll n,int mo) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class ColorfulLineGraphs {
	public:
	int countWays(long long N, long long K, int M) {
		ll ret=1,mul=1,i;
		
		MINUS(pre);
		for(i=1;i<=N;i++) {
			ll pm=mul;
			(mul+=(K-1))%=M;
			ret=ret*mul%M;
			if(pre[mul]>=0) break;
			pre[mul]=i;
			tot[mul]=pm;
		}
		
		if(i>N) return ret;
		
		ll st=pre[mul], period=i-pre[mul];
		
		ll t=1;
		FOR(i,period) {
			tmul[i]=t;
			t=t*mul%M;
			(mul+=(K-1))%=M;
		}
		
		ret=tot[mul]*modpow(t,(N-(st-1))/period,M)%M;
		ret=ret*tmul[(N-(st-1))%period]%M;
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 3LL; long long Arg1 = 2LL; int Arg2 = 100000; int Arg3 = 24; verify_case(0, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 15LL; long long Arg1 = 3LL; int Arg2 = 1000000; int Arg3 = 510625; verify_case(1, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 100000LL; long long Arg1 = 100000LL; int Arg2 = 999999; int Arg3 = 185185; verify_case(2, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 1000000000000LL; long long Arg1 = 6LL; int Arg2 = 1000000; int Arg3 = 109376; verify_case(3, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 5000LL; long long Arg1 = 1000000000000LL; int Arg2 = 314159; int Arg3 = 202996; verify_case(4, Arg3, countWays(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ColorfulLineGraphs ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
