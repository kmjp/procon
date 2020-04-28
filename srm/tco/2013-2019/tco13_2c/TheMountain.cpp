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


class TheMountain {
	int mat[202][202];
	int dp[4][202][202];
	int dpt[4][202][202];
	public:
	int minSum(int H, int W, vector <int> rowIndex, vector <int> columnIndex, vector <int> element) {
		int i,x,y,z;
		int N=rowIndex.size();
		
		ZERO(mat);
		ZERO(dp);
		ZERO(dpt);
		FOR(i,N) mat[rowIndex[i]][columnIndex[i]]=element[i];
		
		
		// 右下
		dp[0][0][0]=max(1,mat[0][0]);
		for(i=1;i<=H+W-1;i++) {
			for(y=0,x=i;y<H&&x>=0;y++,x--) {
				if(x>=W) continue;
				z = 1+max((y==0)?0:dp[0][y-1][x], (x==0)?0:dp[0][y][x-1]);
				if(mat[y][x]==0) dp[0][y][x]=z;
				else if(z<=mat[y][x])  dp[0][y][x]=mat[y][x];
				else dp[0][y][x]=3000;
			}
		}
		//右上
		dp[1][H-1][0]=max(1,mat[H-1][0]);
		for(i=1;i<=H+W-1;i++) {
			for(y=H-1,x=i;y>=0&&x>=0;y--,x--) {
				if(x>=W) continue;
				z=1+max((y==H-1)?0:dp[1][y+1][x], (x==0)?0:dp[1][y][x-1]);
				if(mat[y][x]==0) dp[1][y][x]=z;
				else if(z<=mat[y][x])  dp[1][y][x]=mat[y][x];
				else dp[1][y][x]=3000;
			}
		}
		
		//左下
		dp[2][0][W-1]=max(1,mat[0][W-1]);
		for(i=1;i<=H+W-1;i++) {
			for(y=0,x=W-1-i;y<H&&x<W;y++,x++) {
				if(x<0) continue;
				z=1+max((y==0)?0:dp[2][y-1][x], (x==W-1)?0:dp[2][y][x+1]);
				if(mat[y][x]==0) dp[2][y][x]=z;
				else if(z<=mat[y][x])  dp[2][y][x]=mat[y][x];
				else dp[2][y][x]=3000;
			}
		}
		
		//左上
		dp[3][H-1][W-1]=max(1,mat[H-1][W-1]);
		for(i=1;i<=H+W-1;i++) {
			for(y=H-1,x=W-1-i;y>=0&&x<W;y--,x++) {
				if(x<0) continue;
				z=1+max((y==H-1)?0:dp[3][y+1][x], (x==W-1)?0:dp[3][y][x+1]);
				if(mat[y][x]==0) dp[3][y][x]=z;
				else if(z<=mat[y][x])  dp[3][y][x]=mat[y][x];
				else dp[3][y][x]=3000;
			}
		}
		
		FOR(y,H) {
			z=0;
			FOR(x,W) { z+=dp[0][y][x]; dpt[0][y][x]=z+((y==0)?0:dpt[0][y-1][x]);} //右下
			z=0;
			for(x=W-1;x>=0;x--) { z+=dp[2][y][x]; dpt[2][y][x]=z+((y==0)?0:dpt[2][y-1][x]);} //左下
		}
		for(y=H-1;y>=0;y--) {
			z=0;
			FOR(x,W) { z+=dp[1][y][x]; dpt[1][y][x]=z+((y==H-1)?0:dpt[1][y+1][x]);} //右上
			z=0;
			for(x=W-1;x>=0;x--) { z+=dp[3][y][x]; dpt[3][y][x]=z+((y==H-1)?0:dpt[3][y+1][x]);} //左上
		}
		
		int ma=1<<30;
		FOR(y,H) FOR(x,W) {
			if(dp[0][y][x]>=3000 || dp[1][y][x]>=3000 || dp[2][y][x]>=3000 || dp[3][y][x]>=3000) continue;
			int t=max(max(dp[0][y][x],dp[1][y][x]),max(dp[2][y][x],dp[3][y][x]));
			if(y<H-1 && x<W-1) t+=dpt[3][y+1][x+1];
			if(y>0 && x<W-1) t+=dpt[2][y-1][x+1];
			if(y<H-1 && x>0) t+=dpt[1][y+1][x-1];
			if(y>0 && x>0) t+=dpt[0][y-1][x-1];
			for(i=0;i<y;i++) t += max(dp[0][i][x],dp[2][i][x]); //上
			for(i=y+1;i<H;i++) t += max(dp[1][i][x],dp[3][i][x]); //下
			for(i=0;i<x;i++) t += max(dp[0][y][i],dp[1][y][i]); //右
			for(i=x+1;i<W;i++) t += max(dp[2][y][i],dp[3][y][i]); //左
			ma=min(ma,t);
		}
		
		if(ma==1<<30) return -1;
		return ma;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arr2[] = {0, 0, 0, 1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 1, 2, 0, 1, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {4, 6, 9, 1, 3, 6}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 29; verify_case(0, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arr2[] = {1, 0, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 2, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {5, 7, 6}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 40; verify_case(1, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {0, 0, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 2, 2, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 15; verify_case(2, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {0, 0, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 1, 1, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {5, 8, 5, 8}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = -1; verify_case(3, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 3; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = -1; verify_case(4, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 123; int Arg1 = 45; int Arr2[] = {2, 3, 5, 7, 11}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {13, 17, 19, 23, 29}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {100, 200, 300, 400, 500}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 367047; verify_case(5, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { int Arg0 = 200; int Arg1 = 200; int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {8}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {666}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 5737554; verify_case(6, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_7() { int Arg0 = 10; int Arg1 = 10; int Arr2[] = {0, 8, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 1, 9}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {5, 4, 7}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 593; verify_case(7, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  TheMountain ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
