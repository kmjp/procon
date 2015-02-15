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

class MysticAndCandies {
	public:
	int minBoxes(int C, int X, vector <int> low, vector <int> high) {
		vector<pair<int,int> > P;
		int i,j;
		int LT=0;
		int N=low.size(),mi=low.size();
		FOR(i,N) C-=low[i];
		
		FOR(i,N) P.push_back(make_pair(high[i],low[i]));
		
		sort(P.begin(),P.end());
		reverse(P.begin(),P.end());
		for(i=1;i<=N;i++) {
			int lt=0,dt=0;
			FOR(j,i) lt+=P[j].second;
			for(j=i;j<N;j++) dt+=P[j].first-P[j].second;
			dt=min(dt,C);
			if(lt+(C-dt)>=X) mi=min(mi,i);
		}
		
		FOR(i,N) P[i]=make_pair(low[i],high[i]);
		sort(P.begin(),P.end());
		reverse(P.begin(),P.end());
		for(i=1;i<=N;i++) {
			int lt=0,dt=0;
			FOR(j,i) lt+=P[j].first;
			for(j=i;j<N;j++) dt+=P[j].second-P[j].first;
			dt=min(dt,C);
			if(lt+(C-dt)>=X) mi=min(mi,i);
		}
		return mi;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 15; int Arg1 = 12; int Arr2[] = {1, 2, 3, 4, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 2, 3, 4, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(0, Arg4, minBoxes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 60; int Arg1 = 8; int Arr2[] = {5, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {49, 48, 47}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(1, Arg4, minBoxes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 58; int Arg1 = 30; int Arr2[] = {3, 9, 12, 6, 15}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {8, 12, 20, 8, 15}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(2, Arg4, minBoxes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 207581165; int Arg1 = 172146543; int Arr2[] = {4725448, 2753824, 6019698, 4199708, 4070001, 3589497, 5358499, 3637585, 5393667, 2837466,
2747807, 2918199, 3638042, 5199002, 3072044, 3858909, 3762101, 3657754, 3218704, 3888861,
3195689, 4768935, 3137633, 4124272, 4125056, 6087486, 3632970, 3620489, 2748765, 5917493,
3958996, 3335021, 3517186, 5543440, 2951006, 3403270, 3299481, 3093204, 4092331}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5702812, 6805664, 6823687, 5337687, 4286533, 4999849, 6567411, 4563235, 6618139, 6260135,
6249469, 3821449, 5963157, 6385012, 4255959, 5786920, 6112817, 4103918, 6371537, 4231698,
3409172, 6806782, 5623563, 4511221, 6407338, 6491490, 5209517, 6076093, 6530132, 6111464,
5833839, 6253088, 5595160, 6236805, 5772388, 5285713, 5617002, 4650978, 5234740}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 31; verify_case(3, Arg4, minBoxes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 43873566; int Arg1 = 32789748; int Arr2[] = {2053198, 2175819, 4260803, 1542497, 1418952, 5000015, 1381849, 2462882, 6466891, 1827580, 6943641, 5775477}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2827461, 3726335, 5410505, 4781355, 4925909, 5621160, 7325774, 5025476, 7876037, 8072075, 6979462, 6647628}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 7; verify_case(4, Arg4, minBoxes(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MysticAndCandies ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

