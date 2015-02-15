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

class MagicBoard {
	public:
	int H,W;
	vector <string> B;
	
	int reachable(int y,int x) {
		int vis[51][51],tx,ty;
		
		ZERO(vis);
		queue<int> Q;
		Q.push(y*100+x);
		vis[y][x]=1;
		while(!Q.empty()) {
			int k=Q.front();
			Q.pop();
			int cy=k/100,cx=k%100;
			int ty,tx;
			if(vis[cy][cx]&1) {FOR(tx,W) if(tx!=cx && B[cy][tx] && (vis[cy][tx]&2)==0) vis[cy][tx]|=2,Q.push(cy*100+tx);}
			if(vis[cy][cx]&2) {FOR(ty,H) if(ty!=cy && B[ty][cx] && (vis[ty][cx]&1)==0) vis[ty][cx]|=1,Q.push(ty*100+cx);}
		}
		int ng=0;
		FOR(y,H) FOR(x,W) if(B[y][x] && vis[y][x]==0) ng++;
		return ng==0;
		
	}
	
	string ableToUnlock(vector <string> board) {
		B=board;
		H=board.size();
		W=board[0].size();
		
		int R[51],C[51],N=0;
		int x,y,tx,ty;
		ZERO(R);
		ZERO(C);
		FOR(y,H) FOR(x,W) B[y][x]=(B[y][x]=='#');
		FOR(y,H) FOR(x,W) R[y]^=B[y][x], C[x]^=B[y][x], N^=B[y][x];
		
		FOR(y,H) FOR(x,W) if(B[y][x]) {
			
			int R2[51],C2[51];
			memmove(R2,R,sizeof(R2));
			memmove(C2,C,sizeof(C2));
			C2[x]^=1;
			int ro=0,co=0;
			FOR(ty,H) ro+=R2[ty];
			FOR(tx,W) co+=C2[tx];
			if(N==1 && ro==1 && co==0 && reachable(y,x)) return "YES";
			if(N==0 && co==1 && ro==0 && reachable(y,x)) return "YES";
		}
		
		return "NO";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"##",
 ".#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, ableToUnlock(Arg0)); }
	void test_case_1() { string Arr0[] = {"#.",
 ".#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(1, Arg1, ableToUnlock(Arg0)); }
	void test_case_2() { string Arr0[] = {"##",
 "##",
 "##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, ableToUnlock(Arg0)); }
	void test_case_3() { string Arr0[] = {"###",
 "###",
 "###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, ableToUnlock(Arg0)); }
	void test_case_4() { string Arr0[] = {"###",
 "..#",
 "###",
 "#..",
 "###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, ableToUnlock(Arg0)); }
	void test_case_5() { string Arr0[] = {"................",
 ".######..######.",
 ".######..######.",
 ".##......##..##.",
 ".##......##..##.",
 ".######..######.",
 ".######..######.",
 ".....##..##..##.",
 ".....##..##..##.",
 ".######..######.",
 ".######..######.",
 "................"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(5, Arg1, ableToUnlock(Arg0)); }
	void test_case_62() { string Arr0[] = {"#","#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(6, Arg1, ableToUnlock(Arg0)); }
	void test_case_6() { string Arr0[] = {"##...#.........####.#..##.#....##...#", "....###........#.###.#....##......#.#", "#.#...#..........##....##.##...###...", "##.#.#.....#...#.##..###.#.##...##...", "#....#.....#......#..#....#..........", ".#.###..#......#.##.#....#....#.##.#.", "...##......#...#.##.#...#.#.....#..##", "....#.#..........##.....#.....#......", "....##.....#...#........#.........#..", ".####.#.#.......#####.###.###...##..#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(6, Arg1, ableToUnlock(Arg0)); }


// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MagicBoard ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
