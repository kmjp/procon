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

class PeacefulLine {
	public:
	string makeLine(vector <int> x) {
		int co[27]={};
		int i;
		FOR(i,x.size()) co[x[i]]++;
		FOR(i,26) if(co[i]>(x.size()+1)/2) return "impossible";
		return "possible";
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "possible"; verify_case(0, Arg1, makeLine(Arg0)); }
	void test_case_1() { int Arr0[] = {1,1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "impossible"; verify_case(1, Arg1, makeLine(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,2,2,3,3,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "possible"; verify_case(2, Arg1, makeLine(Arg0)); }
	void test_case_3() { int Arr0[] = {3,3,3,3,13,13,13,13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "possible"; verify_case(3, Arg1, makeLine(Arg0)); }
	void test_case_4() { int Arr0[] = {3,7,7,7,3,7,7,7,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "impossible"; verify_case(4, Arg1, makeLine(Arg0)); }
	void test_case_5() { int Arr0[] = {25,12,3,25,25,12,12,12,12,3,25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "possible"; verify_case(5, Arg1, makeLine(Arg0)); }
	void test_case_6() { int Arr0[] = {3,3,3,3,13,13,13,13,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "possible"; verify_case(6, Arg1, makeLine(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PeacefulLine ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
