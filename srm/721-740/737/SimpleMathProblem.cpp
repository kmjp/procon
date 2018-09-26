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

class SimpleMathProblem {
	public:
	ll modpow(ll a, ll n,ll mo) {
		ll r=1;a%=mo;
		while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
		return r;
	}
	int totient(int v) {
		int ret=v;
		for(int i=2;i*i<=v;i++) if(v%i==0) {
			ret=ret/i*(i-1);
			while(v%i==0) v/=i;
		}
		if(v>1) ret=ret/v*(v-1);
		return ret;
	}
	ll hoge(ll a,ll b,ll c,ll m) {
		int num=0;
		ll g=1;
		while(m%a==0) {
			m/=a;
			g*=a;
			num++;
		}
		if(m==1) return 0;
		if(m==2) return 1;
		int p=totient(m);
		ll t=modpow(b,c,p)+num*(p-1);
		
		return modpow(a,t,m)*g;
	}
	
	
	int calculate(int a, int b, int c, int m) {
		a %= m;
		if(m==1 || a==0) return 0;
		
		ll ret=1;
		if(log(b)*c<log(60)) {
			ll p=1;
			int i;
			FOR(i,c) p*=b;
			FOR(i,p) ret=ret*a%m;
		}
		else {
			for(int i=2;i*i<=a;i++) while(a%i==0) {
				ret=ret*hoge(i,b,c,m)%m;
				a/=i;
			}
			if(a>1) ret=ret*hoge(a,b,c,m)%m;
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 737; int Arg4 = 1; verify_case(0, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 7; int Arg2 = 3; int Arg3 = 123456789; int Arg4 = 63564408; verify_case(1, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 12; int Arg1 = 34; int Arg2 = 56; int Arg3 = 78; int Arg4 = 66; verify_case(2, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3737373; int Arg1 = 7373737; int Arg2 = 37373; int Arg3 = 737373737; int Arg4 = 214080347; verify_case(3, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 10; int Arg3 = 1024; int Arg4 = 0; verify_case(4, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 47; int Arg1 = 53; int Arg2 = 912; int Arg3 = 1; int Arg4 = 0; verify_case(5, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SimpleMathProblem ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

