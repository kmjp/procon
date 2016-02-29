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

class MoveStones {
	public:
	long long get(vector <int> a, vector <int> b) {
		ll SA=0,SB=0;
		int N;
		int i,j;
		N=a.size();
		
		FORR(r,a) SA+=r;
		FORR(r,b) SB+=r;
		if(SA!=SB) return -1;
		ll mi=1LL<<60;
		FOR(i,N) {
			vector<ll> A,B;
			FOR(j,N) A.push_back(a[(i+j)%N]);
			FOR(j,N) B.push_back(b[(i+j)%N]);
			
			ll pat=0;
			FOR(j,N-1) {
				A[j+1]+=A[j]-B[j];
				pat+=abs(A[j]-B[j]);
			}
			mi=min(mi,pat);
			
		}
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {12}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(0, Arg2, get(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = -1LL; verify_case(1, Arg2, get(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 5LL; verify_case(2, Arg2, get(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(3, Arg2, get(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1, 0, 1, 1, 0}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 3, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4LL; verify_case(4, Arg2, get(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1000000000, 0, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0, 1000000000, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 3000000000LL; verify_case(5, Arg2, get(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MoveStones ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
