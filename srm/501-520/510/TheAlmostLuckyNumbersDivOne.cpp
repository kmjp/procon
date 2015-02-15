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

ll numnum[16][2];


class TheAlmostLuckyNumbersDivOne {
	public:
	
	ll dodo2(ll val, int non0, int di,int nok) {
		ll p10=1,ret=0;
		int i;
		
		if(di==0) {
			FOR(i,val+1) if(i==4 || i==7 || nok) ret++;
			return ret;
		}
		
		FOR(i,di) p10*=10;
		
		FOR(i,10) {
			if(p10*(i+1) <= val) {
				if(i==0 && non0==0) {
					ret += dodo2(p10-1,0,di-1,1);
				}
				else if(i==4 || i==7) {
					ret +=numnum[di][0];
					if(nok) ret +=numnum[di][1];
				}
				else {
					if(nok) ret +=numnum[di][0];
				}
			}
			else {
				if(i==4 || i==7) ret += dodo2(val-i*p10,1,di-1,nok);
				else if(nok) ret += dodo2(val-i*p10,1,di-1,0);
				break;
			}
		}
		return ret;
	}
	
	ll dodo(ll val) {
		int d=0;
		ll p10=1;
		if(val==10000000000000000LL) val--;
		while(p10*10 <= val) p10*=10,d++;
		return dodo2(val,0,d,1);
	}
	
	long long find(long long a, long long b) {
		int i;
		ZERO(numnum);
		FOR(i,16) numnum[i][0]=1LL<<i;
		FOR(i,15) numnum[i+1][1]=(1LL<<i)*8*(i+1);
		return dodo(b)-dodo(a-1);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; long long Arg1 = 7LL; long long Arg2 = 4LL; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 8LL; long long Arg1 = 19LL; long long Arg2 = 4LL; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 28LL; long long Arg1 = 33LL; long long Arg2 = 0LL; verify_case(2, Arg2, find(Arg0, Arg1)); }
	//void test_case_3() { long long Arg0 = 12345678900LL; long long Arg1 = 98765432100LL; long long Arg2 = 91136LL; verify_case(3, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 97; long long Arg1 = 100; long long Arg2 = 1; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TheAlmostLuckyNumbersDivOne ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

