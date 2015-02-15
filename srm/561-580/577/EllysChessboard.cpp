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

class EllysChessboard {
	public:
	int B[20][20];
	int memo[20][20][20][20];
	vector<int> X,Y;
	
	int dp(int l,int t,int r,int b) {
		if(memo[l][t][r][b]==-1) {
			ll mask=0;
			int i,j;
			FOR(i,X.size()) if(X[i]<l || X[i]>r || Y[i]<t || Y[i]>b) mask |= 1LL<<i;
			if(mask==0) return memo[l][t][r][b]=0;
			
			memo[l][t][r][b] = 1<<30;
			FOR(i,4) {
				int nl=l-(i==0);
				int nr=r+(i==1);
				int nt=t-(i==2);
				int nb=b+(i==3);
				int mc=0;
				if(nl<0 || nr>=16 || nt<0 || nb>=16) continue;
				
				FOR(j,X.size()) if((mask & (1LL<<j)) && X[j]>=nl && X[j]<=nr && Y[j]>=nt && Y[j]<=nb) {
					mc += max(max(X[j]-nl,nr-X[j]),max(Y[j]-nt,nb-Y[j]));
				}
				memo[l][t][r][b] = min(memo[l][t][r][b], mc + dp(nl,nt,nr,nb));
			}
		}
		return memo[l][t][r][b];
	}
	
	int minCost(vector <string> board) {
		int i,j,x,y;
		ZERO(B);
		MINUS(memo);
		
		X.clear();
		Y.clear();
		FOR(y,8) FOR(x,8) if(board[y][x]=='#') {
			B[x+y+1][x-y+8]=1;
			X.push_back(x-y+8);
			Y.push_back(x+y+1);
		}
		
		if(X.size()<=1) return 0;
		
		int mc=1<<30;
		FOR(i,X.size()) mc=min(mc,dp(X[i],Y[i],X[i],Y[i]));
		return mc;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"........",
 "........",
 "...#....",
 ".#......",
 ".......#",
 "........",
 "........",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(0, Arg1, minCost(Arg0)); }
	void test_case_1() { string Arr0[] = {"........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minCost(Arg0)); }
	void test_case_2() { string Arr0[] = {".#......",
 "........",
 "..#..#.#",
 "...#..#.",
 "........",
 "...#...#",
 "...#...#",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(2, Arg1, minCost(Arg0)); }
	void test_case_3() { string Arr0[] = {"##..####",
 "#####..#",
 "..#.#...",
 "#..##.##",
 ".#.###.#",
 "####.###",
 "#.#...#.",
 "##....#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 275; verify_case(3, Arg1, minCost(Arg0)); }
	void test_case_4() { string Arr0[] = {"########",
 "########",
 "########",
 "########",
 "########",
 "########",
 "########",
 "########"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 476; verify_case(4, Arg1, minCost(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysChessboard ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

