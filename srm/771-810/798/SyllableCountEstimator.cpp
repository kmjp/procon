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

class SyllableCountEstimator {
	public:
	int estimate(string W) {
		int M[256]={};
		M['a']++;
		M['i']++;
		M['u']++;
		M['e']++;
		M['o']++;
		int C=0;
		int i;
		FORR(c,W) C+=M[c];
		int N=W.size();
		FOR(i,N) {
			if(i+2<=N&&W.substr(i,2)=="au") C--;
			if(i+2<=N&&W.substr(i,2)=="oa") C--;
			if(i+2<=N&&W.substr(i,2)=="oo") C--;
			if(i+3<=N&&W.substr(i,3)=="iou") C--;
		}
		if(W.back()=='e') C--;
		if(W.size()>=3 && W.substr(N-2,2)=="le" && M[W[N-3]]==0) C++;
		
		return max(1,C);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); if ((Case == -1) || (Case == 9)) test_case_9(); if ((Case == -1) || (Case == 10)) test_case_10(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "potato"; int Arg1 = 3; verify_case(0, Arg1, estimate(Arg0)); }
	void test_case_1() { string Arg0 = "haul"; int Arg1 = 1; verify_case(1, Arg1, estimate(Arg0)); }
	void test_case_2() { string Arg0 = "gooooooal"; int Arg1 = 1; verify_case(2, Arg1, estimate(Arg0)); }
	void test_case_3() { string Arg0 = "rhythm"; int Arg1 = 1; verify_case(3, Arg1, estimate(Arg0)); }
	void test_case_4() { string Arg0 = "e"; int Arg1 = 1; verify_case(4, Arg1, estimate(Arg0)); }
	void test_case_5() { string Arg0 = "le"; int Arg1 = 1; verify_case(5, Arg1, estimate(Arg0)); }
	void test_case_6() { string Arg0 = "various"; int Arg1 = 3; verify_case(6, Arg1, estimate(Arg0)); }
	void test_case_7() { string Arg0 = "queued"; int Arg1 = 4; verify_case(7, Arg1, estimate(Arg0)); }
	void test_case_8() { string Arg0 = "qwertyuiopasdfghjkl"; int Arg1 = 5; verify_case(8, Arg1, estimate(Arg0)); }
	void test_case_9() { string Arg0 = "participle"; int Arg1 = 4; verify_case(9, Arg1, estimate(Arg0)); }
	void test_case_10() { string Arg0 = "ukulele"; int Arg1 = 3; verify_case(10, Arg1, estimate(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SyllableCountEstimator ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

