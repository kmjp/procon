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


class MergersDivTwo {
	public:
	double findMaximum(vector <int> R, int k) {
		double rev[51];
		int N=R.size(),x,y;
		sort(R.begin(),R.end());
		FOR(x,51) rev[x]=-1e9;
		rev[0]=R[0];
		
		FOR(x,N) {
			double r=rev[x];
			if(r<=-1e9) continue;
			for(y=1;y<=N;y++) {
				if(x+y>=N) break;
				r+=R[x+y];
				if(y+1>=k) rev[x+y]=max(rev[x+y],r/(y+1));
			}
		}
		return rev[N-1];
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, -7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 1.5; verify_case(0, Arg2, findMaximum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5, -7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 0.3333333333333333; verify_case(1, Arg2, findMaximum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 2, 2, 3, -10, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 2.9166666666666665; verify_case(2, Arg2, findMaximum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-100, -100, -100, -100, -100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = -66.66666666666667; verify_case(3, Arg2, findMaximum(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {869, 857, -938, -290, 79, -901, 32, -907, 256, -167, 510, -965, -826, 808, 890,
 -233, -881, 255, -709, 506, 334, -184, 726, -406, 204, -912, 325, -445, 440, -368}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; double Arg2 = 706.0369290573373; verify_case(4, Arg2, findMaximum(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MergersDivTwo ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

