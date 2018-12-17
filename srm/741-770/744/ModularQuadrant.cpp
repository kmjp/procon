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

class ModularQuadrant {
	public:
	ll sq(ll a) {
		ll ret=0;
		
		if(a%3==1) ret+=(2*a+1), a--;
		if(a%3==0) a--;
		if(a>0) ret+=(a+1)*(a+1)+4*(a+1)/3;
		return ret;
		
	}
	ll hoge(ll a,ll b) {
		if(a<0 || b<0) return 0;
		if(a<b) swap(a,b);
		ll ret=0;
		
		while(a>b && (a-b)%3) ret+=(a%3)*1LL*(b+1), a--;
		ret+=(a-b)*(b+1);
		return ret+sq(b);
	}
	
	long long sum(int r1, int r2, int c1, int c2) {
		return hoge(r2,c2)-hoge(r2,c1-1)-hoge(r1-1,c2)+hoge(r1-1,c1-1);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 2; int Arg2 = 1; int Arg3 = 4; long long Arg4 = 13LL; verify_case(0, Arg4, sum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 0; int Arg3 = 7; long long Arg4 = 10LL; verify_case(1, Arg4, sum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 8; int Arg2 = 0; int Arg3 = 5; long long Arg4 = 37LL; verify_case(2, Arg4, sum(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ModularQuadrant ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

