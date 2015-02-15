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


class CharacterBoard2 {
	public:
	int countGenerators(vector <string> fragment, int W, int i0, int j0) {
		ll mo=1000000009;
		ll res=0;
		ll p26[10001];
		p26[0]=1;
		for(int i=1;i<=10000;i++) p26[i]=(p26[i-1]*26)%mo;
		
		for(int S=1;S<=W;S++) {
			map<ll,char> T;
			
			for(int ty=j0;ty<j0+fragment.size();ty++) {
				for(int tx=i0;tx<i0+fragment[0].size();tx++) {
					ll st=(ty*W+tx)%S;
					if(T[st]==0) T[st]=fragment[ty-j0][tx-i0];
					else if(T[st]!=fragment[ty-j0][tx-i0]) goto ne;
				}
			}
			
			res = (res + p26[S-T.size()]) % mo;
			ne:
			;
		}
		
		return (int)res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"dea",
 "abc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; verify_case(0, Arg4, countGenerators(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"xyxxy"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 1; int Arg3 = 0; int Arg4 = 28; verify_case(1, Arg4, countGenerators(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"gogogo",
 "jijiji",
 "rarara"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; verify_case(2, Arg4, countGenerators(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"abababacac",
 "aaacacacbb",
 "ccabababab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 882; int Arg2 = 10; int Arg3 = 62; int Arg4 = 361706985; verify_case(3, Arg4, countGenerators(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"asjkffqw",
 "basjkffq",
 "qbasjkff",
 "qqbasjkf"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9031; int Arg2 = 9024; int Arg3 = 1959; int Arg4 = 173947456; verify_case(4, Arg4, countGenerators(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  CharacterBoard2 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
