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

char from[51][51][3001];

class StepsConstruct {
	public:
	int H,W;
	vector <string> B;
	void dfs(int y,int x,int st) {
		if(st<0) return;
		if(y     && from[y-1][x][st-1]=='\0' && B[y-1][x]=='.') from[y-1][x][st-1]='U', dfs(y-1,x,st-1);
		if(y<H-1 && from[y+1][x][st-1]=='\0' && B[y+1][x]=='.') from[y+1][x][st-1]='D', dfs(y+1,x,st-1);
		if(x     && from[y][x-1][st-1]=='\0' && B[y][x-1]=='.') from[y][x-1][st-1]='L', dfs(y,x-1,st-1);
		if(x<W-1 && from[y][x+1][st-1]=='\0' && B[y][x+1]=='.') from[y][x+1][st-1]='R', dfs(y,x+1,st-1);
	}
	
	string construct(vector <string> board, int k) {
		B=board;
		H=B.size();
		W=B[0].size();
		if(B[0][0]=='#') return "";
		
		ZERO(from);
		from[0][0][k]='*';
		dfs(0,0,k);
		
		string S;
		int y=H-1,x=W-1,st=0;
		if(from[y][x][st]) {
			while(st<k) {
				S += from[y][x][st];
				if(from[y][x][st]=='L') x++;
				else if(from[y][x][st]=='R') x--;
				else if(from[y][x][st]=='U') y++;
				else if(from[y][x][st]=='D') y--;
				
				st++;
			}
			reverse(ALL(S));
		}
		return S;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...",
 ".#.",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; string Arg2 = "DDRR"; verify_case(0, Arg2, construct(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"...",
 ".#.",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; string Arg2 = "DDRRUULLDDRR"; verify_case(1, Arg2, construct(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"...#.",
 "..#..",
 ".#..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; string Arg2 = ""; verify_case(2, Arg2, construct(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"..#",
 "#.#",
 "..#",
 ".#.",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = ""; verify_case(3, Arg2, construct(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {".#...",
 ".#.#.",
 ".#.#.",
 ".#.#.",
 "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; string Arg2 = "DDDDRRUUUURRDDDD"; verify_case(4, Arg2, construct(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"#.", 
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = ""; verify_case(5, Arg2, construct(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  StepsConstruct ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

