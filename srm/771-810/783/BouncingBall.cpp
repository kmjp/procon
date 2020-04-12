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

class BouncingBall {
	public:
	double getPosition(int G, int h, int p, int t) {
		double g=G/100.0;
		double tim=sqrt(2.0*h/g);
		if(t<=tim) return h-g*t*t/2.0;
		double v=g*tim;
		double lef=t-tim;
		while(1) {
			v*=sqrt((100-p)/100.0);
			tim = 2*v/g;
			//cout<<v<<" "<<lef<<" "<<tim<<endl;
			if(lef<=tim) {
				return v*lef-g/2.0*lef*lef;
			}
			lef-=tim;
		}
		return 0;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 981; int Arg1 = 10; int Arg2 = 0; int Arg3 = 1; double Arg4 = 5.095; verify_case(0, Arg4, getPosition(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 981; int Arg1 = 10; int Arg2 = 0; int Arg3 = 2; double Arg4 = 6.408564143658009; verify_case(1, Arg4, getPosition(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 981; int Arg1 = 10; int Arg2 = 0; int Arg3 = 47; double Arg4 = 1.5951180154118365; verify_case(2, Arg4, getPosition(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 981; int Arg1 = 10; int Arg2 = 8; int Arg3 = 2; double Arg4 = 6.081311391188509; verify_case(3, Arg4, getPosition(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 981; int Arg1 = 10; int Arg2 = 8; int Arg3 = 47; double Arg4 = 0.7952075484286876; verify_case(4, Arg4, getPosition(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 1000; int Arg1 = 10; int Arg2 = 10; int Arg3 = 50; double Arg4 = 0.036079462357220954; verify_case(5, Arg4, getPosition(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BouncingBall ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

