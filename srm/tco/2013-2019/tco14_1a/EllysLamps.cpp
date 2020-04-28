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

class EllysLamps {
	public:
	int wor[51][51];
	int dpdp[51];
	int L;
	string R;
	
	int minmin(int LL,int RR) {
		int ma=10000,i,x,y=0;
		FOR(i,2) {
			string T=R;
			if(T[LL]) {
				if(i==0) T[LL]^=1,T[LL+1]^=1;
				else T[LL]^=1,T[LL+1]^=1,T[LL+2]^=1;
			}
			for(x=LL+2;x<=RR;x++) if(T[x-1]) T[x-1]^=1,T[x]^=1,T[x+1]^=1;
			for(x=LL;x<=RR;x++) y+=T[x];
			ma=min(ma,y);
		}
		return ma;
	}
	
	int getMin(string lamps) {
		int x,y;
		R=lamps;
		L=lamps.size();
		FOR(x,L) R[x]=R[x]=='Y';
		R+='\0'; R+='\0';
		
		ZERO(dpdp);
		FOR(x,L) FOR(y,x+1) dpdp[x+1]=max(dpdp[x+1],dpdp[y]+minmin(y,x));
		return dpdp[L];
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "YNNYN"; int Arg1 = 2; verify_case(0, Arg1, getMin(Arg0)); }
	void test_case_1() { string Arg0 = "NNN"; int Arg1 = 0; verify_case(1, Arg1, getMin(Arg0)); }
	void test_case_2() { string Arg0 = "YY"; int Arg1 = 0; verify_case(2, Arg1, getMin(Arg0)); }
	void test_case_3() { string Arg0 = "YNYYYNNNY"; int Arg1 = 3; verify_case(3, Arg1, getMin(Arg0)); }
	void test_case_4() { string Arg0 = "YNYYYYNYNNYYNNNNNNYNYNYNYNNYNYYYNY"; int Arg1 = 13; verify_case(4, Arg1, getMin(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysLamps ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

