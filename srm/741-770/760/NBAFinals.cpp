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

class NBAFinals {
	public:
	int dubsAgain(vector <int> scores, string team) {
		int R=0,W=0;
		int i;
		FOR(i,team.size()) {
			if(team[i]=='R') {
				if(scores[i]==0) {
					R++;
				}
				else {
					R+=scores[i];
				}
			}
			else {
				if(scores[i]==0) {
					W+=4;
				}
				else {
					W+=scores[i];
				}
			}
		}
		return W>R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 2, 3, 3, 2, 4, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "RRWWRWR"; int Arg2 = 1; verify_case(0, Arg2, dubsAgain(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2, 2, 3, 3, 2, 3, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "RRWWRWR"; int Arg2 = 0; verify_case(1, Arg2, dubsAgain(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WR"; int Arg2 = 1; verify_case(2, Arg2, dubsAgain(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "RWR"; int Arg2 = 0; verify_case(3, Arg2, dubsAgain(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "????"; int Arg2 = 1; verify_case(4, Arg2, dubsAgain(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {3, 2, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "?WR?"; int Arg2 = 1; verify_case(5, Arg2, dubsAgain(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {0, 1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "R?W?R"; int Arg2 = 1; verify_case(6, Arg2, dubsAgain(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  NBAFinals ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

