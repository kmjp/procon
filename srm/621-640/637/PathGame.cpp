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

int grundy[3][1001][3];

class PathGame {
	public:
	int H,W;
	int getgr(int d,int w,int w2) {
		set<int> me;
		int r=0,i;
		if(w==0 && d==0 && w2==1) return 1;
		if(w<=0) return 0;
		if(grundy[d][w][w2+1]>=0) return grundy[d][w][w2+1];
		
		FOR(i,w) me.insert(getgr(d,i,-1)^getgr(1,w-1-i,w2));
		for(i=d;i<w+w2;i++) me.insert(getgr(d,i-1,1)^getgr(1,w+w2-1-i,-w2));
		
		while(me.count(r)) r++;
		return grundy[d][w][w2+1]=r;
	}
	
	string judge(vector <string> board) {
		int x,y;
		W=board[0].size();
		FOR(y,2) FOR(x,W) if(board[y][x]=='#') {
			if(x>0 && board[y^1][x-1]) board[y^1][x-1]='*';
			if(board[y^1][x]) board[y^1][x]='*';
			if(x<W-1 && board[y^1][x+1]) board[y^1][x+1]='*';
		}
		
		MINUS(grundy);
		int gr=0,aa=0;
		FOR(x,W) FOR(y,2) if(board[y][x]=='.') {
			int cx=x,d=0,w=0,w2=0;
			while(cx+w<W && board[y][cx+w]=='.') board[y][cx+w]='a'+aa, w++;
			w2=d=(board[y^1][cx]!='.');
			while(cx+w2<W && board[y^1][cx+w2]=='.') board[y^1][cx+w2]='a'+aa, w2++;
			if(aa++>=26) aa=0;
			gr ^= getgr(d,w,w2-w);
		}
		cout << board[0] << endl;
		cout << board[1] << endl;
		return (gr==0)?"Sothe":"Snuke";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#.."
,"..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Snuke"; verify_case(0, Arg1, judge(Arg0)); }
	void test_case_1() { string Arr0[] = {"#"
,"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sothe"; verify_case(1, Arg1, judge(Arg0)); }
	void test_case_2() { string Arr0[] = {"....."
,"..#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sothe"; verify_case(2, Arg1, judge(Arg0)); }
	void test_case_3() { string Arr0[] = {"#........."
,".........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Snuke"; verify_case(3, Arg1, judge(Arg0)); }
	void test_case_42() { string Arr0[] = {".....#..#........##......."
,"..........#..........#...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Snuke"; verify_case(4, Arg1, judge(Arg0)); }
//	void test_case_4() { string Arr0[] = {".......................................................................................................####...#...#..#...#.........#....#.#.....................#.##.....#.#.............................#.#.............#...#.....#.#..........##.#.......#....#..........#.........................................................................................................", "...................................................................................................#........#.................#.##............#.......#.#..###...............#...#..#....#..#........#.#.......#...............#.....................#..#..............#.........##.................................................................................................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sothe"; verify_case(4, Arg1, judge(Arg0)); }
void test_case_4() { string Arr0[] = {
	".....#.....", "..........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sothe"; verify_case(4, Arg1, judge(Arg0)); }


// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PathGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
