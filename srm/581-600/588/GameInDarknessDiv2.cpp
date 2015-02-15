#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

class GameInDarknessDiv2 {
	public:
	
	string check (vector <string> field, vector <string> moves) {
		bool okok[2][51][51];
		int ax,ay;
		int H=field.size();
		int W=field[0].size();
		ZERO(okok);
		
		int y,x,i,d;
		FOR(y,H) FOR(x,W) {
			if(field[y][x]=='A') ay=y,ax=x,field[y][x]='.';
			if(field[y][x]=='B') okok[0][y][x]=true,field[y][x]='.';
		}
		
		string M;
		FOR(x,moves.size()) M+=moves[x];
		
		FOR(i,M.size()) {
			int cur=i%2,tar=(i%2)^1;
			ZERO(okok[tar]);
			if(M[i]=='U') ay--;
			if(M[i]=='D') ay++;
			if(M[i]=='L') ax--;
			if(M[i]=='R') ax++;
			okok[cur][ay][ax]=false;
			
			FOR(y,H) FOR(x,W) {
				if(okok[cur][y][x]==false) continue;
				FOR(d,4) {
					int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
					int cx=x+dx[d],cy=y+dy[d];
					if(cx<0 || cy<0 || cx>=W || cy>=H) continue;
					if((cx!=ax || cy!=ay)&&field[cy][cx]=='.') okok[tar][cy][cx]=true;
				}
			}
		}
		
		FOR(y,H) FOR(x,W) if(okok[M.size()%2][y][x]) return "Bob wins";
		return "Alice wins";
			
		
		
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"A.B..",
 "##.##",
 "##.##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"RRDUR"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Alice wins"; verify_case(0, Arg2, check(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"A.B..",
 "##.##",
 "##..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"RRRLD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Bob wins"; verify_case(1, Arg2, check(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"###.#",
 "###..",
 "A..B#",
 "###..",
 "###.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"RR", "R", "UDD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Alice wins"; verify_case(2, Arg2, check(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"A.###",
 ".B..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"RDRRRLLLLUDUDRLURDLUD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Bob wins"; verify_case(3, Arg2, check(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {".....",
 ".#.#.",
 "##.#.",
 "A###.",
 "B...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"D"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Alice wins"; verify_case(4, Arg2, check(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {".#...#....#.......#....#......",
 "...###.#.#..#.#.#..###...#.#.#",
 ".#.#...#...#..#..#.....##.#...",
 "#..#.##..##..#.#..###.#....#.#",
 "..#..#..#...#...#....#..##.#..",
 "#..##..#..##.#.#.####..#.#...#",
 ".#....##.#.....#......##.#.#..",
 ".###.#...#.#.#..#.#.##...##.#.",
 ".....#.#.##..#.#..##...##...#.",
 "#.#.#...#...#.#.#...#.#.#.##.#",
 ".#..##.#..##..#.###...........",
 "..##.....####.......##.#.#.##.",
 "#....##.#.#...####.#...#.#.#..",
 "#.#.#......##.#...#..#.#..#..#",
 "..#..#.#.##...#.#..#..#..#..#.",
 ".#..#...#...#..#..#.#..#..#A#.",
 "..#..#.#.B##.##..#...#.#.##...",
 "#.#.##..#......#.#.#.#.#...#.#",
 "#.#...#.######...#.#.#.#.#.#..",
 "..#.##.#.....#.##..#...#.#.#.#",
 ".#..#..#.#.#.#.#..#.#####..#.#",
 "..#.#.##.#.#.##.#......#..#...",
 "#..#.....#.#.....#.#.##..##.#.",
 "##..###.#..#.#.#.#..##..#...##",
 "##.#...#..##.#.#..#.#..#.#.#..",
 "#..#.#.####..#..#..#..#......#",
 "..#..#.....####..#.##.#.###.#.",
 ".#..#.####.#.#..#.....#...#...",
 "..##.......#...#..####.##.#.#.",
 "#....#.#.#..#.###....#....#..#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"UURURUULLLLLLLLLLDLLLLUDLLUDDLRDDDULLDLLDDRRRRRDDU","RRUUURUULLD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Alice wins"; verify_case(5, Arg2, check(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  GameInDarknessDiv2 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
