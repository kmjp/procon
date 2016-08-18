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

ll A[202020];
ll mo=1000000007;

class XorOrderDiv1 {
	public:
	pair<ll,ll> dfs(int cur,int L,int R,int d,int X,int Y) {
		if(d<0) return {0,0};
		int X2 = (X+Y)/2;
		int M = lower_bound(A+L,A+R,X2)-A;
		
		pair<ll,ll> r;
		ll num;
		if(cur<X2) {
			num = R-M;
			r = dfs(cur,L,M,d-1,X,X2);
		}
		else {
			num = M-L;
			r = dfs(cur,M,R,d-1,X2,Y);
		}
		r.second = (2*r.second + 2*num*r.first +  ((num*num%mo)<<(d)))%mo;
		r.first = (2*r.first + (num<<(d)))%mo;
		return r;
	}
	
	int get(int m, int n, int a0, int b) {
		int i;
		FOR(i,n) A[i] = (a0 + 1LL*i*b) & ((1<<m)-1);
		sort(A,A+n);
		
		ll ret=0;
		FOR(i,n) ret ^= dfs(A[i],0,n,m-1,0,1<<m).second;
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 0; int Arg3 = 1; int Arg4 = 8; verify_case(0, Arg4, get(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 1; int Arg3 = 3; int Arg4 = 48; verify_case(1, Arg4, get(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 16; int Arg1 = 100; int Arg2 = 41; int Arg3 = 5; int Arg4 = 523436032; verify_case(2, Arg4, get(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 30; int Arg1 = 200000; int Arg2 = 399; int Arg3 = 18082016; int Arg4 = 408585698; verify_case(3, Arg4, get(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  XorOrderDiv1 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
