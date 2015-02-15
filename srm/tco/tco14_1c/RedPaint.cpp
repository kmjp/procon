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

double dpdp[2][520][520];

class RedPaint {
	public:
	/*
	double expectedCells(int N) {
		int i;
		double dd[1010];
		dd[0]=1;
		FOR(i,500) {
			dd[i*2+1]=dd[i*2+2]=dd[i*2]*(i*2+1)/(i*2+2.0);
		}
		double ret=1;
		FOR(i,N) ret+=dd[i];
		
		return ret;
	}
	*/
	double expectedCells(int N) {
		ZERO(dpdp);
		int x,y,z,i;
		dpdp[0][0][0]=1;
		
		FOR(i,N) {
			int cur=i%2,tar=cur^1;
			ZERO(dpdp[tar]);
			FOR(x,i+1) FOR(y,i+1) {
				// right
				if(x==y) dpdp[tar][x+1][y+1] += dpdp[cur][x][y]/2;
				else dpdp[tar][x][y+1] += dpdp[cur][x][y]/2;
				// left
				if(y==0) dpdp[tar][x+1][y] += dpdp[cur][x][y]/2;
				else dpdp[tar][x][y-1] += dpdp[cur][x][y]/2;
			}
		}
		
		double ret=0;
		FOR(x,N+1) FOR(y,N+1) ret += dpdp[N%2][x][y]*(x+1);
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; double Arg1 = 1.0; verify_case(0, Arg1, expectedCells(Arg0)); }
	void test_case_1() { int Arg0 = 1; double Arg1 = 2.0; verify_case(1, Arg1, expectedCells(Arg0)); }
	void test_case_2() { int Arg0 = 2; double Arg1 = 2.5; verify_case(2, Arg1, expectedCells(Arg0)); }
	void test_case_3() { int Arg0 = 4; double Arg1 = 3.375; verify_case(3, Arg1, expectedCells(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RedPaint ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

