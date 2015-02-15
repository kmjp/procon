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

string memo[52][52];

class MergeStrings {
	string SS,AA,BB;
	public:
	string dodo(int al,int bl) {
		if(memo[al][bl]!="{") return memo[al][bl];
		if(al==AA.size() && bl==BB.size()) return "";
		
		memo[al][bl]="}";
		if(al!=AA.size()) {
			string r=dodo(al+1,bl);
			if(r!="}" && (SS[al+bl]=='?' || SS[al+bl]==AA[al])) memo[al][bl]=min(memo[al][bl],AA[al]+r);
		}
		if(bl!=BB.size()) {
			string r=dodo(al,bl+1);
			if(r!="}" && (SS[al+bl]=='?' || SS[al+bl]==BB[bl])) memo[al][bl]=min(memo[al][bl],BB[bl]+r);
		}
		return memo[al][bl];
	}
	
	string getmin(string S, string A, string B) {
		SS=S,AA=A,BB=B;
		int i,j;
		FOR(i,51) FOR(j,51) memo[i][j]="{";
		
		string res=dodo(0,0);
		if(res=="}") return "";
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "??CC??"; string Arg1 = "ABC"; string Arg2 = "BCC"; string Arg3 = "ABCCBC"; verify_case(0, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "WHAT?"; string Arg1 = "THE"; string Arg2 = "WA"; string Arg3 = ""; verify_case(1, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "PARROT"; string Arg1 = "PARROT"; string Arg2 = ""; string Arg3 = "PARROT"; verify_case(2, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "???????????"; string Arg1 = "AZZAA"; string Arg2 = "AZAZZA"; string Arg3 = "AAZAZZAAZZA"; verify_case(3, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "????K??????????????D???K???K????????K?????K???????"; string Arg1 = "KKKKKDKKKDKKDDKDDDKDKK"; string Arg2 = "KDKDDKKKDDKDDKKKDKDKKDDDDDDD"; string Arg3 = "KDKDKDKKKDDKDDKKKDKDKKDKDDDKDDDKKDKKKDKKDDKDDDKDKK"; verify_case(4, Arg3, getmin(Arg0, Arg1, Arg2)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MergeStrings ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

