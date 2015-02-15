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

int NP,prime[100000];
const int prime_max = 1000000;
void cprime() {
	static int p[prime_max];
	int i,j;
	for(i=2;i<prime_max;i++) {
		if(p[i]) continue;
		prime[NP++]=i;
		for(j=i*2;j<prime_max;j+=i) p[j]=i;
	}
}
int nf[100001];

class FractionInDifferentBases {
	public:
	long long getNumberOfGoodBases(long long P, long long Q, long long A, long long B) {
		if(P==0) return 0;
		
		NP=0;
		cprime();
		
		ll g=__gcd(P,Q);
		P/=g;
		Q/=g;
		
		int i;
		ll pr=1;
		ZERO(nf);
		FOR(i,NP) {
			while((Q%prime[i])==0) nf[i]++,Q/=prime[i];
			if(nf[i]) pr*= prime[i];
		}
		pr*=Q;
		if(Q>1) prime[NP++] = Q,nf[NP-1]++;
		
		return (B-B/pr)-((A-1)-(A-1)/pr);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 2LL; long long Arg2 = 10LL; long long Arg3 = 10LL; long long Arg4 = 0LL; verify_case(0, Arg4, getNumberOfGoodBases(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 9LL; long long Arg2 = 9LL; long long Arg3 = 10LL; long long Arg4 = 1LL; verify_case(1, Arg4, getNumberOfGoodBases(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 5LL; long long Arg1 = 6LL; long long Arg2 = 2LL; long long Arg3 = 10LL; long long Arg4 = 8LL; verify_case(2, Arg4, getNumberOfGoodBases(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 2662LL; long long Arg1 = 540LL; long long Arg2 = 2LL; long long Arg3 = 662LL; long long Arg4 = 639LL; verify_case(3, Arg4, getNumberOfGoodBases(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { long long Arg0 = 650720LL; long long Arg1 = 7032600LL; long long Arg2 = 2012LL; long long Arg3 = 2012540LL; long long Arg4 = 2010495LL; verify_case(4, Arg4, getNumberOfGoodBases(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FractionInDifferentBases ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

