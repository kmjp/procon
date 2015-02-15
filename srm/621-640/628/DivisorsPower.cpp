#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

class DivisorsPower {
	public:
	int enumdiv(ll n) {
		int ret=0;
		for(ll i=1;i*i<=n;i++) if(n%i==0) ret+=1+(i*i!=n);
		return ret;
	}

	long long findArgument(long long n) {
		ll mat=1LL<<60;
		double sq=sqrt(n);
		
		for(ll x=sq-3;x<=sq+3;x++) if(x>=2 && x*x==n && enumdiv(x)==2) mat=x;
		
		for(ll x=2;x<=1000000;x++) {
			ll y=x,pp=1;
			while(y*x<=n && y*x/x==y) y*=x,pp++;
			if(y!=n || pp==1) continue;
			if(pp==enumdiv(x)) mat=min(mat,x);
		}
		
		if(mat>=1LL<<60) return -1;
		return mat;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; long long Arg1 = 2LL; verify_case(0, Arg1, findArgument(Arg0)); }
	void test_case_1() { long long Arg0 = 10LL; long long Arg1 = -1LL; verify_case(1, Arg1, findArgument(Arg0)); }
	void test_case_2() { long long Arg0 = 64LL; long long Arg1 = 4LL; verify_case(2, Arg1, findArgument(Arg0)); }
	void test_case_3() { long long Arg0 = 10000LL; long long Arg1 = 10LL; verify_case(3, Arg1, findArgument(Arg0)); }
//	void test_case_4() { long long Arg0 = 2498388559757689LL; long long Arg1 = 49983883LL; verify_case(4, Arg1, findArgument(Arg0)); }
	void test_case_4() { long long Arg0 = 6756327210616080; long long Arg1 = 49983883LL; verify_case(4, Arg1, findArgument(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  DivisorsPower ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
