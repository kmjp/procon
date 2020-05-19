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

class SuffixDecomposition {
	public:
	long long findTotalFun(vector <int> P, int A0, int X, int Y, int B0, int X1, int Y1, int N) {
		vector<ll> A,B,S;
		A.push_back(A0);
		B.push_back(B0);
		while(A.size()<N) {
			A.push_back((A.back()*X+Y)%1812447359);
			B.push_back((B.back()*X1+Y1)%1812447359);
		}
		FORR(p,P) S.push_back(p);
		while(S.size()<N) S.push_back(max(A[S.size()],B[S.size()]));
		reverse(ALL(S));
		ll ret=0;
		vector<pair<ll,ll>> C;
		C.push_back({1LL<<40,1LL<<40});
		FORR(s,S) {
			ll L=s,R=s;
			while(C.back().first<=R) {
				L=min(L,C.back().first);
				R=max(R,C.back().second);
				C.pop_back();
			}
			C.push_back({L,R});
			
			ret+=C.size()-1;
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 9, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 3; long long Arg8 = 4LL; verify_case(0, Arg8, findTotalFun(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_1() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 2; int Arg4 = 3; int Arg5 = 1; int Arg6 = 2; int Arg7 = 4; long long Arg8 = 8LL; verify_case(1, Arg8, findTotalFun(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_2() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000001; int Arg2 = 1000001; int Arg3 = 1000001; int Arg4 = 5000001; int Arg5 = 5000001; int Arg6 = 5000001; int Arg7 = 4; long long Arg8 = 6LL; verify_case(2, Arg8, findTotalFun(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_3() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1812447358; int Arg2 = 1812447358; int Arg3 = 1812447358; int Arg4 = 42524; int Arg5 = 2565262; int Arg6 = 2676642; int Arg7 = 6; long long Arg8 = 7LL; verify_case(3, Arg8, findTotalFun(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_4() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1010; int Arg2 = 2010; int Arg3 = 3010; int Arg4 = 900010; int Arg5 = 9000; int Arg6 = 76540; int Arg7 = 8; long long Arg8 = 10LL; verify_case(4, Arg8, findTotalFun(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SuffixDecomposition ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

