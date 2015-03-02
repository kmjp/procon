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

class RobotOnMoonEasy {
	public:
	int H,W;
	string isSafeCommand(vector <string> B, string S) {
		H=B.size();
		W=B[0].size();
		int sy,sx,i,j,x,y;
		FOR(y,H) FOR(x,W) if(B[y][x]=='S') sy=y,sx=x,B[y][x]='.';
		ITR(it,S) {
			int ty=sy,tx=sx;
			if(*it=='U') ty--;
			if(*it=='D') ty++;
			if(*it=='L') tx--;
			if(*it=='R') tx++;
			
			if(tx<0 || tx>=W || ty<0 || ty>=H) return "Dead";
			if(B[ty][tx]=='.') sy=ty,sx=tx;
		}
		return "Alive";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....",
 ".###.",
 "..S#.",
 "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "URURURURUR"; string Arg2 = "Alive"; verify_case(0, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".....",
 ".###.",
 "..S..",
 "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "URURURURUR"; string Arg2 = "Dead"; verify_case(1, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {".....",
 ".###.",
 "..S..",
 "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "URURU"; string Arg2 = "Alive"; verify_case(2, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD"; string Arg2 = "Alive"; verify_case(3, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#.###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD"; string Arg2 = "Dead"; verify_case(4, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "R"; string Arg2 = "Dead"; verify_case(5, Arg2, isSafeCommand(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RobotOnMoonEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
