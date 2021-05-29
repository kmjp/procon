#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

class SudokuTypo {
	public:
	int fix(vector <int> digits) {
		int C[10]={};
		FORR(d,digits) C[d]++;
		int i;
		FOR(i,9) if(C[i+1]<9) return i+1;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {8,6,1,2,3,4,9,5,3,
 4,7,9,5,6,1,2,8,3,
 3,2,5,9,7,8,1,6,4,
 9,5,8,1,4,3,6,7,2,
 7,1,2,8,5,6,3,4,9,
 6,3,4,7,2,9,5,1,8,
 5,9,6,4,8,2,7,3,1,
 1,4,3,6,9,7,8,2,5,
 2,8,7,3,1,5,4,9,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(0, Arg1, fix(Arg0)); }
	void test_case_1() { int Arr0[] = {8,6,1,2,3,4,9,5,7,
 4,7,9,5,6,1,2,8,3,
 3,2,5,9,7,8,1,6,4,
 9,5,8,1,4,3,6,7,2,
 7,1,2,8,1,6,3,4,9,
 6,3,4,7,2,9,5,1,8,
 5,9,6,4,8,2,7,3,1,
 1,4,3,6,9,7,8,2,5,
 2,8,7,3,1,5,4,9,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, fix(Arg0)); }
	void test_case_2() { int Arr0[] = {5,3,4,6,7,8,9,1,2,
 6,7,2,1,9,5,3,4,8,
 1,9,8,3,4,2,5,6,7,
 8,5,9,7,6,1,4,2,3,
 4,2,6,8,5,3,7,9,1,
 7,1,3,9,2,4,8,5,6,
 9,6,1,5,3,7,2,8,4,
 2,8,7,4,1,9,1,3,5,
 3,4,5,2,8,6,1,7,9}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, fix(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SudokuTypo ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

