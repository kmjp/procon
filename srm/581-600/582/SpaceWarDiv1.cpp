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


class SpaceWarDiv1 {
	int M,E;
	vector<int> mg,es;
	vector<long long> ec;
	
	ll hoge[51];
	public:
	int okok(ll cur) {
		int i,j;
		vector<long long> e=ec;
		
		FOR(i,M) {
			ll le=cur;
			FOR(j,E) {
				if(es[j]<=mg[i]) {
					ll aa=min(le,e[j]);
					le-=aa;
					e[j]-=aa;
				}
			}
		}
		FOR(i,E) if(e[i]>0) return 0;
		return 1;
	}
	
	long long minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector<long long> enemyCount) {
		
		M=magicalGirlStrength.size();
		sort(magicalGirlStrength.begin(),magicalGirlStrength.end());
		E=enemyStrength.size();
		
		mg=magicalGirlStrength;
		es=enemyStrength;
		ec=enemyCount;
		
		int i,j,x,y;
		FOR(i,E) if(enemyStrength[i]>magicalGirlStrength[M-1]) return -1;
		ZERO(hoge);
		FOR(x,M) {
			FOR(y,E) {
				if(magicalGirlStrength[x]>=enemyStrength[y]) {
					hoge[x]+=enemyCount[y];
					enemyCount[y]=0;
				}
			}
		}
		
		ll lo=0,hi=1LL<<60;
		FOR(i,65) {
			ll pi=(hi+lo)/2;
			if(okok(pi)) {
				hi=pi;
			}
			else {
				lo=pi+1;
			}
		}
		
		lo=max(lo-5,0LL);
		while(1) {
			if(okok(lo)) return lo;
			lo++;
		}
		
		return 0;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {2, 9, 4}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 7LL; verify_case(0, Arg3, minimalFatigue(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {2, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {2, 9, 4}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(1, Arg3, minimalFatigue(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {14, 6, 22}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 33}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {9, 1}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = -1LL; verify_case(2, Arg3, minimalFatigue(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {869, 249, 599, 144, 929, 748, 665, 37, 313, 99, 33, 437, 308, 137, 665, 834, 955, 958, 613, 417}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {789, 57, 684, 741, 128, 794, 542, 367, 937, 739, 568, 872, 127, 261, 103, 763, 864, 360, 618, 307}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arr2[] = {20626770196420LL, 45538527263992LL, 52807114957507LL, 17931716090785LL, 65032910980630LL, 88711853198687LL, 26353250637092LL,
 61272534748707LL, 89294362230771LL, 52058590967576LL, 60568594469453LL, 23772707032338LL, 43019142889727LL, 39566072849912LL,
 78870845257173LL, 68135668032761LL, 36844201017584LL, 10133804676521LL, 6275847412927LL, 37492167783296LL}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 75030497287405LL; verify_case(3, Arg3, minimalFatigue(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  SpaceWarDiv1 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
