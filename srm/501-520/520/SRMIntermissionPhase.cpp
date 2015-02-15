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

ll mo=1000000007;
ll dp[22][200010];
ll pat[8][200010];
ll pat2[200010];

class SRMIntermissionPhase {
	public:
	int N;
	int countWays(vector <int> points, vector <string> description) {
		int i,j;
		int mi,ma;
		
		ZERO(pat);
		ZERO(pat2);
		pat[0][0]=1;
		FOR(i,200001) {
			if(1<=i && i<=points[0]) pat[1][i]=1;
			if(1<=i && i<=points[1]) pat[2][i]=1;
			if(1<=i && i<=points[2]) pat[4][i]=1;
			mi=max(1,i-points[1]),ma=min(points[0],i-1);
			if(mi<=ma) pat[3][i]=ma-mi+1;
			pat2[i+1]=pat2[i]+pat[3][i];
			mi=max(1,i-points[2]),ma=min(points[0],i-1);
			if(mi<=ma) pat[5][i]=ma-mi+1;
			mi=max(1,i-points[2]),ma=min(points[1],i-1);
			if(mi<=ma) pat[6][i]=ma-mi+1;
		}
		FOR(i,200001) {
			mi=max(1,i-points[2]),ma=i-1;
			if(mi<=ma) {
				pat[7][i]=pat2[ma+1]-pat2[mi];
			}
		}
		
		
		N=description.size();
		ZERO(dp);
		dp[0][200001]=1;
		FOR(i,N) {
			int cur=(description[i][0]=='Y')+(description[i][1]=='Y')*2+(description[i][2]=='Y')*4;
			ll tot=0;
			for(j=200001;j>=0;j--) {
				dp[i+1][j]=tot*pat[cur][j]%mo;
				tot=(tot+dp[i][j])%mo;
			}
		}
		
		ll tot=0;
		for(j=200001;j>=0;j--) tot+=dp[N][j];
		return (int)(tot%mo);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {25000, 50000, 100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YNN",
 "NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25000; verify_case(0, Arg2, countWays(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {30000, 60000, 90000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYN",
 "NYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 799969993; verify_case(1, Arg2, countWays(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {3, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNN",
 "YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, countWays(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {25600, 51200, 102400}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYY",
 "YNY",
 "YYY",
 "YNN",
 "YYN",
 "NNY",
 "NYN",
 "NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 867560805; verify_case(3, Arg2, countWays(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SRMIntermissionPhase ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

