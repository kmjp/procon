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

ll X[200001];
ll Y[200001];
pair<ll,ll> P[200001];
ll mi[200001];
set<pair<ll,int> > PS;

class PilingRectsDiv1 {
	public:
	long long getmax(int N, vector <int> XS, vector <int> YS, int XA, int XB, int XC, int YA, int YB, int YC) {
		int i,L=XS.size();
		FOR(i,L) X[i]=XS[i],Y[i]=YS[i];
		for(i=L;i<2*N;i++) {
			X[i] = (X[i - 1] * XA + XB) % XC + 1;
		    Y[i] = (Y[i - 1] * YA + YB) % YC + 1;
		}
		FOR(i,2*N) {
			if(X[i]<Y[i]) swap(X[i],Y[i]);
			P[i].first = X[i];
			P[i].second = Y[i];
		}
		sort(P,P+2*N);
		mi[0]=P[0].second;
		FOR(i,2*N-1) mi[i+1] = min(mi[i],P[i+1].second);
		
		PS.clear();
		FOR(i,N) PS.insert(make_pair(P[i+N].second, i+N));
		
		int dr=N-1;
		ll ret = P[N].first * PS.begin()->first + mi[dr]*P[0].first;
		FOR(i,N-1) {
			if(PS.begin()->first < P[N-1-i].second) {
				dr=max(dr,PS.begin()->second);
				PS.erase(PS.begin());
				PS.insert(make_pair(P[N-1-i].second, N-1-i));
				ll ret2 = P[N-1-i].first * PS.begin()->first + mi[dr]*P[0].first;
				ret = max(ret,ret2);
			}
		}
		
		// 0
		if(PS.begin()->first < P[0].second) {
			dr=max(dr,PS.begin()->second);
			PS.erase(PS.begin());
			PS.insert(make_pair(P[0].second, N-1-i));
			ll ret2 = P[0].first * PS.begin()->first;
			int vis[200001];
			ZERO(vis);
			ITR(it,PS) vis[it->second]++;
			FOR(i,2*N) if(vis[i]==0) {
				ret2 += mi[dr]*P[i].first;
				break;
			}
			ret = max(ret,ret2);
		}
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,5,3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 0; int Arg5 = 1; int Arg6 = 0; int Arg7 = 0; int Arg8 = 1; long long Arg9 = 14LL; verify_case(0, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {7,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9; int Arg4 = 0; int Arg5 = 10; int Arg6 = 2; int Arg7 = 7; int Arg8 = 9; long long Arg9 = 56LL; verify_case(1, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {5,6,9,10,4,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {9,5,8,6,8,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 0; int Arg5 = 1; int Arg6 = 0; int Arg7 = 0; int Arg8 = 1; long long Arg9 = 69LL; verify_case(2, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_3() { int Arg0 = 10000; int Arr1[] = {1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000000000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 93827162; int Arg4 = 91238127; int Arg5 = 98231267; int Arg6 = 92138287; int Arg7 = 98563732; int Arg8 = 99381279; long long Arg9 = 1240119561532788LL; verify_case(3, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {375,571,973,896,460,930,583,530,657,590}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {284,37,994,699,941,745,166,884,270,708}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 428; int Arg4 = 1000; int Arg5 = 788; int Arg6 = 851; int Arg7 = 125; int Arg8 = 894; long long Arg9 = 420515LL; verify_case(4, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_5() { int Arg0 = 34734; int Arr1[] = {898,579,465,665,875,391,583,901,326,133,656,562,701,707,492,617,455,441,382,952,689,656,334,877,120,318,497,25,569,962,845,562,632,898,882,498,595,889,382,507,791,548,810,606,105,869,569,970,322,974}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {83,18,492,27,339,622,851,915,464,347,287,210,282,166,976,167,968,769,14,383,454,983,319,165,185,315,795,851,124,287,846,745,19,639,894,828,540,420,147,452,501,670,466,554,166,1,446,808,508,172}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 569; int Arg4 = 185; int Arg5 = 285; int Arg6 = 741; int Arg7 = 304; int Arg8 = 296; long long Arg9 = 10050LL; verify_case(5, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PilingRectsDiv1 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

