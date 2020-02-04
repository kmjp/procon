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

int P[3000001][2];

class PreviousOccurrence {
	public:
	int findValue(int defaultValue, int query) {
		MINUS(P);
		int i;
		P[0][0]=0;
		int pre=0;
		if(query==0) return 0;
		for(i=1;i<3000000;i++) {
			int cur;
			if(P[pre][1]==-1) {
				cur=defaultValue;
			}
			else {
				cur=P[pre][0]-P[pre][1];
			}
			if(cur==query) return i;
			P[cur][1]=P[cur][0];
			P[cur][0]=i;
			pre=cur;
		}
		return -1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 0; int Arg2 = 0; verify_case(0, Arg2, findValue(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 2; int Arg2 = 5; verify_case(1, Arg2, findValue(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 47; int Arg2 = 1261; verify_case(2, Arg2, findValue(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 7; int Arg2 = 66; verify_case(3, Arg2, findValue(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 47; int Arg1 = 6763; int Arg2 = 540153; verify_case(4, Arg2, findValue(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PreviousOccurrence ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

