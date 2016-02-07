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

int L[2],R[2];
int T[2],B[2];


class ExplodingRobots {
	public:
	string canExplode(int x1, int y1, int x2, int y2, string instructions) {
		
		L[0]=R[0]=x1;
		T[0]=B[0]=y1;
		L[1]=R[1]=x2;
		T[1]=B[1]=y2;
		
		FORR(c,instructions) {
			if(c=='L') L[0]--, L[1]--;
			if(c=='R') R[0]++, R[1]++;
			if(c=='U') T[0]--, T[1]--;
			if(c=='D') B[0]++, B[1]++;
			
			
			if(L[0]>R[1] || L[1]>R[0]) continue;
			if(T[0]>B[1] || T[1]>B[0]) continue;
			return "Explosion";
		}
		return "Safe";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 2; int Arg3 = 0; string Arg4 = "L"; string Arg5 = "Explosion"; verify_case(0, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 2; int Arg3 = 0; string Arg4 = "U"; string Arg5 = "Safe"; verify_case(1, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 2; int Arg3 = 0; string Arg4 = "UL"; string Arg5 = "Explosion"; verify_case(2, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 5; int Arg3 = 5; string Arg4 = "LURLL"; string Arg5 = "Safe"; verify_case(3, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 5; int Arg2 = -9; int Arg3 = -10; string Arg4 = "LULULULLLUULRULULULULULULLULULLULD"; string Arg5 = "Explosion"; verify_case(4, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ExplodingRobots ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
