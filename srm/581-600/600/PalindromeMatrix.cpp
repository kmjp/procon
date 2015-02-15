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

int mm3[8][4][1<<14];
class PalindromeMatrix {
	public:
	int H,W;
	int mat[16][16];
	char mm2[8][8][16];
	int minChange(vector <string> A, int RC, int CC) {
		int y,x,ii,jj,res,t,i,yo1,yo2,xo1,xo2;
		int ym,xm;
		H=A.size();
		W=A[0].size();
		FOR(y,H/2) FOR(x,W/2) {
			mat[y][x]=(A[y][x]-'0')+(A[y][W-1-x]-'0')+(A[H-1-y][x]-'0')+(A[H-1-y][W-1-x]-'0');
		}
		res=H*W;
		vector<int> YM,XM;
		FOR(y,H/2) FOR(x,W/2) {
			int y2=H-1-y,x2=W-1-x;
			FOR(yo1,2) FOR(yo2,2) FOR(xo1,2) FOR(xo2,2) {
				int tr=0;
				if(yo1+yo2+xo1+xo2>=3) tr+=min(mat[y][x],4-mat[y][x]);
				else if(!xo1 && !xo2) {
					if(yo1) tr+=(A[y][x]!=A[y][x2]);
					if(yo2) tr+=(A[y2][x]!=A[y2][x2]);
				}
				else if(!yo1 && !yo2) {
					if(xo1) tr+=(A[y][x]!=A[y2][x]);
					if(xo2) tr+=(A[y][x2]!=A[y2][x2]);
				}
				else if(yo1&&xo1&&!yo2&&!xo2) t=A[y][x]+A[y2][x]+A[y][x2]-3*'0', tr+=min(t,3-t);
				else if(yo1&&xo2&&!yo2&&!xo1) t=A[y][x]+A[y2][x2]+A[y][x2]-3*'0', tr+=min(t,3-t);
				else if(yo2&&xo1&&!yo1&&!xo2) t=A[y2][x]+A[y2][x2]+A[y][x]-3*'0', tr+=min(t,3-t);
				else if(yo2&&xo2&&!yo1&&!xo1) t=A[y2][x2]+A[y][x2]+A[y2][x]-3*'0', tr+=min(t,3-t);
				mm2[y][x][yo1*8+yo2*4+xo1*2+xo2]=tr;
			}
		}
		ZERO(mm3);
		FOR(y,H/2) {
			FOR(ii,4) {
				FOR(xm,1<<W) {
					FOR(x,W/2) {
						int x2=W-1-x;
						int xo1=(xm>>x)&1;
						int xo2=(xm>>x2)&1;
						mm3[y][ii][xm]+=mm2[y][x][ii*4+xo1*2+xo2];
					}
				}
			}
		}
		
		
		FOR(i,1<<H) if(__builtin_popcount(i)==RC) YM.push_back(i);
		FOR(i,1<<W) if(__builtin_popcount(i)==CC) XM.push_back(i);
		FOR(ii,YM.size()) FOR(jj,XM.size()) {
			ym=YM[ii];xm=XM[jj];
			int tr=0;
			FOR(y,H/2) {
				int y2=H-1-y;
				int yo1=(ym>>y)&1;
				int yo2=(ym>>y2)&1;
				tr+=mm3[y][yo1*2+yo2][xm];
				/*
				FOR(x,W/2) {
					int x2=W-1-x;
					int xo1=(xm>>x)&1;
					int xo2=(xm>>x2)&1;
					tr+=mm2[y][x][yo1*8+yo2*4+xo1*2+xo2];
					if(tr>=res) break;
				}
				*/
				if(tr>=res) break;
			}
			res=min(res,tr);
		}
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0000"
,"1000"
,"1100"
,"1110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; verify_case(0, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0000"
,"1000"
,"1100"
,"1110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; int Arg3 = 3; verify_case(1, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"01"
,"10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; verify_case(2, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"1110"
,"0001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; verify_case(3, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; int Arg3 = 8; verify_case(4, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"000000000000"
,"011101110111"
,"010001010101"
,"010001010101"
,"011101010101"
,"010101010101"
,"010101010101"
,"011101110111"
,"000000000000"
,"000000000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 9; int Arg3 = 14; verify_case(5, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"11111101001110"
,"11000111111111"
,"00010101111001"
,"10110000111111"
,"10000011010010"
,"10001101101101"
,"00101010000001"
,"10111010100100"
,"11010011110111"
,"11100010110110"
,"00100101010100"
,"01001011001000"
,"01010001111010"
,"10100000010011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 6; int Arg3 = 31; verify_case(6, Arg3, minChange(Arg0, Arg1, Arg2)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PalindromeMatrix ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

