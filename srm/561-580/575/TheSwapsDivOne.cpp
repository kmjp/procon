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
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#else
#define DBG(...)
#define DV(...)
#endif

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

double P[1000002];
class TheSwapsDivOne {
	int L;
	double nc[2500];
	public:
	double find(vector <string> sequence, int k) {
		string s;
		int i,x,y;
		FOR(i,sequence.size()) s+=sequence[i];
		
		double tc=0;
		L=s.size();
		FOR(x,L) {
			nc[x]=(x+1)*(L-x)/(double)(L*(L+1)/2);
			tc+=nc[x];
		}
		
		P[0]=1;
		for(x=1;x<=k;x++) {
			P[x]=P[x-1]*(L-2)/(double)L + (1-P[x-1])*(2/(double)L/(double)(L-1));
		}
		
		double tt=0;
		FOR(x,L) {
			tt += P[k]*nc[x]*(s[x]-'0') + (1-P[k])*(tc-nc[x])*(s[x]-'0')/(L-1);
		}
		return tt;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"4", "77"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 10.0; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"4", "77"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; double Arg2 = 10.0; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"1", "1", "1", "1", "1", "1", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000; double Arg2 = 3.0; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"572685085149095989026478064633266980348504469", "19720257361", "9", "69"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; double Arg2 = 98.3238536775161; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  TheSwapsDivOne ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
