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

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#else
#define DBG(...)
#define DV(...)
#endif

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int dt[4][2][2]= {
	{{1,0},{0,-1}},
	{{-1,0},{0,-1}},
	{{1,0},{0,1}},
	{{-1,0},{0,1}},
};

class TheTilesDivTwo {
	public:
	
	int DP[2][16][16];
	int find(vector <string> board) {
		int x,y,cur,tar,pm,cm,pat,y1,y2,t1,t2,nm;
		int W=board[0].size(),H=board.size();
		ZERO(DP);
		
		FOR(x,W) {
			cur=x%2;
			tar=1^cur;
			
			ZERO(DP[tar]);
			// 0
			FOR(pm,1<<H) FOR(cm,1<<H) DP[tar][cm][0] = max(DP[tar][cm][0], DP[cur][pm][cm]);
			// 1
			FOR(y1,H) {
				if((x+y1)%2 || board[y1][x]=='X') continue;
				
				FOR(t1,4) {
					if(x+dt[t1][0][0]<0 || x+dt[t1][0][0]>=W) continue;
					if(y1+dt[t1][1][1]<0 || y1+dt[t1][1][1]>=H) continue;
					if(board[y1+dt[t1][0][1]][x+dt[t1][0][0]]=='X') continue;
					if(board[y1+dt[t1][1][1]][x+dt[t1][1][0]]=='X') continue;
					FOR(pm,1<<H) FOR(cm,1<<H) {
						if(cm & (1<<(y1+dt[t1][1][1]))) continue;
						if(dt[t1][0][0]<0){
							if(pm & (1<<y1)) continue;
							DP[tar][cm | (1<<y1) | (1<<(y1+dt[t1][1][1]))][0] = 
								max(DP[tar][cm | (1<<y1) | (1<<(y1+dt[t1][1][1]))][0], DP[cur][pm][cm]+1);
						}
						else {
							DP[tar][cm | (1<<y1) | (1<<(y1+dt[t1][1][1]))][(1<<y1)] = 
								max(DP[tar][cm | (1<<y1) | (1<<(y1+dt[t1][1][1]))][(1<<y1)], DP[cur][pm][cm]+1);
						}
					}
				}
			}
			FOR(y1,H) for(y2=y1+1;y2<H;y2++) {
				if((x+y1)%2 || board[y1][x]=='X') continue;
				if((x+y2)%2 || board[y2][x]=='X') continue;
				
				FOR(t1,4) FOR(t2,4) {
					if(y1+dt[t1][1][1] == y2+dt[t2][1][1]) continue; // collide
					if(x+dt[t1][0][0]<0 || x+dt[t1][0][0]>=W) continue;
					if(y1+dt[t1][1][1]<0 || y1+dt[t1][1][1]>=H) continue;
					if(board[y1+dt[t1][0][1]][x+dt[t1][0][0]]=='X') continue;
					if(board[y1+dt[t1][1][1]][x+dt[t1][1][0]]=='X') continue;
					if(x+dt[t2][0][0]<0 || x+dt[t2][0][0]>=W) continue;
					if(y2+dt[t2][1][1]<0 || y2+dt[t2][1][1]>=H) continue;
					if(board[y2+dt[t2][0][1]][x+dt[t2][0][0]]=='X') continue;
					if(board[y2+dt[t2][1][1]][x+dt[t2][1][0]]=='X') continue;
					FOR(pm,1<<H) FOR(cm,1<<H) {
						if(cm & (1<<(y1+dt[t1][1][1]))) continue;
						if(cm & (1<<(y2+dt[t2][1][1]))) continue;
						nm = cm | (1<<y1) | (1<<(y1+dt[t1][1][1])) | (1<<y2) | (1<<(y2+dt[t2][1][1]));
						
						if(dt[t1][0][0]<0 && (pm & (1<<y1))) continue;
						if(dt[t2][0][0]<0 && (pm & (1<<y2))) continue;
						
						if(dt[t1][0][0]<0 && dt[t2][0][0]<0) {
							DP[tar][nm][0] = max(DP[tar][nm][0], DP[cur][pm][cm]+2);
						}
						else if(dt[t1][0][0]<0 && dt[t2][0][0]>0) {
							DP[tar][nm][1<<y2] = max(DP[tar][nm][1<<y2], DP[cur][pm][cm]+2);
						}
						else if(dt[t1][0][0]>0 && dt[t2][0][0]<0) {
							DP[tar][nm][1<<y1] = max(DP[tar][nm][1<<y1], DP[cur][pm][cm]+2);
						}
						else {
							DP[tar][nm][(1<<y1)|(1<<y2)] = max(DP[tar][nm][(1<<y1)|(1<<y2)], DP[cur][pm][cm]+2);
						}
					}
				}
			}
		}
		
		int ma=0;
		FOR(pm,1<<H) FOR(cm,1<<H) ma=max(ma, DP[W%2][pm][cm]);
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X.X",
 "...",
 "X.X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arr0[] = {"...",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arr0[] = {"......X.X.XXX.X.XX."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, find(Arg0)); }
	void test_case_4() { string Arr0[] = {"X.....XXX.XX..XXXXXXXXX...X.XX.XX....X",
 ".XXXX..X..XXXXXXXX....XX.X.X.X.....XXX",
 "....XX....X.XX..X.X...XX.X..XXXXXXX..X",
 "XX.XXXXX.X.X..X..XX.XXX..XX...XXX.X..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(3, Arg1, find(Arg0)); }
	void test_case_3() { string Arr0[] = {
		"X...X...X.XXXX..X.X...X.X...X..X...XX.",
		"...X...X...X.X.....X...X.XXX.X.X...X..",
		".X..X.XX.XX.X.X.X.....X.XX..XXX.XX...X",
		"..X....X.X.X...X.......X.X...........X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 22; verify_case(3, Arg1, find(Arg0)); }


// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  TheTilesDivTwo ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
