#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class TheNicePair {
	public:
	int solve(vector <int> A) {
		int i,j;
		int x,y,z;
		int ret=-1;
		
		for(i=2;i<=1000;i++) {
			FOR(y,A.size()) FOR(x,y+1) {
				int num=0;
				for(z=x;z<=y;z++) if(A[z]%i==0) num++;
				if(num>=(y-x+2)/2) ret=max(ret,(y-x));
			}
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5,5,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arr0[] = {2,3,5,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { int Arr0[] = {8,8,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { int Arr0[] = {1,1000,1000,1,1000,1,999}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, solve(Arg0)); }
	void test_case_5() { int Arr0[] = {1000,1,1,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(5, Arg1, solve(Arg0)); }
	void test_case_6() { int Arr0[] = {1,1,953,1,1,1,1,1,1,1,1,1,1,1,1,953,1,953,953,1,1,1,1,1,1,1,953,953,953,1,1,1,1,1,953,953,1,1,1,953,953,953,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(6, Arg1, solve(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TheNicePair ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
