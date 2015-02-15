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

int pr[51][51];

int NP,prime[100];
const int prime_max = 100;
void cprime() {
	static int p[prime_max];
	int i,j;
	for(i=2;i<prime_max;i++) {
		if(p[i]) continue;
		prime[NP++]=i;
		for(j=i*2;j<prime_max;j+=i) p[j]=i;
	}
}


class RelativelyPrimeSubset {
	set<int> M2;
	map<int,int> memo;
	public:
	int dpdp(int mask,int lb) {
		int i,r=0,ma=0;
		if(memo.find(mask)!=memo.end()) return memo[mask];
		ITR(it,M2) {
			if(mask & *it) continue;
			int lb2 = *it & (-*it);
			if(lb2<lb) continue;
			ma = max(ma,1+dpdp(mask | *it, lb2));
		}
		return memo[mask]=ma;
		
	}
	
	int findSize(vector <int> S) {
		int i,x,y,m,L=S.size(),has1=0;
		NP=0;
		cprime();
		
		set<int> M;
		FOR(i,L) {
			int ma=0;
			FOR(x,NP) if(S[i]%prime[x]==0) ma |= 1<<x;
			if(S[i]==1) has1=1;
			if(ma) M.insert(ma);
		}
		M2.clear();
		memo.clear();
		ITR(it,M) {
			x=0;
			if(__builtin_popcount(*it)==1 && *it>=1<<15) {
				has1++;
				continue;
			}
			ITR(it2,M2) if((*it2 | *it) == *it) x++;
			if(x==0) M2.insert(*it);
		}
		return dpdp(0,0) + has1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,3,7,11,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, findSize(Arg0)); }
	void test_case_1() { int Arr0[] = {4,8,12,16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, findSize(Arg0)); }
	void test_case_2() { int Arr0[] = {100,17,81,82}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, findSize(Arg0)); }
	void test_case_32() { int Arr0[] = {2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, findSize(Arg0)); }
	void test_case_3() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, findSize(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RelativelyPrimeSubset ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

