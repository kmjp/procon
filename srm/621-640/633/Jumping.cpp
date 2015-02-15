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

class Jumping {
	public:
	string ableToGet(int x, int y, vector <int> jumpLengths) {
		double tot=0, ma=sqrt(x*x+y*y),N=jumpLengths.size();
		int i;
		tot+=ma;
		FOR(i,N) {
			tot+=jumpLengths[i];
			ma=max(ma,0.0+jumpLengths[i]);
		}
		if(ma*2<=tot) return "Able";
		return "Not able";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 4; int Arr2[] = {2, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Able"; verify_case(0, Arg3, ableToGet(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 4; int Arr2[] = {4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Not able"; verify_case(1, Arg3, ableToGet(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 4; int Arr2[] = {6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Not able"; verify_case(2, Arg3, ableToGet(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 1; int Arr2[] = {100, 100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Able"; verify_case(3, Arg3, ableToGet(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 300; int Arg1 = 400; int Arr2[] = {500}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Able"; verify_case(4, Arg3, ableToGet(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 11; int Arg1 = 12; int Arr2[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Able"; verify_case(5, Arg3, ableToGet(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 11; int Arg1 = 12; int Arr2[] = {1,2,3,4,5,6,7,8,9,100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Not able"; verify_case(6, Arg3, ableToGet(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Jumping ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

