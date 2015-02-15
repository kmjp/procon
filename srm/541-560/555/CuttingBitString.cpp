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


class CuttingBitString {
	char type[50][60];
	char str[100];
	u64 num[50];
	int tl[50];
	int nt,sl;
	int res;
	int memo[100];
	
	public:
	
	void setb(u64 v,char* s) {
		char* ps=s;
		while(v>0) {
			*s = '0' + (v&1);
			v>>=1;
			s++;
		}
		*s=0;
	}
	
	int dfs(int pos) {
		int i;
		
		if(memo[pos]!=-2) return memo[pos];
		if(pos==sl) {
			return 0;
		}
		
		int min=999;
		int v;
		FOR(i,nt) {
			if(sl-pos < tl[i]) break;
			if(memcmp(&str[pos],type[i],tl[i])==0) {
				v = dfs(pos + tl[i]);
				if(v<999) {
					v++;
					if(v < min) min = v;
				}
			}
			
		}
		memo[pos]=min;
		return min;
	}
	
	int getmin(string S) {
		u64 v;
		int i;
		
		ZERO(str);
		FOR(i,100) memo[i]=-2;;
		FOR(i,S.size()) str[i]=S.c_str()[S.size()-1-i];
		sl = strlen(str);
		
		v=1;
		nt=0;
		while(v<(1ULL<<51)) {
			num[nt]=v;
			setb(v,type[nt]);
			tl[nt]=strlen(type[nt]);
			nt++;
			v*=5;
		}
		res=999;
		res = dfs(0);
		
		if(res==999) return -1;
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "101101101"; int Arg1 = 3; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "1111101"; int Arg1 = 1; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "00000"; int Arg1 = -1; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "110011011"; int Arg1 = 3; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "1000101011"; int Arg1 = -1; verify_case(4, Arg1, getmin(Arg0)); }
	void test_case_5() { string Arg0 = "111011100110101100101110111"; int Arg1 = 5; verify_case(5, Arg1, getmin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  CuttingBitString ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
