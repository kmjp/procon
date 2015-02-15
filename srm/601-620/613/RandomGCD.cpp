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

int NP,prime[100000];
const int prime_max = 100000;
void cprime(int hoge) {
	static int p[prime_max];
	int i,j;
	NP=0;
	for(i=2;i<hoge;i++) {
		if(p[i]) continue;
		prime[NP++]=i;
		for(j=i*2;j<hoge;j+=i) p[j]=i;
	}
}

ll modpow(ll a, ll n) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}
int vis[100001];

class RandomGCD {
	public:
	
	
	int countTuples(int N, int K, int low, int high) {
		low=(low+(K-1))/K;
		high=high/K;
		if(low>high) return 0;
		cprime(high-low+1);
		int i,j;

		ll ret=0;
		for(i=1;i<=high-low;i++) {
			int nd=1,xx=i;
			int lo=(low+(i-1))/i;
			int hi=high/i;
			if(hi<lo) continue;
			
			int ng=0;
			FOR(j,NP) {
				
				if(xx<prime[j] || ng) break;
				if(xx%prime[j]==0) {
					int ii=0;
					nd=-nd;
					while(xx%prime[j]==0) xx/=prime[j],ii++;
					if(ii>1) ng++;
				}
			}
			if(ng) continue;
			if(xx>1) nd=-nd;
			ret=(ret+mo+nd*(modpow(hi-lo+1,N)-(hi-lo+1)))%mo;
		}
		
		if(low==1) ret++;
		
		ret %= mo;
		
		return (int)ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 4; int Arg4 = 3; verify_case(0, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 100; int Arg2 = 2; int Arg3 = 4; int Arg4 = 0; verify_case(1, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 5; int Arg3 = 5; int Arg4 = 1; verify_case(2, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 73824; int Arg1 = 17347; int Arg2 = 9293482; int Arg3 = 9313482; int Arg4 = 0; verify_case(3, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 222; int Arg1 = 222; int Arg2 = 222; int Arg3 = 22222; int Arg4 = 339886855; verify_case(4, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
//	void test_case_4() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 5; int Arg3 = 5; int Arg4 = 1; verify_case(4, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RandomGCD ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

