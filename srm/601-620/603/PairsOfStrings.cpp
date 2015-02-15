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
ll modpow(ll a, ll n) {
	ll r=1;
	while(n) {
		if(n%2) r=(r*a)%mo;
		a=(a*a)%mo;
		n>>=1;
	}
	return r;
}

vector<ll> enumdiv(ll n) {
	set<ll> S;
	for(ll i=1;i*i<=n;i++) if(n%i==0) S.insert(i),S.insert(n/i); //include 1
	S.insert(n);
	return vector<ll>(S.begin(),S.end());
}

ll numnum[2000];

class PairsOfStrings {
	public:
	
	int getNumber(int n, int k) {
		ll ret=0;
		int x,y;
		
		vector<ll> S=enumdiv(n);
		FOR(x,S.size()) {
			numnum[x]=modpow(k,S[x]);
			FOR(y,x) if(S[x]%S[y]==0) numnum[x]+=mo-numnum[y];
			numnum[x]%=mo;
			ret = (ret+numnum[x]*S[x])%mo;
		}
		
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 6; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 20; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 184; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 2; int Arg2 = 348; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 26; int Arg2 = 46519912; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PairsOfStrings ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

