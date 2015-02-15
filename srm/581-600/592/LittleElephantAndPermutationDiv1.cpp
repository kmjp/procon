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

ll dpdp[2][51][2511];
ll mo=1000000007;

class LittleElephantAndPermutationDiv1 {
	public:
	int getNumber(int N, int K) {
		int i,s2,s1,tot=0,k;
		
		ZERO(dpdp);
		dpdp[0][N][0]=1;
		FOR(i,N) {
			int cur=i%2,tar=(i+1)%2;
			ZERO(dpdp[tar]);
			int j=N-i;
			FOR(k,tot+1) {
				for(s2=0;s2<=N;s2++) {
					if(dpdp[cur][s2][k]==0) continue;
					int s0=2*i-(N-s2);
					int s1=N-s2-s0;
					if(s0<0 || s0>N || s1<0 || s1>N) continue;
					//_P("%d %d %d %d %d : %lld\n",i,k,s0,s1,s2,dpdp[cur][s2][k]);
					
					if(s2>=1)          dpdp[tar][s2-1][k+j]   = (dpdp[tar][s2-1][k+j]   + s2*dpdp[cur][s2][k]) % mo; // s2
					if(s2>=2)          dpdp[tar][s2-2][k+2*j] = (dpdp[tar][s2-2][k+2*j] + s2*(s2-1)*dpdp[cur][s2][k]) % mo; // s2,s2
					if(s2>=1 && s1>=1) dpdp[tar][s2-1][k+j]   = (dpdp[tar][s2-1][k+j]   + 2*s2*(s1/2)*dpdp[cur][s2][k]) % mo; // s2,s1
					if(s1>=2)          dpdp[tar][s2][k]       = (dpdp[tar][s2][k]       + (s1/2)*(s1/2)*dpdp[cur][s2][k]) % mo; // s1,s1
				}
			}
			tot=min(tot+2*j,2500);
		}
		
		ll r=0;
		for(i=K;i<=2500;i++) r+=dpdp[N%2][0][i];
		//FOR(i,N) r=(r*(i+1)) % mo;
		return (int)(r%mo);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 4; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 8; int Arg2 = 18; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 74; int Arg2 = 484682624; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 1000; int Arg2 = 539792695; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LittleElephantAndPermutationDiv1 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

