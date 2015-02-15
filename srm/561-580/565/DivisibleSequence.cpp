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
#include <assert.h>
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
ll prime[100000];
const int prime_max = 1000001;
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

ll mod=1000000009;
ll rev(ll num) {
	ll pw = mod-2;
	ll ret = 1;
	for(ll i = 30; i >= 0; i--) {
		ret = (ret*ret)%mod;
		if((pw>>i)&1) ret = (ret*num)%mod;
	}
	return ret;
}

ll combi(ll N_, ll C_) {
	const int num=100;
	static ll rm[num+1];
	int i;
	ll res=1;
	if(rm[1]==0) for(i=1;i<=num;i++) rm[i]=rev(i);
	
	assert(C_<num);
	
	FOR(i,C_) {
		res = (res * rm[i+1])%mod;
		res = (res * (N_-i))%mod;
	}
	return res;
}


class DivisibleSequence {
	public:
	int count(int N, int H) {
		int i;
		cprime();
		ll res=1;
		
		if(H==1) return 1;
		FOR(i,np) {
			ll tres = 1;
			int nd=0;
			while(N%prime[i]==0){ N /= prime[i]; nd++; tres += combi(H+nd-2,nd);}
			res = (res*tres)%mod;
		}
		if(N>1) res = (res*H) % mod;

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 3; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 9; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 2; int Arg2 = 4; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 10000; int Arg2 = 1; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 30; int Arg1 = 4; int Arg2 = 64; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 25883; int Arg1 = 100000; int Arg2 = 991000009; verify_case(5, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 128; int Arg1 = 5; int Arg2 = 330; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  DivisibleSequence ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
