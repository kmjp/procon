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
int mask[100000];
int SZ[1030];
ll dp[1030];


class LittleElephantAndSubset {
	public:
	int N;
	
	ll dpdp(int mask) {
		int i,m;
		if(mask==0) return 1;
		if(dp[mask]>=0) return dp[mask];
		dp[mask]=0;
		m=1;
		while(m*2<=mask) m*=2;
		FOR(i,m) {
			if((mask & (m+i)) !=(m+i)) continue;
			if(SZ[m+i]==0) continue;
			dp[mask]+=SZ[m+i]*dpdp(mask ^ (m+i));
			dp[mask]%=mo;
		}
		return dp[mask];
	}
	
	void dfs(ll val,int mask) {
		int i;
		if(val>N) return;
		SZ[mask]++;
		FOR(i,10) if((mask & (1<<i))==0) dfs(val*10+i,mask | (1<<i));
	}
	
	int getNumber(int N) {
		int i,r=0;
		this->N=N;
		ZERO(SZ);
		
		for(i=1;i<=9;i++) dfs(i,1<<i);
		MINUS(dp);
		ll ret=mo-1;
		FOR(i,1024) ret+=dpdp(i);
		return (int)(ret%mo);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 999999999; int Arg1 = 7; verify_case(0, Arg1, getNumber(Arg0)); }
	//void test_case_0() { int Arg0 = 3; int Arg1 = 7; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 767; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { int Arg0 = 47; int Arg1 = 25775; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { int Arg0 = 4777447; int Arg1 = 66437071; verify_case(3, Arg1, getNumber(Arg0)); }

// END CUT HERE
};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LittleElephantAndSubset ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

