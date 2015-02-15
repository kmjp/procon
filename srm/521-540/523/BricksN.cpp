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

class BricksN {
	public:
	int K;
	ll line[51];
	ll memo[51][51][2];
	
	ll dodo(int W,int H,int first) {
		if(H<=0) return first;
		if(W<=0) return 0;
		if(memo[W][H][first]>=0) return memo[W][H][first];
		int x,w,x2;
		
		if(first==1) {
			memo[W][H][first]=1;
			FOR(x,W) for(w=1;w<=W-x;w++) {
				ll ret=line[w]*dodo(w,H-1,1)%mo;
				ll tot=1;
				for(x2=x+w+1;x2<W;x2++) tot+=dodo(W-x2,H,0);
				tot%=mo;
				memo[W][H][first]+=ret%mo*tot%mo;
			}
		}
		else {
			memo[W][H][first]=0;
			for(w=1;w<=W;w++) {
				ll ret=line[w]*dodo(w,H-1,1)%mo;
				ll tot=1;
				for(x2=w+1;x2<W;x2++) tot+=dodo(W-x2,H,0);
				tot%=mo;
				memo[W][H][first]+=ret%mo*tot%mo;
			}
		}
		memo[W][H][first] %= mo;
		return memo[W][H][first];
		
	}
	
	int countStructures(int w, int h, int k) {
		K=k;
		int i,j;
		
		MINUS(memo);
		ZERO(line);
		line[0]=1;
		FOR(i,w) for(j=1;j<=k;j++) {
			if(i+j<=w) line[i+j]=(line[i+j]+line[i]) % mo;
		}
		
		return dodo(w,h,1);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 3; int Arg3 = 13; verify_case(0, Arg3, countStructures(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 3; int Arg3 = 83; verify_case(1, Arg3, countStructures(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 1; int Arg3 = 6; verify_case(2, Arg3, countStructures(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 3; int Arg3 = 288535435; verify_case(3, Arg3, countStructures(Arg0, Arg1, Arg2)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BricksN ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

