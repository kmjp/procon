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

typedef signed long long s64;
typedef unsigned long long u64;

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


class FoxAndMountain {
	public:
	int trans[51][2];
	int memo[51][51][51];
	static const int mo=1000000009;
	
	
	int count(int n, string history) {
		int hl, mind,h,i,j,k,res;
		char tstr[51];
		char sstr[51];
		
		hl = history.size();
		strcpy(sstr,history.c_str());
		
		ZERO(trans);
		
		
		FOR(i,hl) {
			//_P("%d %d\n",trans[i][1],trans[i][0]);
			ZERO(tstr);
			memmove(tstr,history.c_str(),i);
			if(history[i]=='U') {
				trans[i][1]=i+1;
				tstr[i]='D';
				for(j=1;j<=i;j++) {
					if(memcmp(sstr,&tstr[i-(j-1)],j)==0) trans[i][0]=j;
				}
			}
			else {
				trans[i][0]=i+1;
				tstr[i]='U';
				for(j=1;j<=i;j++) {
					if(memcmp(sstr,&tstr[i-(j-1)],j)==0) trans[i][1]=j;
				}
			}
		}
		trans[hl][0]=trans[hl][1]=hl;
		
		ZERO(memo);
		memo[0][0][0]=1;
		FOR(i,n) {
			FOR(j,26) {
				FOR(k,hl+1) {
					if(memo[i][j][k]==0) continue;
					if(j>0){
						memo[i+1][j-1][trans[k][0]] += memo[i][j][k];
						memo[i+1][j-1][trans[k][0]] %= mo;
					}
					if(j<25) {
						memo[i+1][j+1][trans[k][1]] += memo[i][j][k];
						memo[i+1][j+1][trans[k][1]] %= mo;
					}
				}
			}
		}
		
		return memo[n][0][hl];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; string Arg1 = "UUDD"; int Arg2 = 1; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; string Arg1 = "DUUD"; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; string Arg1 = "UU"; int Arg2 = 1; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 49; string Arg1 = "U"; int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 20; string Arg1 = "UUUDUUU"; int Arg2 = 990; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 30; string Arg1 = "DUDUDUDUDUDUDUDU"; int Arg2 = 3718; verify_case(5, Arg2, count(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 50; string Arg1 = "U"; int Arg2 = 946357703; verify_case(6, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  FoxAndMountain ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
