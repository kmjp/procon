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

class EagleInZoo {
	public:
	int C[55];
	double P[55],S[55];
	double calc(vector <int> parent, int K) {
		int i,x,y,N;
		N=parent.size()+1;
		
		if(K==1) return 1;
		
		ZERO(C);
		FOR(i,parent.size()) C[parent[i]]++;
		P[0]=1;
		for(i=1;i<N;i++) P[i]=P[parent[i-1]]/C[parent[i-1]];
		
		ZERO(S);
		S[0]=1;
		double ret=0;
		for(x=2;x<=K;x++) {
			for(y=N-1;y>=1;y--) {
				if(x==K) ret+=(S[parent[y-1]]-S[y])*P[y];
				S[y]+=(S[parent[y-1]]-S[y])*P[y];
			}
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 1.0; verify_case(0, Arg2, calc(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 0.5; verify_case(1, Arg2, calc(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,1,0,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 0.75; verify_case(2, Arg2, calc(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,0,1,1,2,4,4,4,5,5,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; double Arg2 = 0.14595168754091617; verify_case(3, Arg2, calc(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,1,2,3,2,1,1,7,0,9,10,11,12,13,14,15,16,17,18,14,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; double Arg2 = 0.3272154791654077; verify_case(4, Arg2, calc(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {0,1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; double Arg2 = 0.0; verify_case(5, Arg2, calc(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EagleInZoo ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

