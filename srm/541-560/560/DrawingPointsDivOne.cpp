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


class DrawingPointsDivOne {
	public:
	int m[300][300];
	int cs[300][300];
	
	int check(int cstep) {
		int num[300][300];
		int num2[300][300];
		int x,y;
		ZERO(num);
		ZERO(num2);
		//yoko
		for(y=299;y>=0;y--) {
			for(x=299;x>=0;x--) {
				if(x==299) num[x][y]=cs[x][y];
				else if(cs[x][y]==0) num[x][y]=0;
				else num[x][y] = num[x+1][y]+1;
			}
		}
		//tate
		for(x=299;x>=0;x--) {
			for(y=299;y>=0;y--) {
				if(y==299) num2[x][y]=(num[x][y]>=cstep)?1:0;
				else if(num[x][y]<cstep) num2[x][y]=0;
				else num2[x][y] = num2[x][y+1]+1;
				int r=(num2[x][y]>=cstep)?1:0;
				if(r!=m[x][y]) return 0;
			}
		}
		return 1;
	}
	
	int test(int cstep) {
		int ns[300][300];
		int x,y;
		
		ZERO(ns);
		FOR(x,299) {
			FOR(y,299) {
				if(cs[x][y]) {
					ns[x][y]=ns[x+1][y+1]=ns[x+1][y]=ns[x][y+1]=1;
				}
			}
		}
		
		memcpy(cs,ns,sizeof(cs));
		return check(cstep+1);
	}
	
	int maxSteps(vector <int> x, vector <int> y) {
		int i;
		ZERO(m);
		ZERO(cs);
		FOR(i,x.size()) m[x[i]+70][y[i]+70]=cs[x[i]+70][y[i]+70]=1;
		
		
		int step=0;
		while(test(step+1)) {
			step++;
			if(step>150) return -1;
		}
		return step;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, maxSteps(Arg0, Arg1)); }
//	void test_case_1() { int Arr0[] = {0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, maxSteps(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, maxSteps(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-70}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, maxSteps(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-41,-40,1,-11,-32,-7,24,-11,49,-15,-22,20,-8,54,54,69,16,-30,36,-6,-30,40,64,20,-66,
 -37,-33,-18,-35,36,9,61,-43,45,5,60,-8,-58,65,-66,41,12,34,-11,-57,-38,46,63,-55,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,-24,-2,-4,23,14,1,70,-26,45,15,48,32,-41,54,-47,-67,-46,-9,-53,54,28,-61,11,53,68,
 -33,62,37,-8,-17,-17,48,19,-49,56,-41,16,17,-50,28,59,10,50,23,-16,56,31,-70,-44}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(3, Arg2, maxSteps(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  DrawingPointsDivOne ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
