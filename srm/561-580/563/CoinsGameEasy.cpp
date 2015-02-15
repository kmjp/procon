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


class CoinsGameEasy {
	public:
	int dist[21][21][21][21];
	int ds[21][21][21][21];
	int H,W,ms;
	char str[21][21];
	vector <string> B;
	void dfs(int cx0,int cy0, int cx1, int cy1) {
		if(dist[cx0][cy0][cx1][cy1]>=10) return;
		
		int dx[4]={1,-1,0,0};
		int dy[4]={0,0,1,-1};
			
		int loop,fc;
		FOR(loop,4) {
			int ncx0=cx0+dx[loop];
			int ncy0=cy0+dy[loop];
			int ncx1=cx1+dx[loop];
			int ncy1=cy1+dy[loop];
			fc=0;
			if(ncx0<0 || ncx0>=W || ncy0<0 || ncy0>=H) fc++;
			else {
				if(B[ncy0][ncx0]=='#') {
					ncx0=cx0;
					ncy0=cy0;
				}
			}
			if(ncx1<0 || ncx1>=W || ncy1<0 || ncy1>=H) fc++;
			else {
				if(B[ncy1][ncx1]=='#') {
					ncx1=cx1;
					ncy1=cy1;
				}
			}
			if(fc==1){
				ms=min(ms,dist[cx0][cy0][cx1][cy1]+1);	
				return;
			}
			if(fc==2) continue;
			if(ncx0==cx0 && ncy0==cy0 && ncx1==cx1 && ncy1==cy1) continue;
			if(ncx0==ncx1 && ncy0==ncy1) continue;
			if(dist[ncx0][ncy0][ncx1][ncy1]>dist[cx0][cy0][cx1][cy1]+1) {
				dist[ncx0][ncy0][ncx1][ncy1]=dist[cx0][cy0][cx1][cy1]+1;
				dfs(ncx0,ncy0,ncx1,ncy1);
			}
		}
		return;
	}
	
	int minimalSteps(vector <string> board) {
		H=board.size();
		W=board[0].size();
		B=board;
		FILL_INT(dist,1000000);
		int x,y;
		
		int nc=0;
		int cx[2],cy[2];
		FOR(y,H) FOR(x,W) {
			if(board[y][x]=='o') {
				cx[nc]=x;
				cy[nc]=y;
				nc++;
			}
		}
		ms=10000;
		dist[cx[0]][cy[0]][cx[1]][cy[1]]=0;
		dfs(cx[0],cy[0],cx[1],cy[1]);
		return (ms>10)?-1:ms;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"oo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minimalSteps(Arg0)); }
	void test_case_1() { string Arr0[] = {".#", 
 ".#", 
 ".#",
 "o#",
 "o#",
 "##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, minimalSteps(Arg0)); }
	void test_case_2() { string Arr0[] = {"..",
 "..",
 "..",
 "o#",
 "o#",
 "##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, minimalSteps(Arg0)); }
	void test_case_3() { string Arr0[] = {"###",
 ".o.",
 "###",
 ".o.",
 "###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, minimalSteps(Arg0)); }
	void test_case_4() { string Arr0[] = {"###",
 ".o.",
 "#.#",
 ".o.",
 "###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, minimalSteps(Arg0)); }
	void test_case_5() { string Arr0[] = {"###########",
 "........#o#",
 "###########",
 ".........o#",
 "###########"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(5, Arg1, minimalSteps(Arg0)); }
	void test_case_7() { string Arr0[] = {"############",
 ".........#o#",
 "############",
 "..........o#",
 "############"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(6, Arg1, minimalSteps(Arg0)); }
	void test_case_6() { string Arr0[] = {
".......",
".......",
"..o....",
".......",
".......",
".......",
".......",
".......",
"......#",
".......",
".......",
".......",
".......",
".......",
"..o....",
".......",
".......",
".......",
"......."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(6, Arg1, minimalSteps(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  CoinsGameEasy ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
