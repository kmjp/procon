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


class EllysNewNickname {
	public:
	int getLength(string nickname) {
		int i,l=0;
		
		FOR(i,nickname.size()) { 
			if(nickname[i]=='i') nickname[i]='a';
			if(nickname[i]=='u') nickname[i]='a';
			if(nickname[i]=='e') nickname[i]='a';
			if(nickname[i]=='o') nickname[i]='a';
			if(nickname[i]=='y') nickname[i]='a';
			if(i==0 || nickname[i]!='a' || nickname[i-1]!='a') l++;
		}
		return l;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "tourist"; int Arg1 = 6; verify_case(0, Arg1, getLength(Arg0)); }
	void test_case_1() { string Arg0 = "eagaeoppooaaa"; int Arg1 = 6; verify_case(1, Arg1, getLength(Arg0)); }
	void test_case_2() { string Arg0 = "esprit"; int Arg1 = 6; verify_case(2, Arg1, getLength(Arg0)); }
	void test_case_3() { string Arg0 = "ayayayayayaya"; int Arg1 = 1; verify_case(3, Arg1, getLength(Arg0)); }
	void test_case_4() { string Arg0 = "wuuut"; int Arg1 = 3; verify_case(4, Arg1, getLength(Arg0)); }
	void test_case_5() { string Arg0 = "naaaaaaaanaaaanaananaaaaabaaaaaaaatmaaaaan"; int Arg1 = 16; verify_case(5, Arg1, getLength(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  EllysNewNickname ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
