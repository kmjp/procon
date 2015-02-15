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
#include <numeric>
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
#define ALL(x) x.begin(),x.end()
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int cost[64][64][64];

class NumberLabyrinthDiv2 {
	int R,C;
	public:
	int getMinimumNumberOfMoves(vector <string> board, int r1, int c1, int r2, int c2, int K) {
		int x,y,z,d,i;
		R=board.size();
		C=board[0].size();
		FOR(x,64) FOR(y,64) FOR(z,64) cost[x][y][z]=10000;
		cost[r1][c1][K]=0;
		queue<int> Q;
		Q.push(r1*10000+c1*100+K);
		
		while(!Q.empty()) {
			int k=Q.front();
			Q.pop();
			int cy=k/10000,cx=(k/100)%100,ck=k%100;
			
			for(d=1;d<=9;d++) {
				if(board[cy][cx]!='.' && board[cy][cx]!='0'+d) continue;
				if(board[cy][cx]=='.' && ck==0) continue;
				FOR(i,4) {
					int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
					int ty=cy+dy[i]*d,tx=cx+dx[i]*d;
					if(tx<0 || tx>=C || ty<0 || ty>=R) continue;
					if(cost[ty][tx][ck-(board[cy][cx]=='.')] > cost[cy][cx][ck]+1) {
						cost[ty][tx][ck-(board[cy][cx]=='.')] = cost[cy][cx][ck]+1;
						Q.push(ty*10000+tx*100+ck-(board[cy][cx]=='.'));
					}
				}
			}
		}
		int mi=10000;
		FOR(i,K+1) mi=min(mi,cost[r2][c2][i]);
		if(mi>=10000) return -1;
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...2",
 "....",
 "3..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 2; int Arg4 = 3; int Arg5 = 0; int Arg6 = -1; verify_case(0, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { string Arr0[] = {"...2",
 "....",
 "3..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 2; int Arg4 = 3; int Arg5 = 1; int Arg6 = 2; verify_case(1, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { string Arr0[] = {"...3",
 "....",
 "2..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 2; int Arg4 = 3; int Arg5 = 3; int Arg6 = 3; verify_case(2, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { string Arr0[] = {"55255",
 ".0.0.",
 "..9..",
 "..3..",
 "3.9.3",
 "44.44"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; int Arg3 = 4; int Arg4 = 2; int Arg5 = 10; int Arg6 = 6; verify_case(3, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { string Arr0[] = {"920909949",
 "900020000",
 "009019039",
 "190299149",
 "999990319",
 "940229120",
 "000409399",
 "999119320",
 "009939999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 3; int Arg3 = 1; int Arg4 = 1; int Arg5 = 50; int Arg6 = 10; verify_case(4, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  NumberLabyrinthDiv2 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

