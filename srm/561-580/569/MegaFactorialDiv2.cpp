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

int np;
ll prime[200];
const int prime_max = 1001;
void cprime() {
	int i,j;
	char p[prime_max];
	
	np=0;
	ZERO(p);
	for(i=2;i<prime_max;i++) {
		if(p[i]) continue;
		prime[np++]=i;
		for(j=i*2;j<prime_max;j+=i) p[j]=1;
	}
}

vector<int> dp[1001][101];
ll MO=1000000009;

class MegaFactorialDiv2 {
	public:
	int countDivisors(int N, int K) {
		int i,j,n,k;
		cprime();
		
		FOR(i,1001) {
			n=0;
			FOR(j,np) if(i%prime[j]==0) n=j;
			dp[i][0].resize(n+1);
			k=i;
			FOR(j,n+1) {
				dp[i][0][j]=0;
				if(k<prime[j]) break;
				while((k%prime[j])==0) {
					k /= prime[j];
					dp[i][0][j]++;
				}
			}
		}
		
		for(n=1;n<=1000;n++) for(k=1;k<=100;k++) {
			dp[n][k].resize(max(dp[n-1][k].size(),dp[n][k-1].size()));
			FOR(i,dp[n][k].size()) dp[n][k][i] = (
			((dp[n-1][k].size()>i)?dp[n-1][k][i]:0) + ((dp[n][k-1].size()>i)?dp[n][k-1][i]:0)) % MO;
		}
		
		ll res=1;
		FOR(i,dp[N][K].size()) {
			res = (res * (1LL+dp[N][K][i])) % MO;
		}
		return (int)res;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 4; verify_case(0, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 6; verify_case(1, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 18; verify_case(2, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 1392; verify_case(3, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 100; int Arg2 = 563680238; verify_case(4, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_42() { int Arg0 = 100; int Arg1 = 2; int Arg2 = 321266186; verify_case(4, Arg2, countDivisors(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  MegaFactorialDiv2 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
