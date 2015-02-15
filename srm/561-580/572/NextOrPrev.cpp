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


class NextOrPrev {
	public:
	int getMinimum(int nextCost, int prevCost, string start, string goal) {
		int i,L,x,y;
		int to[60];
		
		MINUS(to);
		L=start.size();
		FOR(i,L) to[start[i]-'a']=goal[i]-'a';
		
		FOR(x,26) for(y=x+1;y<=25;y++) {
			if(to[x]==-1 || to[y]==-1) continue;
			if(to[x]>to[y]) return -1;
		}
		int num=0;
		FOR(x,26) {
			if(to[x]==-1) continue;
			if(to[x]>x) num += (to[x]-x)*nextCost;
			if(to[x]<x) num += (x-to[x])*prevCost;
		}
		return num;
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 8; string Arg2 = "ae"; string Arg3 = "bc"; int Arg4 = 21; verify_case(0, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 8; string Arg2 = "ae"; string Arg3 = "cb"; int Arg4 = -1; verify_case(1, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; string Arg2 = "srm"; string Arg3 = "srm"; int Arg4 = 0; verify_case(2, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 1; string Arg2 = "acb"; string Arg3 = "bdc"; int Arg4 = 30; verify_case(3, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 1; string Arg2 = "zyxw"; string Arg3 = "vuts"; int Arg4 = 16; verify_case(4, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 563; int Arg1 = 440; string Arg2 = "ptrbgcnlaizo"; string Arg3 = "rtscedkiahul"; int Arg4 = 10295; verify_case(5, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arg0 = 126; int Arg1 = 311; string Arg2 = "yovlkwpjgsna"; string Arg3 = "zpwnkytjisob"; int Arg4 = -1; verify_case(6, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  NextOrPrev ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
