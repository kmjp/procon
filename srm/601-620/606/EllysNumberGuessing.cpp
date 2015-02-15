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

class EllysNumberGuessing {
	public:
	int getNumber(vector <int> guesses, vector <int> answers) {
		int N=guesses.size();
		ll l,h;
		int i;
		l=h=guesses[0];
		l-=answers[0];
		h+=answers[0];
		if(h>1000000000) h=-1;
		if(l<1) l=-1;
		
		FOR(i,N) {
			if(h!=guesses[i]+(ll)answers[i] && h!=guesses[i]-(ll)answers[i]) h=-1;
			if(l!=guesses[i]+(ll)answers[i] && l!=guesses[i]-(ll)answers[i]) l=-1;
		}
		
		if(l!=-1 && h!=-1) return -1;
		if(l==-1 && h==-1) return -2;
		if(l==-1) return (int)h;
		return (int)l;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {600, 594}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 12}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 606; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100, 50, 34, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {58, 8, 8, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 42; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {500000, 600000, 700000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {120013, 220013, 79987}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -2; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {500000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {133742666}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {76938260, 523164588, 14196746, 296286419, 535893832,
 41243148, 364561227, 270003278, 472017422, 367932361,
 395758413, 301278456, 186276934, 316343129, 336557549,
 52536121, 98343562, 356769915, 89249181, 335191879}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {466274085, 20047757, 529015599, 246925926, 7318513,
 501969197, 178651118, 273209067, 71194923, 175279984,
 147453932, 241933889, 356935411, 226869216, 206654796,
 490676224, 444868783, 186442430, 453963164, 208020466}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 543212345; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {42}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {42}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 84; verify_case(5, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {999900000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100001}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 999799999; verify_case(6, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysNumberGuessing ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

