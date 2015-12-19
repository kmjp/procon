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

int gr[55][55][2600];

class BoardEscape {
	public:
	string findWinner(vector <string> s, int k) {
		int H=s.size();
		int W=s[0].size();
		int y,x,i,j;
		
		ZERO(gr);
		for(i=1;i<=2500;i++) {
			FOR(y,H) FOR(x,W) {
				if(s[y][x]=='E') gr[y][x][i]=0;
				else if(s[y][x]=='.' || s[y][x]=='T') {
					int mex[6]={};
					FOR(j,4) {
						int dd[4]={0,-1,0,1};
						int ty=y+dd[j];
						int tx=x+dd[j^1];
						if(tx<0 || tx>=W || ty<0 || ty>=H) continue;
						if(s[ty][tx]=='#') continue;
						mex[gr[ty][tx][i-1]]=1;
					}
					while(mex[gr[y][x][i]]) gr[y][x][i]++;
				}
			}
		}
		
		if(k>2500) k=2400+(k-2500)%2;
		int ret=0;
		FOR(y,H) FOR(x,W) if(s[y][x]=='T') ret ^= gr[y][x][k];
		
		if(ret==0) return "Bob";
		return "Alice";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"TE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "Alice"; verify_case(0, Arg2, findWinner(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"E#E",
 "#T#",
 "E#E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000; string Arg2 = "Bob"; verify_case(1, Arg2, findWinner(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"T.T.T.",
 ".E.E.E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arg2 = "Alice"; verify_case(2, Arg2, findWinner(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"TTE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = "Alice"; verify_case(3, Arg2, findWinner(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"..........................",
 "......TTT..TTT..T...T.....",
 ".....T.....T..T.TT.TT.....",
 "......TTT..TTT..T.T.T.....",
 ".........T.T.T..T...T.....",
 "......TTT..T..T.T...T.....",
 "..........................",
 "...E#E#E#E#E#E#E#E#E#E#...",
 "..........................",
 "......TTT..TTT...TTT......",
 ".....T........T.T.........",
 "......TTT.....T..TTT......",
 ".....T...T...T..T...T.....",
 "......TTT....T...TTT......",
 "..........................",
 "...#E#E#E#E#E#E#E#E#E#E...",
 "..........................",
 "....TT...T...T..T.TTT.T...",
 "...T.....T...T..T.T...T...",
 "...T.TT..T...TTTT.TT..T...",
 "...T..T..T...T..T.T.......",
 "....TT...TTT.T..T.T...T...",
 ".........................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 987654321; string Arg2 = "Bob"; verify_case(4, Arg2, findWinner(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BoardEscape ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
