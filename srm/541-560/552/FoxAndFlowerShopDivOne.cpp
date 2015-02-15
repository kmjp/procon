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

typedef signed long long s64;
typedef unsigned long long u64;

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


class FoxAndFlowerShopDivOne {
	public:
	char str[40][40];
	int fl[40][40][2];
	int* lp,*pp;
	
	int W,H;
	
	void rect(int x1,int y1,int x2,int y2,int* l,int* p) {
		*l = fl[y2][x2][0]-fl[y1][x2][0]-fl[y2][x1][0]+fl[y1][x1][0];
		*p = fl[y2][x2][1]-fl[y1][x2][1]-fl[y2][x1][1]+fl[y1][x1][1];
	}
	
	int theMaxFlowers(vector <string> flowers, int maxDiff) {
		H = flowers.size();
		W = strlen(flowers[0].c_str());
		int i;
		FOR(i,H) strcpy(str[i],flowers[i].c_str());
		
		int x,y,tx,ty,l,p;
		l=p=0;
		ZERO(fl);
		FOR(y,H+1) FOR(x,W+1) {
			FOR(ty,y) FOR(tx,x) {
				if(str[ty][tx]=='L'){ fl[y][x][0]++; l++;}
				if(str[ty][tx]=='P'){ fl[y][x][1]++; p++;}
			}
		}
		lp=new int[1024*1024];
		pp=new int[1024*1024];
		
		FOR(y,H) FOR(x,W) {
			for(ty=y+1;ty<H+1;ty++) {
				for(tx=x+1;tx<W+1;tx++) {
					rect(x,y,tx,ty,&l,&p);
					lp[(x+y*32)*1024+tx+ty*32]=l;
					pp[(x+y*32)*1024+tx+ty*32]=p;
				}
			}
		}
		int best=-1;
		
		//c•ªŠ„
		int sp;
		int li[2000][2];
		for(sp=1;sp<H;sp++) {
			FOR(i,2000) li[i][0]=li[i][1]=-1;
			//ã
			FOR(y,sp) FOR(x,W) {
				for(ty=y+1;ty<sp+1;ty++) {
					for(tx=x+1;tx<W+1;tx++) {
						rect(x,y,tx,ty,&l,&p);
						if(li[1000+l-p][0] < l+p) li[1000+l-p][0]=l+p;
					}
				}
			}
			//
			for(y=sp;y<H;y++) FOR(x,W) {
				for(ty=y+1;ty<H+1;ty++) {
					for(tx=x+1;tx<W+1;tx++) {
						rect(x,y,tx,ty,&l,&p);
						if(li[1000+l-p][1] < l+p) li[1000+l-p][1]=l+p;
					}
				}
			}
			FOR(x,2000) if(li[x][0]>=0) FOR(y,2000) if(li[y][1]>=0 && abs(x+y-2000)<=maxDiff && li[x][0]+li[y][1]>best){
				best = li[x][0]+li[y][1];
			}
		}
		
		//‰¡•ªŠ„
		for(sp=1;sp<W;sp++) {
			FOR(i,2000) li[i][0]=li[i][1]=-1;
			//ã
			FOR(y,H) FOR(x,sp) {
				for(ty=y+1;ty<H+1;ty++) {
					for(tx=x+1;tx<sp+1;tx++) {
						rect(x,y,tx,ty,&l,&p);
						if(li[1000+l-p][0] < l+p){
							li[1000+l-p][0]=l+p;
						}
					}
				}
			}
			//
			FOR(y,H) for(x=sp;x<W;x++) {
				for(ty=y+1;ty<H+1;ty++) {
					for(tx=x+1;tx<W+1;tx++) {
						rect(x,y,tx,ty,&l,&p);
						if(li[1000+l-p][1] < l+p){
							li[1000+l-p][1]=l+p;
						}
					}
				}
			}
			FOR(x,2000) if(li[x][0]>=0) FOR(y,2000) if(li[y][1]>=0 && abs(x+y-2000)<=maxDiff && li[x][0]+li[y][1]>best){
				best = li[x][0]+li[y][1];
			}
		}
		
		return best;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"LLL",
 "PPP",
 "LLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 7; verify_case(0, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"LLL",
 "PPP",
 "LLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 6; verify_case(1, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"...",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(2, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"LLPL.LPP",
 "PLPPPPLL",
 "L.P.PLLL",
 "LPL.PP.L",
 ".LLL.P.L",
 "PPLP..PL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 38; verify_case(3, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = -1; verify_case(4, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"LLLP..LLP.PLL.LL..LP",
 "L.PL.L.LLLL.LPLLPLP.",
 "PLL.LL.LLL..PL...L..",
 ".LPPP.PPPLLLLPLP..PP",
 "LP.P.PPL.L...P.L.LLL",
 "L..LPLPP.PP...PPPL..",
 "PP.PLLL.LL...LP..LP.",
 "PL...P.PPPL..PLP.L..",
 "P.PPPLPLP.LL.L.LLLPL",
 "PLLPLLP.LLL.P..P.LPL",
 "..LLLPLPPPLP.P.LP.LL",
 "..LP..L..LLPPP.LL.LP",
 "LPLL.PLLPPLP...LL..P",
 "LL.....PLL.PLL.P....",
 "LLL...LPPPPL.PL...PP",
 ".PLPLLLLP.LPP...L...",
 "LL...L.LL.LLLPLPPPP.",
 "PLPLLLL..LP.LLPLLLL.",
 "PP.PLL..L..LLLPPL..P",
 ".LLPL.P.PP.P.L.PLPLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 208; verify_case(5, Arg2, theMaxFlowers(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  FoxAndFlowerShopDivOne ___test;
  ___test.run_test(-1);
}
// END CUT HERE
