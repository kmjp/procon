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


class FencingPenguinsEasy {
	public:
	int ok[250][250];
	ll R;
	int NP;
	vector< int > hull, X, Y;
		
	int right(int f,int t) {
		int i;
		double PI = atan(1)*4;
		double fx = R*cos(2*PI*(f/(double)NP));
		double fy = R*sin(2*PI*(f/(double)NP));
		double tx = R*cos(2*PI*(t/(double)NP));
		double ty = R*sin(2*PI*(t/(double)NP));
		
		FOR(i,X.size()) if((X[i]-fx)*(ty-fy)-(Y[i]-fy)*(tx-fx)>0) return 0;
		return 1;
	}
	
	double minarea(int s) {
		int x,y;
		double area[300];
		
		area[s]=0;
		
		for(x=1;x<=NP;x++) {
			area[(s+x)%NP]=1e30;
			if(x==NP) area[s]=1e30;
			for(y=1;y<=x;y++) {
				int c = (s+x)%NP, p=(s+x-y)%NP;
				if(!ok[p][c]) continue;
				area[c] = min(area[c], area[p] + R*R*sin(2*atan(1)*4*(y%NP)/NP)/2.0);
			}
		}
		return area[s];
	}

	double calculateMinArea(int np, int radius, vector <int> X_, vector <int> Y_) {
		int i,x,y;
		R=radius; NP=np;
		X=X_; Y=Y_;
		
		FOR(x,NP) FOR(y,NP) if(x!=y) ok[x][y]=right(x,y);
		double mi = 1e30;
		FOR(x,NP) mi = min(mi, minarea(x));
		if(mi>=1e29) return -1;
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (abs(Expected-Received)<1e-6) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; _P("%.8lf %.8lf\n",Expected, Received);} }
	void test_case_0() { int Arg0 = 3; int Arg1 = 5; int Arr2[] = {-1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 32.47595264191645; verify_case(0, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 30; int Arg1 = 5; int Arr2[] = {6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = -1.0; verify_case(1, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 5; int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 25.0; verify_case(2, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 5; int Arr2[] = {2,-2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,-1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 50.0; verify_case(3, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 8; int Arg1 = 5; int Arr2[] = {8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {8}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = -1.0; verify_case(4, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 7; int Arg1 = 10; int Arr2[] = {9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 29.436752637711805; verify_case(5, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arg0 = 30; int Arg1 = 800; int Arr2[] = {8,2,100,120,52,67,19,-36}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-19,12,88,-22,53,66,-140,99}
; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 384778.74757953023; verify_case(6, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  FencingPenguinsEasy ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
