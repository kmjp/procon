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

class DevuAndGame {
	public:
	string canWin(vector <int> nextLevel) {
		int x = 0;
		
		while(1) {
			if(nextLevel[x]==-1) return "Win";
			if(nextLevel[x]==-2) return "Lose";
			int y = nextLevel[x];
			nextLevel[x]=-2;
			x = y;
		}
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Win"; verify_case(0, Arg1, canWin(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 0, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Lose"; verify_case(1, Arg1, canWin(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Lose"; verify_case(2, Arg1, canWin(Arg0)); }
	void test_case_3() { int Arr0[] = {29,33,28,16,-1,11,10,14,6,31,7,35,34,8,15,17,26,12,13,22,1,20,2,21,-1,5,19,9,18,4,25,32,3,30,23,10,27}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Win"; verify_case(3, Arg1, canWin(Arg0)); }
	void test_case_4() { int Arr0[] = {17,43,20,41,42,15,18,35,-1,31,7,33,23,33,-1,-1,0,33,19,12,42,-1,-1,9,9,-1,39,-1,31,46,-1,20,44,41,-1,-1,12,-1,36,-1,-1,6,47,10,2,4,1,29}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Win"; verify_case(4, Arg1, canWin(Arg0)); }
	void test_case_5() { int Arr0[] = {3, 1, 1, 2, -1, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Lose"; verify_case(5, Arg1, canWin(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DevuAndGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
