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

ll aa[100000],cc[100000];
class BigFatInteger2 {
	public:
	string isDivisible(int A, int B, int C, int D) {
		int i,j,k;
		NP=0;
		cprime();
		ZERO(aa);
		ZERO(cc);
		FOR(i,NP) if(A%prime[i]==0) {
			while(A%prime[i]==0) A/=prime[i],aa[i]+=B;
		}
		FOR(i,NP) if(C%prime[i]==0) {
			while(C%prime[i]==0) C/=prime[i],cc[i]+=D;
		}
		
		if(A!=C && C!=1) return "not divisible";
		if(A!=1) aa[99999]=B;
		if(C!=1) cc[99999]=D;
		FOR(i,100000) if(aa[i]<cc[i]) return "not divisible";
		return "divisible";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 2; int Arg3 = 1; string Arg4 = "divisible"; verify_case(0, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 6; int Arg3 = 1; string Arg4 = "not divisible"; verify_case(1, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1000000000; int Arg1 = 1000000000; int Arg2 = 1000000000; int Arg3 = 200000000; string Arg4 = "divisible"; verify_case(2, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 100; int Arg2 = 4; int Arg3 = 200; string Arg4 = "not divisible"; verify_case(3, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 999999937; int Arg1 = 1000000000; int Arg2 = 999999929; int Arg3 = 1; string Arg4 = "not divisible"; verify_case(4, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 4; int Arg3 = 1; string Arg4 = "divisible"; verify_case(5, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BigFatInteger2 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

