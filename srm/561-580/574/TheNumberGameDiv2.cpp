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


class TheNumberGameDiv2 {
	public:
	int minimumMoves(int A, int B) {
		char As[100],Bs[100],Br[100];;
		int AL,BL;
		sprintf(As,"%d",A);
		sprintf(Bs,"%d",B);
		AL=strlen(As);
		BL=strlen(Bs);
		
		int loop,x,y,mm=999;
		FOR(x,AL-BL+1) {
			if(strncmp(As+x,Bs,BL)!=0) continue;
			
			y=AL-BL;
			if(x>0) y+=2;
			mm=min(mm,y);
		}
		
		ZERO(Br);
		FOR(x,BL) Br[x]=Bs[BL-1-x];
		FOR(x,AL-BL+1) {
			if(strncmp(As+x,Br,BL)!=0) continue;
			mm=min(mm,1+AL-BL);
		}
		
		return (mm>=999)?-1:mm;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 25; int Arg1 = 5; int Arg2 = 2; verify_case(0, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5162; int Arg1 = 16; int Arg2 = 4; verify_case(1, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 334; int Arg1 = 12; int Arg2 = -1; verify_case(2, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 218181918; int Arg1 = 9181; int Arg2 = 6; verify_case(3, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 9798147; int Arg1 = 79817; int Arg2 = -1; verify_case(4, Arg2, minimumMoves(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  TheNumberGameDiv2 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
