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

int dpdp[55][2300];

class TypoCoderDiv1 {
	public:
	int getmax(vector <int> D, int X) {
		int i,x,y,j;
		int L=D.size();
		
		FOR(i,L+1) FOR(x,2300) dpdp[i][x]=-999999;
		dpdp[0][X]=0;
		
		FOR(i,L) FOR(x,2200) {
			if(dpdp[i][x]<0) continue;
			
			dpdp[i+1][max(0,x-D[i])] = max(dpdp[i+1][max(0,x-D[i])], dpdp[i][x]);
			
			ll af=x+D[i];
			if(af<2200) {
				dpdp[i+1][af] = max(dpdp[i+1][af], dpdp[i][x]);
			}
			else {
				if(i+1<L) {
					af=max(0LL,af-D[i+1]);
					if(af<2200) dpdp[i+2][af] = max(dpdp[i+2][af], dpdp[i][x]+2);
				}
				else {
					dpdp[L][2200] = max(dpdp[L][2200], dpdp[i][x]+1);
				}
			}
		}
		int r=0;
		FOR(i,2201) r=max(r,dpdp[L][i]);
		return r;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100,200,100,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2000; int Arg2 = 3; verify_case(0, Arg2, getmax(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2199; int Arg2 = 0; verify_case(1, Arg2, getmax(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {90000,80000,70000,60000,50000,40000,30000,20000,10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(2, Arg2, getmax(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1000000000,1000000000,10000,100000,2202,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 4; verify_case(3, Arg2, getmax(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2048,1024,5012,256,128,64,32,16,8,4,2,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2199; int Arg2 = 0; verify_case(4, Arg2, getmax(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {61,666,512,229,618,419,757,217,458,883,23,932,547,679,565,767,513,798,870,31,379,294,929,892,173,127,796,353,913,115,802,803,948,592,959,127,501,319,140,694,851,189,924,590,790,3,669,541,342,272}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1223; int Arg2 = 29; verify_case(5, Arg2, getmax(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {34,64,43,14,58,30,2,16,90,58,35,55,46,24,14,73,96,13,9,42,64,36,89,42,42,64,52,68,53,76,52,54,23,88,32,52,28,96,70,32,26,3,23,78,47,23,54,30,86,32}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1328; int Arg2 = 20; verify_case(6, Arg2, getmax(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TypoCoderDiv1 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

