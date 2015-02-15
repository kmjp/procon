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

class DropCoins {
	public:
	int sum[52][52];
	int getMinimum(vector <string> board, int K) {
		int x,y,i,c=0,r=10000000,h,w;
		int H=board.size();
		int W=board[0].size();
		
		FOR(y,H+1) FOR(x,W+1) {
			sum[y][x]=0;
			FOR(h,y) FOR(w,x) if(board[h][w]=='o') sum[y][x]++;
		}
		
		FOR(y,H) FOR(x,W) {
			for(h=1;y+h<=H;h++) for(w=1;x+w<=W;w++) {
				if(sum[y+h][x+w]-sum[y][x+w]-sum[y+h][x]+sum[y][x]==K) {
					r=min(r,min(2*y+(H-(y+h)),y+2*(H-(y+h)))+min(2*x+(W-(x+w)),x+2*(W-(x+w))));
				}
			}
		}
		
		
		if(r==10000000) return -1;
		return r;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".o.."
,"oooo"
,"..o."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; verify_case(0, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".....o"
,"......"
,"oooooo"
,"oooooo"
,"......"
,"o....."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 3; verify_case(1, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"...."
,".oo."
,".oo."
,"...."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(2, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"......."
,"..ooo.."
,"ooooooo"
,".oo.oo."
,"oo...oo"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 4; verify_case(3, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"................."
,".ooooooo...oooo.."
,".ooooooo..oooooo."
,".oo.......oo..oo."
,".oo.......oo..oo."
,".ooooo.....oooo.."
,".ooooooo...oooo.."
,".....ooo..oo..oo."
,"......oo..oo..oo."
,".ooooooo..oooooo."
,".oooooo....oooo.."
,"................."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; int Arg2 = 6; verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DropCoins ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

