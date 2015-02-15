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
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------


class FlippingBitsDiv2 {
	map<string, int> MM;
	int M;
	public:
	
	int test(string SS) {
		if(MM.find(SS)!=MM.end()) return MM[SS];
		if(SS.size()==0) return 0;
		
		int i,t=0;
		FOR(i,M) if(SS[SS.size()-1-i]=='0') t++;
		string SR;
		FOR(i,SS.size()-M) SR += (SS[i]=='0'?'1':'0');
		return MM[SS] = min(t+test(SS.substr(0,SS.size()-M)), 1+M-t+test(SR));
	}
	
	int getmin(vector <string> S, int M) {
		string SS;
		int i,N;
		
		FOR(i,S.size()) SS+=S[i];
		N=SS.size();
		this->M=M;
		
		MM.clear();
		string SR=SS;
		reverse(SR.begin(),SR.end());
		
		int mi=10000;
		for(i=0;i<=N/M;i++) mi=min(mi,test(SS.substr(0,i*M))+test(SR.substr(0,N-i*M)));
		return mi;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"00111000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, getmin(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"00111000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, getmin(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(2, Arg2, getmin(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"00100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 2; verify_case(3, Arg2, getmin(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"00010","11010110","1010111","110001010","0110001100"
,"000110110","011010101","00","111","100"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; int Arg2 = 31; verify_case(4, Arg2, getmin(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  FlippingBitsDiv2 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
