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

class PointDistance {
	public:
	vector <int> findPoint(int x1, int y1, int x2, int y2) {
		int cx,cy;
		for(cx=-100;cx<=100;cx++)
			for(cy=-100;cy<=100;cy++) {
				int d1=(x1-cx)*(x1-cx)+(y1-cy)*(y1-cy);
				int d2=(x2-cx)*(x2-cx)+(y2-cy)*(y2-cy);
				if(d1&&d2&&d1>d2) return {cx,cy};
			}
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = -1; int Arg1 = 0; int Arg2 = 1; int Arg3 = 0; int Arr4[] = {8, 48 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, findPoint(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = -1; int Arg3 = -1; int Arr4[] = {25, -63 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, findPoint(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 1; int Arg2 = 2; int Arg3 = 3; int Arr4[] = {41, 65 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, findPoint(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = -4; int Arg2 = -2; int Arg3 = 5; int Arr4[] = {68, 70 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, findPoint(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = -50; int Arg1 = -50; int Arg2 = 50; int Arg3 = -50; int Arr4[] = {67, 4 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, findPoint(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = -50; int Arg1 = 50; int Arg2 = -49; int Arg3 = 49; int Arr4[] = {73, -25 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(5, Arg4, findPoint(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PointDistance ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
