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


class TypingDistance {
	public:
	int dis[256];
	
	int minDistance(string K, string W) {
		int i,n=0;
		FOR(i,K.size()) dis[K[i]]=i;
		for(i=1;i<W.size();i++) n+=abs(dis[W[i]] - dis[W[i-1]]);
		return n;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "qwertyuiop"; string Arg1 = "potter"; int Arg2 = 8; verify_case(0, Arg2, minDistance(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "tc"; string Arg1 = "tctcttccctccccttc"; int Arg2 = 9; verify_case(1, Arg2, minDistance(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "a"; string Arg1 = "aaaaaaaaaaa"; int Arg2 = 0; verify_case(2, Arg2, minDistance(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "kwadrutove"; string Arg1 = "rowerowe"; int Arg2 = 39; verify_case(3, Arg2, minDistance(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "qwertyuiopasdfghjklzxcvbnm"; string Arg1 = "topcodersingleroundmatchgoodluckhavefun"; int Arg2 = 322; verify_case(4, Arg2, minDistance(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  TypingDistance ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
