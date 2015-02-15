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

class FavouriteDigits {
	public:
	ll p10[19];
	int d1,c1,d2,c2;
	
	int okok(ll v, int mv,int& tc1, int& tc2) {
		int ok=0,i,j=0;
		tc1=tc2=0;
		
		for(i=16;i>=mv;i--) {
			if(v/p10[i]) j++;
			if(j && ((v/p10[i])%10)==d1) tc1++;
			if(j && ((v/p10[i])%10)==d2) tc2++;
		}
		return (tc1>=c1) && (tc2>=c2);
	}
	
	long long findNext(long long N, int digit1, int count1, int digit2, int count2) {
		int i,j,tc1,tc2,x;
		d1=digit1; d2=digit2;
		c1=count1; c2=count2;
		if(d1>d2) swap(d1,d2), swap(c1,c2);
		
		ll ret=1LL<<60;
		p10[0]=1;
		FOR(i,18) p10[i+1]=10*p10[i];
		
		if(okok(N,0,tc1,tc2)) return N;
		
		for(i=17;i>=0;i--) {
			ll val = N/p10[i+1]*p10[i+1];
			FOR(j,10) {
				ll val2=val + j*p10[i];
				if(val2<=N) continue;
				okok(val2,i,tc1,tc2);
				
				FOR(x,i) {
					if(tc2<c2) tc2++, val2 += d2*p10[x];
					else if(tc1<c1) tc1++, val2 += d1*p10[x];
				}
				if(tc1>=c1 && tc2>=c2) ret = min(ret,val2);
			}
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 47LL; int Arg1 = 1; int Arg2 = 0; int Arg3 = 2; int Arg4 = 0; long long Arg5 = 47LL; verify_case(0, Arg5, findNext(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { long long Arg0 = 47LL; int Arg1 = 5; int Arg2 = 0; int Arg3 = 9; int Arg4 = 1; long long Arg5 = 49LL; verify_case(1, Arg5, findNext(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { long long Arg0 = 47LL; int Arg1 = 5; int Arg2 = 0; int Arg3 = 3; int Arg4 = 1; long long Arg5 = 53LL; verify_case(2, Arg5, findNext(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { long long Arg0 = 47LL; int Arg1 = 2; int Arg2 = 1; int Arg3 = 0; int Arg4 = 2; long long Arg5 = 200LL; verify_case(3, Arg5, findNext(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { long long Arg0 = 123456789012345LL; int Arg1 = 1; int Arg2 = 2; int Arg3 = 2; int Arg4 = 4; long long Arg5 = 123456789012422LL; verify_case(4, Arg5, findNext(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_52() { long long Arg0 = 92LL; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; int Arg4 = 0; long long Arg5 = 100LL; verify_case(5, Arg5, findNext(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { long long Arg0 = 729947LL; int Arg1 = 0; int Arg2 = 0; int Arg3 = 3; int Arg4 = 2; long long Arg5 = 730000LL; verify_case(5, Arg5, findNext(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FavouriteDigits ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

