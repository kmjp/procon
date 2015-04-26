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

class TheTips {
	public:
	double solve(vector <string> clues, vector <int> probability) {
		int N=clues.size();
		int i,x,y;
		
		FOR(i,N) FOR(x,N) FOR(y,N) if(clues[x][i]=='Y' && clues[i][y]=='Y') clues[x][y]='Y';
		double ret=0;
		FOR(i,N) {
			double fail=1;
			FOR(x,N) if(clues[x][i]=='Y' || i==x) fail *= 1-probability[x]/100.0;
			ret += 1-fail;
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.5; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"YN","NY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.5; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"YYY","NYY","NNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.0; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"NNN","NNN","NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"NYYNYYNNNN","NNNNYNNNYN","YNNYYYYYNN","YYNYNNNNYN","NYNNNNNNNY","YNYYNNYNNY","NYNNYYYYYY","NYYYYNNNNN","YYNYNNYYYN","NNYYNYNYYY"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {11,66,99,37,64,45,21,67,71,62}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 9.999891558057332; verify_case(4, Arg2, solve(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"NNY","NNY","NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50, 50, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.7525; verify_case(5, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TheTips ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
