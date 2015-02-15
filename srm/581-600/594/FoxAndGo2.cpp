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
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int NB,NE;
set<int> bl[2501],em[2501],b2e[2501],b2el[2501];
int fr[2501][2501],fr2[2501];

class FoxAndGo2 {
	public:
	int boss[51][51],N;
	vector<string> B;
	
	void dfs(char c,int x,int y,int key,set<int>& ss) {
		int i,tx,ty,f=1;
		ss.insert(x*50+y);
		boss[x][y]=key;
		FOR(i,4) {
			tx=x+dx[i],ty=y+dy[i];
			if(tx<0 || tx>=N || ty<0 || ty>=N) continue;
			if(B[tx][ty]!=c) continue;
			if(boss[tx][ty]!=-1) continue;
			ss.insert(tx*50+ty);
			boss[tx][ty]=key;
			dfs(c,tx,ty,key,ss);
		}
	}
	
	int maxKill(vector <string> board) {
		B=board;
		N=B.size();
		MINUS(boss);
		NB=NE=0;
		
		int x,y,i,tx,ty;
		FOR(i,2500) bl[i].clear(),em[i].clear(),b2e[i].clear(),b2el[i].clear();
		FOR(x,N) FOR(y,N) if(boss[x][y]==-1 && B[x][y]=='o') dfs('o',x,y,NB,bl[NB]),NB++;
		FOR(x,N) FOR(y,N) if(boss[x][y]==-1 && B[x][y]=='.') dfs('.',x,y,NE,em[NE]),NE++;
		if(NB==0) return 0;
		
		FOR(x,NB) FOR(y,NE) {
			fr[x][y]=0,fr2[y]=0;
			ITR(it,em[y]) {
				int ex=*it/50,ey=*it%50;
				int f=1;
				FOR(i,4) {
					tx=ex+dx[i],ty=ey+dy[i];
					if(tx<0 || tx>=N || ty<0 || ty>=N) continue;
					if(B[tx][ty]=='o' && boss[tx][ty]==x) f=0;
				}
				fr[x][y]|=f;
			}
		}
		
		
		FOR(x,N) FOR(y,N) if(B[x][y]=='o') {
			FOR(i,4) {
				tx=x+dx[i],ty=y+dy[i];
				if(tx<0 || tx>=N || ty<0 || ty>=N) continue;
				if(B[tx][ty]=='.' && fr[boss[x][y]][boss[tx][ty]]==0) b2e[boss[x][y]].insert(boss[tx][ty]);
				if(B[tx][ty]=='.') b2el[boss[x][y]].insert(boss[tx][ty]);
			}
		}
		set<int> cand;
		FOR(i,NB) cand.insert(i);
		int r=0;
		int up=1;
		while(up) {
			up=0;
			ITR(it,cand) if(b2e[*it].size()<=1) {
				up=1;
				x=*it;
				cand.erase(it);
				r+=bl[x].size();
				ITR(ite,b2el[x]) ITR(it2,cand) b2e[*it2].erase(*ite);
				break;
			}
		}
		
		return r;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...",
 ".o.",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, maxKill(Arg0)); }
	void test_case_1() { string Arr0[] = {"o.",
 "oo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, maxKill(Arg0)); }
	void test_case_2() { string Arr0[] = {".o.o.",
 "o.o.o",
 ".o.o.",
 "o.o.o",
 ".o.o."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, maxKill(Arg0)); }
	void test_case_3() { string Arr0[] = {".o.o.",
 "o.o.o",
 ".o.o.",
 "o.o.o",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, maxKill(Arg0)); }
	void test_case_4() { string Arr0[] = {".o.o.o.o.o.",
 "o.ooo.ooo.o",
 ".o.......o.",
 "oo.......oo",
 ".o...o...o.",
 "o...o.o...o",
 ".o...o...o.",
 "oo.......oo",
 ".o.......o.",
 "o.ooo.ooo.o",
 ".o.o.o.o.o."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, maxKill(Arg0)); }
	void test_case_5() { string Arr0[] = {"...ooo.....",
 "...o.o.....",
 ".ooo.ooo...",
 ".o.....o...",
 ".ooo.ooo...",
 "...o.o.....",
 "...ooo.....",
 "....o......",
 "....o...ooo",
 "....ooooo.o",
 "........ooo"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 38; verify_case(5, Arg1, maxKill(Arg0)); }
	void test_case_6() { string Arr0[] = {"ooooooooooo",
 "o.........o",
 "o...ooo...o",
 "o...o.o...o",
 "o...ooo...o",
 "o....o....o",
 "o....oooooo",
 "o..........",
 "o.......ooo",
 "o.......o.o",
 "ooooooooooo"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(6, Arg1, maxKill(Arg0)); }
	void test_case_7() { string Arr0[] = {"oo.o.ooo.o..o..",
 "...ooo.o..oo.oo",
 "o..o.o.ooo.o..o",
 "oo.......oo.ooo",
 "..oo.o.o.o.ooo.",
 "..oo..oo..o.ooo",
 "oo.o.oo..o.oooo",
 ".oo.o..ooo.o.oo",
 "o..o.o.o.o.oo..",
 ".oo.oo...o....o",
 "o.o.oo....oo..o",
 ".o.o..o.oo..ooo",
 "o.o.o..o..o....",
 "ooo.oooooooo..o",
 "o..oo.o..o.ooo."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60; verify_case(7, Arg1, maxKill(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FoxAndGo2 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

