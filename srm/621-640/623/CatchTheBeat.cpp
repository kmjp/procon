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
#include <limits>
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

class CatchTheBeat {
	public:
	template<class CC> int LIS_num(vector<CC>& v) {
		int i,N=v.size();
		vector<CC> dp(N,(numeric_limits<CC>::max)()),id(N);
		FOR(i,v.size()) dp[id[i]=lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin()] = v[i]-1;
		return *max_element(id.begin(),id.end())+1;
	}

	int maxCatched(int n, int x0, int y0, int a, int b, int c, int d, int mod1, int mod2, int offset) {
		int i;
		vector<ll> X(n,0),Y(n,0);
		vector<pair<int,ll> > P;
		X[0]=x0;
		Y[0]=y0;
		for(i=1;i<n;i++) {
			X[i]=(X[i-1]*(ll)a+b)%mod1;
			Y[i]=(Y[i-1]*(ll)c+d)%mod2;
		}
		FOR(i,n) {
			X[i]-=offset;
			if(Y[i]-X[i]<0 || X[i]+Y[i]<0) continue;
			P.push_back(make_pair(Y[i]-X[i],X[i]+Y[i]));
		}
		if(P.empty()) return 0;
		
		sort(P.begin(),P.end());
		vector<ll> V;
		ITR(it,P) V.push_back(it->second);
		return LIS_num(V);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 0; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; int Arg6 = 1; int Arg7 = 100; int Arg8 = 100; int Arg9 = 1; int Arg10 = 2; verify_case(0, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 1234; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1000000000; int Arg8 = 1000000000; int Arg9 = 1000; int Arg10 = 1; verify_case(1, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 999; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1000000000; int Arg8 = 1000000000; int Arg9 = 1000; int Arg10 = 0; verify_case(2, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 0; int Arg2 = 0; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; int Arg6 = 1; int Arg7 = 3; int Arg8 = 58585858; int Arg9 = 1; int Arg10 = 66; verify_case(3, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_4() { int Arg0 = 500000; int Arg1 = 123456; int Arg2 = 0; int Arg3 = 1; int Arg4 = 0; int Arg5 = 1; int Arg6 = 1; int Arg7 = 1000000000; int Arg8 = 1000000000; int Arg9 = 0; int Arg10 = 376544; verify_case(4, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_5() { int Arg0 = 500000; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1; int Arg8 = 1; int Arg9 = 0; int Arg10 = 500000; verify_case(5, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_6() { int Arg0 = 10; int Arg1 = 999999957; int Arg2 = 79; int Arg3 = 993948167; int Arg4 = 24597383; int Arg5 = 212151897; int Arg6 = 999940854; int Arg7 = 999999986; int Arg8 = 999940855; int Arg9 = 3404; int Arg10 = 3; verify_case(6, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  CatchTheBeat ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
