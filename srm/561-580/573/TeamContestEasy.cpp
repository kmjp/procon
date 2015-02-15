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


class TeamContestEasy {
	int N;
	vector<int> S;
	public:
	int worstRank(vector <int> strength) {
		S.clear();
		N=strength.size();
		int i,ms;
		
		ms=strength[0]+strength[1]+strength[2] - min(min(strength[0],strength[2]),strength[1]);
		int rank=1;
		for(i=3;i<N;i++) S.push_back(strength[i]);
		sort(S.begin(),S.end());
		reverse(S.begin(),S.end());
		int vis[50];
		ZERO(vis);
		
		N-=3;
		int j,m;
		FOR(i,N-1) {
			if(vis[i]) continue;
			for(j=N-1;j>i;j--) {
				if(vis[j]) continue;
				if(S[i]+S[j]<=ms) continue;
				vis[i]=vis[j]=1;
				int k;
				for(k=N-1;k>i;k--) {
					if(vis[k]==0) {
						vis[k]=1;
						rank++;
						goto nex;
					}
				}
				
			}
			nex:
			;
		}
		return rank;
		
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 7, 3, 5, 7, 3, 5, 7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, worstRank(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, worstRank(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, worstRank(Arg0)); }
	void test_case_3() { int Arr0[] = {2,2,1,1,3,1,3,2,1,3,1,2,1,2,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, worstRank(Arg0)); }
	void test_case_4() { int Arr0[] = {45,72,10,42,67,51,33,21,8,51,17,72}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, worstRank(Arg0)); }
	void test_case_5() { int Arr0[] = {570466,958327,816467,17,403,953808,734850,5824,917784,921731,161921,1734,823437,3218,81,932681,2704,981643,1232,475,873323,6558,45660,1813,4714,224,
32301,28081,6728,17055,561,15146,842613,5559,1860,783,989,2811,20664,112531,1933,866794,805528,53821,2465,137385,39,2007}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(5, Arg1, worstRank(Arg0)); }
	void test_case_6() { int Arr0[] = {610297,849870,523999,6557,976530,731458,7404,795100,147040,110947,159692,40785,4949,2903,1688,37278,620703,28156,16823,1159,12132,971379,5916,1159,988589,
12215,133,1490,911360,920059,544070,40249,514852,852,745070,1105,715897,714696,589133,698317,5683,631612,16453,101000,764881,101,2053,754661}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(6, Arg1, worstRank(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  TeamContestEasy ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
