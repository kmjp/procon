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

class VertexMove {
	public:
	double largestTriangleArea(int a, int b, int c) {
		double s=(a+b+c)/2.0;
		double S=sqrt(s*(s-a)*(s-b)*(s-c));
		int d=max({a,b,c});
		double h=2*S/d;
		return d*(h+1)/2;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 5; double Arg3 = 8.5; verify_case(0, Arg3, largestTriangleArea(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 10; double Arg3 = 48.30127018922193; verify_case(1, Arg3, largestTriangleArea(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 12; int Arg1 = 13; int Arg2 = 16; double Arg3 = 84.68727078205352; verify_case(2, Arg3, largestTriangleArea(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  VertexMove ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

