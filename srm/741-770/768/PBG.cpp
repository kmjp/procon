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

const ll mo=1000000007;
ll memo[4040][4040];
ll rc2[6060];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class PBG {
	public:
	ll hoge(int w,int l) {
		if(w==0) return 0;
		if(memo[w][l]>=0) return memo[w][l];
		ll ret=0;
		if(l==0) {
			ret=(w+hoge(w-1,l))%mo;
		}
		else {
			if(w>=2) ret+=(w*(w-1)/2)*(w+l+hoge(w-1,l))%mo;
			if(l) ret+=(w*l+l*(l-1)/2)*hoge(w,l-1)%mo;
			ret=ret*rc2[w+l]%mo;
		}
		
		return memo[w][l]=ret;
	}
	
	int findEV(int P, int B, int G) {
		int i;
		for(i=1;i<=6000;i++) rc2[i]=modpow(i*(i-1)/2);
		MINUS(memo);
		ll GW=hoge(G,P+B);
		ll GPW=hoge(G+P,B);
		
		return (mo+GPW-GW)*modpow(P)%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 0; int Arg3 = 3; verify_case(0, Arg3, findEV(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 333333338; verify_case(1, Arg3, findEV(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 0; int Arg3 = 1; verify_case(2, Arg3, findEV(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 4; int Arg3 = 672193888; verify_case(3, Arg3, findEV(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 3; int Arg3 = 333333339; verify_case(4, Arg3, findEV(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 0; int Arg3 = 1; verify_case(5, Arg3, findEV(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 2000; int Arg1 = 2000; int Arg2 = 2000; int Arg3 = 246923693; verify_case(6, Arg3, findEV(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PBG ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

