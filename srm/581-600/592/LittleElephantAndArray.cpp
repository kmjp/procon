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
vector<ll> S[2];
ll dpdp[2][100000];

class LittleElephantAndArray {
	public:
	ll p10[20];
	vector<ll > create(ll V) {
		static ll prev=-1;
		static vector<ll> SV;
		int i,x;
		
		if(prev!=V/10) {
			ll t=V/10;
			int d=0,ma;
			SV.clear();
			while(t) t/=10,d++;
			for(int ma=1;ma<1<<d;ma++) {
				ll v=0;
				int nd=0,cd;
				FOR(cd,d) if(ma & (1<<cd)) v+=((V/10/p10[cd])%10)*p10[nd++];
				SV.push_back(v);
			}
			prev=V/10;
		}
		
		vector<ll> RV;
		FOR(i,SV.size()) RV.push_back(SV[i]),RV.push_back(SV[i]*10+V%10);
		RV.push_back(V%10);
		
		sort(RV.begin(),RV.end());
		return RV;
	}
	
	int getNumber(long long A, int N) {
		int i,x,y;
		p10[0]=1;
		FOR(i,15) p10[i+1]=p10[i]*10;
		
		S[0]=create(A);
		FOR(i,S[0].size()) dpdp[0][i]=1;
		
		FOR(i,N) {
			int cur=i%2,tar=(i+1)%2;
			S[tar]=create(A+i+1);
			
			for(x=1;x<S[cur].size();x++) dpdp[cur][x] = ( dpdp[cur][x]+dpdp[cur][x-1]) % mo;
			ZERO(dpdp[tar]);
			
			FOR(x,S[tar].size()) {
				vector<ll>::iterator vit=upper_bound(S[cur].begin(),S[cur].end(),S[tar][x]);
				if(vit!=S[cur].begin()) dpdp[tar][x] = dpdp[cur][vit-S[cur].begin()-1];
			}
		}
		
		ll ret=0;
		FOR(i,S[N%2].size()) ret+=dpdp[N%2][i];
		return (int)(ret%mo);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; int Arg1 = 9; int Arg2 = 1; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 10LL; int Arg1 = 2; int Arg2 = 15; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 4747774LL; int Arg1 = 1; int Arg2 = 8369; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_32() { long long Arg0 = 6878542150015LL; int Arg1 = 74; int Arg2 = 977836619; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 1000000000000000; int Arg1 = 100; int Arg2 = 22435455; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LittleElephantAndArray ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

