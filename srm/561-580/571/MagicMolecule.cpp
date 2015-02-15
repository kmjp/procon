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


class MagicMolecule {
	int N,M;
	vector<int> P;
	vector<string> B;
	public:
	int dfs(ll bmask,int left) {
		int ret=0,x,y;
		
		if(left<0) return -1;
		
		FOR(x,N) for(y=x+1;y<N;y++) {
			if((bmask & (1LL<<x)) && (bmask & (1LL<<y)) && B[x][y]=='N') {
				return max(dfs(bmask ^ (1LL<<x),left-1),dfs(bmask ^ (1LL<<y),left-1));
			}
		}
		
		ret = 0;
		FOR(x,N) if(bmask & (1LL<<x)) ret+=P[x];
		return ret;
	}
	
	int maxMagicPower(vector <int> mP, vector <string> mB) {
		int x,y;
		M=N=mP.size();
		P=mP;
		B=mB;
		while(3*(M-1)>=2*N) M--;
		
		return (int)dfs((1LL<<N)-1,N-M);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYY","YNN","YNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, maxMagicPower(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNYY","NNYY","YYNN","YYNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(1, Arg2, maxMagicPower(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {86,15,100,93,53,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYYYYN","YNNNNY","YNNYYN","YNYNYN","YNYYNY","NYNNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 332; verify_case(2, Arg2, maxMagicPower(Arg0, Arg1)); }
	void test_case_23() { int Arr0[] = {3969,9430,7242,8549,8190,8368,3704,9740,1691}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYYYYYYYY","YNYYYYYYY","YYNYYYYYY","YYYNYYYYY","YYYYNYYYY","YYYYYNYYY","YYYYYYNNY","YYYYYYNNY","YYYYYYYYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 57179; verify_case(3, Arg2, maxMagicPower(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {6600, 7710, 1995, 2428, 786, 99, 2531, 1766, 5764, 7145, 5073, 8898, 9502, 5869, 902, 2698, 4050, 6032, 3878, 6866, 6707, 8163, 1052, 7947, 511, 9198, 7083, 406, 9887, 4935, 4199, 6620, 4156, 8913, 2581, 3422, 1988, 9539, 6305, 9849, 6717, 5691, 8479, 5420, 1770}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYNYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYNYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYY", "YYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYNYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYNYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYNYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYNYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYNYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYNYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYY", "YYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYNYNYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYNYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 209789; verify_case(3, Arg2, maxMagicPower(Arg0, Arg1)); }
// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  MagicMolecule ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
