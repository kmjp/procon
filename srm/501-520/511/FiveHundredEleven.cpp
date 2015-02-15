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

int win[512][52];

class FiveHundredEleven {
	public:
	int N;
	vector<int> C;
	int dpdp(int mask,int step) {
		if(mask==511) return 1; // win
		if(step==N) return 0; // lose
		
		if(win[mask][step]==-1) {
			int numinc=0,x;
			win[mask][step] = 0;
			
			FOR(x,N) if((mask|C[x])==mask) numinc++;
			win[mask][step] |= (step<numinc && dpdp(mask,step+1)==0);
			FOR(x,N) win[mask][step] |= ((mask|C[x])!=mask && dpdp(mask|C[x],step+1)==0);
		}
		return win[mask][step];
	}
	
	string theWinner(vector <int> cards) {
		int i,j,x,y;
		C=cards;
		N=cards.size();
		
		MINUS(win);
		return dpdp(0,0)?"Fox Ciel":"Toastman";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 5, 7, 9, 510}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Fox Ciel"; verify_case(0, Arg1, theWinner(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Toastman"; verify_case(1, Arg1, theWinner(Arg0)); }
	void test_case_2() { int Arr0[] = {511}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Toastman"; verify_case(2, Arg1, theWinner(Arg0)); }
	//void test_case_3() { int Arr0[] = {5, 58, 192, 256}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Fox Ciel"; verify_case(3, Arg1, theWinner(Arg0)); }
	void test_case_3() { int Arr0[] = {461, 443, 177, 366, 499, 384, 125, 499, 372, 374, 39, 285, 203, 33, 429, 469, 458, 163, 154, 438, 508}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Toastman"; verify_case(3, Arg1, theWinner(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FiveHundredEleven ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

