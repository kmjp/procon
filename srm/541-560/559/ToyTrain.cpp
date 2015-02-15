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


class ToyTrain {
	public:
	int R,C;
	char str[60][60];
	char rail[60][60];
	int use[10];
	int getMinCost(vector <string> field) {
		int i,x,y,c;
		R=field.size();
		C=field[0].size();
		FOR(y,R) strcpy(str[y],field[y].c_str());
		
		ZERO(rail);
		ZERO(use);
		//‰¡
		FOR(y,R) {
			c=0;
			FOR(x,C) {
				if(str[y][x]=='A') {
					if(c==1) return -1;
					rail[y][x] = 1;
					c=(c==0)?1:0;
				}
				else if(str[y][x]=='B') {
					if(c==2) return -1;
					rail[y][x] = 1;
					c=(c==0)?2:0;
				}
				else if(c!=0) {
					rail[y][x] = 1;
					if(str[y][x]>='1' && str[y][x]<='9') use[str[y][x]-'0']=1;
				}
				
			}
			if(c!=0) return -1;
		}
		
		//c
		FOR(x,C) {
			c=0;
			FOR(y,R) {
				if(str[y][x]=='A') {
					if(c==1) return -1;
					rail[y][x] = 1;
					c=(c==0)?1:0;
				}
				else if(str[y][x]=='B') {
					if(c==2) return -1;
					rail[y][x] = 1;
					c=(c==0)?2:0;
				}
				else if(c!=0) {
					if(rail[y][x]) return -1;
					rail[y][x] = 1;
					if(str[y][x]>='1' && str[y][x]<='9') use[str[y][x]-'0']=1;
				}
			}
			if(c!=0) return -1;
		}
		
		c=1;
		FOR(y,R) FOR(x,C) {
			if(rail[y][x]) c=0;
			if(str[y][x]=='S' && rail[y][x]==0) return -1;
		}
		
		if(c) return -1;
		FOR(i,10) if(use[i]) c+=i;
		
		return c;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BA",
 "SS",
 "AB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, getMinCost(Arg0)); }
	void test_case_1() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, getMinCost(Arg0)); }
	void test_case_2() { string Arr0[] = {"ABBA",
 "BAAB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, getMinCost(Arg0)); }
	void test_case_3() { string Arr0[] = {"AA",
 "AA"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, getMinCost(Arg0)); }
	void test_case_4() { string Arr0[] = {"..AB",
 "B..A",
 "....",
 "A.B."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, getMinCost(Arg0)); }
	void test_case_5() { string Arr0[] = {"A1B8A2B",
 "16A.B22",
 "BAB.9.A",
 "ABA.7.B",
 "B12345A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 31; verify_case(5, Arg1, getMinCost(Arg0)); }
	void test_case_6() { string Arr0[] = {"..A.B",
 ".1.2.",
 "A.B..",
 ".3.4.",
 "B...A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(6, Arg1, getMinCost(Arg0)); }
	void test_case_7() { string Arr0[] = {"ASBSBSA",
 "S.S.S.S",
 "BSASASB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(7, Arg1, getMinCost(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  ToyTrain ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
