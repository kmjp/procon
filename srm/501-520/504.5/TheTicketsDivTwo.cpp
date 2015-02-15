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

class TheTicketsDivTwo {
	int pat;
	int N,M,K;
	int hist[11];
	
	public:
	void dfs(int cur,int npat,vector<int>& v) {
		int i,j,g=1;
		
		for(i=cur;i<K;i++) g*=6;
		if(cur==K) {
			if(v[0]==M) pat+=npat;
		}
		else if(v.size()==1) {
			if(v[0]==M) pat+=npat*g;
		}
		else {
			vector<int> v2;
			//4
			if(v[0]==M) pat+=npat*g/6;
			v2=v;
			v2.erase(v2.begin());
			//2,6
			dfs(cur+1,npat*2,v2);
			//1,3,5
			v2.push_back(v[0]);
			dfs(cur+1,npat*3,v2);
		}
	}
	
	double find(int n, int m, int k) {
		int i;
		pat=0;
		N=n;M=m;K=k;
		vector<int> V;
		FOR(i,N) V.push_back(i+1);
		dfs(0,1,V);
		double ret=pat;
		FOR(i,k) ret/=6.0;
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; double Arg3 = 0.16666666666666666; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 2; double Arg3 = 0.5833333333333334; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 7; int Arg2 = 4; double Arg3 = 0.0; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 10; double Arg3 = 0.25264033564814814; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TheTicketsDivTwo ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

