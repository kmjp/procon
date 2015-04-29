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

class PolynomialRemainder {
	public:
	int calc(ll a,ll b,ll c,ll m) {
		int i;
		for(i=0;i<m;i++) if((a*i%m*i+b*i+c)%m==0) return i;
		return -1;
	}
	
	int findRoot(int a, int b, int c) {
		ll p29=2*2*2*2*2*2*2*2*2;
		ll p59=5*5*5*5*5*5*5*5*5;
		ll p2=calc(a,b,c,p29);
		ll p5=calc(a,b,c,p59);
		
		if(p2==-1 || p5==-1) return -1;
		while(p5 % p29 != p2) p5+=p59;
		return p5;
	}
	/* alternative solution */
	int findRoot(int a, int b, int c) {
		ll mo=1000000000;
		int i;
		ll A=a, B=b, C=c;
		for(ll i=0;i<1000000;i++) {
			ll c=(i*i%mo*A + B*i + C)%mo;
			if(c%1000000) continue;
			for(ll j=i;j<mo;j+=1000000) if((j*j%mo*A + B*j + C)%mo==0) return j;
		}
		return -1;
	}
	*/
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; verify_case(0, Arg3, findRoot(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 1; int Arg3 = -1; verify_case(1, Arg3, findRoot(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 3; int Arg3 = -1; verify_case(2, Arg3, findRoot(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 123456000; int Arg1 = 789012345; int Arg2 = 678901230; int Arg3 = 121618466; verify_case(3, Arg3, findRoot(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 479659453; int Arg1 = 928595613; int Arg2 = 143451144; int Arg3 = 647373336; verify_case(4, Arg3, findRoot(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PolynomialRemainder ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
