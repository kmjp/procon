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

class OperateString {
	public:
	string operate(string s, vector <int> moves) {
		ll tot=0;
		FORR(m,moves) tot+=m;
		ll N=s.size();
		tot=tot%N+N;
		string t;
		int i;
		FOR(i,N) t+=s[(i+tot)%N];
		return t;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abcde"; int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "deabc"; verify_case(0, Arg2, operate(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abcde"; int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "deabc"; verify_case(1, Arg2, operate(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "abracadabra"; int Arr1[] = {-3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "braabracada"; verify_case(2, Arg2, operate(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "topcoder"; int Arr1[] = {-5,7,-2,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "dertopco"; verify_case(3, Arg2, operate(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "havefunsolvingthissrmwatchoutfortimeoutsmakesureyoursolutionisfastenough"; int Arr1[] = {1000000000,-900000000,800000000,-700000000,600000000,543210987}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ingthissrmwatchoutfortimeoutsmakesureyoursolutionisfastenoughhavefunsolv"; verify_case(4, Arg2, operate(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  OperateString ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

