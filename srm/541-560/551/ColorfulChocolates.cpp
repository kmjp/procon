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


class ColorfulChocolates {
	public:
	char str[52];
	int ms;
	
	int can(int s,int e,int ms) {
		float sp;
		int i,t,nt;
		for(sp=s+0.5;sp<e;sp+=1) {
			t=0;nt=0;
			//¶‚Éo‚·
			for(i=s;i<sp;i++) {
				if(str[i]==str[s]) t++;
				else nt+=t;
			}
			//‰E‚Éo‚·
			t=0;
			for(i=e;i>sp;i--) {
				if(str[i]==str[s]) t++;
				else nt+=t;
			}
			if(nt<=ms) return 1;
			
		}
		return 0;
	}
	
	int maximumSpread(string chocolates, int maxSwaps) {
		int l,s,e,i;;
		int maxe=1;
		int sc;
		
		ms=maxSwaps;
		
		strcpy(str,chocolates.c_str());
		l = strlen(str);
		for(s=0;s<l;s++) {
			for(e=s+1;e<l;e++) {
				if(str[s]!=str[e]) continue;
				sc = 1;
				for(i=s+1;i<=e;i++) if(str[s]==str[i]) sc++;
				if(sc<maxe) continue;
				if(can(s,e,ms)) maxe=sc;
				
			}
		}
		return maxe;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCDCBC"; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, maximumSpread(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ABCDCBC"; int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, maximumSpread(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ABBABABBA"; int Arg1 = 3; int Arg2 = 4; verify_case(2, Arg2, maximumSpread(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ABBABABBA"; int Arg1 = 4; int Arg2 = 5; verify_case(3, Arg2, maximumSpread(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO"; int Arg1 = 77; int Arg2 = 5; verify_case(4, Arg2, maximumSpread(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  ColorfulChocolates ___test;
  ___test.run_test(-1);
}
// END CUT HERE
