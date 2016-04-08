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

double win[1010][1010];

class Queueing {
	public:
	double probFirst(int len1, int len2, int p1, int p2) {
		int i,j,x,y;
		double P[2]={1.0/p1,1.0/p2};
		double Q[2]={1-P[0],1-P[1]};
		
		ZERO(win);
		FOR(i,1000) win[0][i+1]=1;
		
		for(x=1;x<=1000;x++) for(y=1;y<=1000;y++) {
			win[x][y] = P[0]*Q[1]*win[x-1][y]; // get only first
			win[x][y] += P[1]*Q[0]*win[x][y-1]; // get only second
			win[x][y] += P[0]*P[1]*win[x-1][y-1]; // get both
			win[x][y] /= (1-Q[0]*Q[1]); // forget else;
		}
		
		return win[len1][len2];
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; double Arg4 = 0.5; verify_case(0, Arg4, probFirst(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 3; int Arg3 = 7; double Arg4 = 0.9835390946502058; verify_case(1, Arg4, probFirst(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 7; int Arg3 = 3; double Arg4 = 0.010973936899862834; verify_case(2, Arg4, probFirst(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 12; int Arg1 = 34; int Arg2 = 56; int Arg3 = 78; double Arg4 = 0.999996203228025; verify_case(3, Arg4, probFirst(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 6; int Arg2 = 8; int Arg3 = 4; double Arg4 = 0.5229465300297028; verify_case(4, Arg4, probFirst(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Queueing ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
