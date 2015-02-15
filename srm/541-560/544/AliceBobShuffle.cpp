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

ll dp[51][51][51];
ll mo=1000000007;
class AliceBobShuffle {
	public:
	int countWays(vector <int> AS, vector <int> BS, vector <int> AE, vector <int> BE) {
		int i,asi,bsi,aei,bei;
		map<int,int> nc;
		ITR(it,AS) nc[*it]++;
		ITR(it,BS) nc[*it]++;
		ITR(it,AE) nc[*it]--;
		ITR(it,BE) nc[*it]--;
		ITR(it,nc) if(it->second) return 0;
		ZERO(dp);
		int asl=AS.size(),bsl=BS.size();
		int ael=AE.size(),bel=BE.size(),nn=asl+bsl;
		
		dp[asl][bsl][0]=1;
		for(asi=asl;asi>=0;asi--) for(bsi=bsl;bsi>=0;bsi--) {
			for(aei=0;aei<=ael;aei++) {
				bei = nn-asi-bsi-aei;
				if(bei<0 || bei>bel) continue;
				if(dp[asi][bsi][aei]==0) continue;
				if(asi>0 && aei<ael && AS[asi-1]==AE[ael-1-aei]) 
					dp[asi-1][bsi][aei+1] = (dp[asi-1][bsi][aei+1] + dp[asi][bsi][aei]) % mo;
				if(bsi>0 && aei<ael && BS[bsi-1]==AE[ael-1-aei]) 
					dp[asi][bsi-1][aei+1] = (dp[asi][bsi-1][aei+1] + dp[asi][bsi][aei]) % mo;
				if(asi>0 && bei<bel && AS[asi-1]==BE[bel-1-bei]) 
					dp[asi-1][bsi][aei] = (dp[asi-1][bsi][aei] + dp[asi][bsi][aei]) % mo;
				if(bsi>0 && bei<bel && BS[bsi-1]==BE[bel-1-bei]) 
					dp[asi][bsi-1][aei] = (dp[asi][bsi-1][aei] + dp[asi][bsi][aei]) % mo;
			}
		}
		
		return dp[0][0][ael];
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(0, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(1, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(2, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(3, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {3, 3, 2, 4, 1, 3, 1, 2, 1, 1, 5, 5, 1, 2, 3, 1, 2, 1, 2, 1, 1, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 1, 4, 3, 4, 4, 4, 3, 2, 1, 6, 2, 2, 3, 2, 2, 1, 3, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 1, 4, 3, 4, 4, 4, 1, 3, 1, 2, 2, 2, 3, 2, 1, 2, 1, 2, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 3, 2, 3, 4, 2, 1, 2, 1, 1, 5, 6, 5, 1, 3, 1, 2, 3, 1, 1, 1, 3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 314159265; verify_case(4, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AliceBobShuffle ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

