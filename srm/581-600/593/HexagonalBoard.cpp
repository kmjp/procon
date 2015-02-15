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

int dx[6]={1,-1,1,0,-1,0};
int dy[6]={0,0,-1,-1,1,1};
class HexagonalBoard {
	public:
	int N,C;
	vector <string> B;
	int col[51][51];
	int okok2() {
		int x,y,i,ty,tx;
		FOR(x,N) FOR(y,N) col[y][x]=-1;
		queue<int> Q;
		FOR(x,N) FOR(y,N) if(B[y][x]=='X' && col[y][x]==-1) {
			col[y][x]=0;
			Q.push(y*100+x);
			while(!Q.empty()) {
				int k=Q.front();
				int cy=k/100,cx=k%100;
				Q.pop();
				
				FOR(i,6) {
					int tx=cx+dx[i];
					int ty=cy+dy[i];
					if(tx<0 || tx>=N || ty<0 || ty>=N) continue;
					if(B[ty][tx]!='X') continue;
					if(col[ty][tx]==col[cy][cx]) return 0;
					if(col[ty][tx]==-1) {
						col[ty][tx]=1-col[cy][cx];
						Q.push(ty*100+tx);
					}
				}
			}
		}
		return 1;
	}
	
	
	int minColors(vector <string> board) {
		int x,y,i;
		B=board;
		N=board.size();
		C=0;
		FOR(y,N) FOR(x,N) C+=B[y][x]=='X';
		if(C==0) return 0;
		int ng=0;
		FOR(y,N) FOR(x,N) if(B[y][x]=='X') {
			FOR(i,6) {
				int tx=x+dx[i];
				int ty=y+dy[i];
				if(tx<0 || tx>=N || ty<0 || ty>=N) continue;
				if(B[ty][tx]=='X') ng=1;
			}
		}
		if(ng==0) return 1;
		
		if(okok2()) return 2;
		return 3;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"---",
 "---",
 "---"}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, minColors(Arg0)); }
	void test_case_1() { string Arr0[] = {"-X--",
 "---X",
 "----",
 "-X--"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minColors(Arg0)); }
	void test_case_2() { string Arr0[] = {"XXXX",
 "---X",
 "---X",
 "---X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minColors(Arg0)); }
	void test_case_3() { string Arr0[] = {"XX-XX--"
,"-XX-XXX"
,"X-XX--X"
,"X--X-X-"
,"XX-X-XX"
,"-X-XX-X"
,"-XX-XX-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minColors(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  HexagonalBoard ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

