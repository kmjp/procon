#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

class UniformBoard {
	int NA[52][52],NP[52][52],NE[52][52];
	public:
	int getBoard(vector <string> board, int K) {
		int N=board.size();
		int x,y,h,w,h2;
		int ret=0;
		
		ZERO(NA);
		ZERO(NP);
		ZERO(NE);
		FOR(y,N) FOR(x,N) {
			FOR(h,y+1) NA[y+1][x+1]+=count(board[h].begin(),board[h].begin()+x+1,'A');
			FOR(h,y+1) NP[y+1][x+1]+=count(board[h].begin(),board[h].begin()+x+1,'P');
			FOR(h,y+1) NE[y+1][x+1]+=count(board[h].begin(),board[h].begin()+x+1,'.');
		}
		if(NE[N][N]==0) K=0;
		FOR(y,N) FOR(x,N) for(h=1;y+h<=N;h++) for(w=1;x+w<=N;w++) {
			if(h*w<=ret) continue;
			int CA=NA[y+h][x+w]-NA[y+h][x]-NA[y][x+w]+NA[y][x];
			int CP=NP[y+h][x+w]-NP[y+h][x]-NP[y][x+w]+NP[y][x];
			int CE=NE[y+h][x+w]-NE[y+h][x]-NE[y][x+w]+NE[y][x];
			if(NA[N][N]>=h*w && CE+CP*2<=K) ret=h*w;
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AP",
 ".A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"AP",
 ".A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"PPP",
 "APA",
 "A.P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(2, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"AAA",
 "PPP",
 "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 3; verify_case(3, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 0; verify_case(4, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"PPAAPA..AP",
 "PPA.APAP..",
 "..P.AA.PPP",
 "P.P..APAA.",
 "P.P..P.APA",
 "PPA..AP.AA",
 "APP..AAPAA",
 "P.P.AP...P",
 ".P.A.PAPPA",
 "..PAPAP..P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 15; verify_case(5, Arg2, getBoard(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  UniformBoard ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
