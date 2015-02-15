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

class FoxAndChess {
int T[100],T2[100],A[100],B[100];
	
	public:
	string ableToMove(string begin, string target) {
		int i,N;
		N=begin.size();
		string S,S2;
		
		FOR(i,N) {
			if(begin[i]!='.') S += begin[i];
			if(target[i]!='.') S2 += target[i];
		}
		if(S!=S2) return "Impossible";
		
		int N1=0,N2=0;
		FOR(i,N) {
			if(begin[i]!='.') {
				T[N1]=begin[i];
				A[N1]=i;
				N1++;
			}
			if(target[i]!='.') {
				T2[N2]=target[i];
				B[N2]=i;
				N2++;
			}
		}
		FOR(i,N1) if(T[i]!=T2[i]) return "Impossible";
		FOR(i,N1) {
			if(T[i]=='L') if(A[i]<B[i]) return "Impossible";
			if(T[i]=='R') if(A[i]>B[i]) return "Impossible";
		}
		return "Possible";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "R..."; string Arg1 = "..R."; string Arg2 = "Possible"; verify_case(0, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "..R."; string Arg1 = "R..."; string Arg2 = "Impossible"; verify_case(1, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = ".L.R.R."; string Arg1 = "L...R.R"; string Arg2 = "Possible"; verify_case(2, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = ".L.R."; string Arg1 = ".R.L."; string Arg2 = "Impossible"; verify_case(3, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "LRLLRLRLLRLLRLRLRL"; string Arg1 = "LRLLRLRLLRLLRLRLRL"; string Arg2 = "Possible"; verify_case(4, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "L"; string Arg1 = "."; string Arg2 = "Impossible"; verify_case(5, Arg2, ableToMove(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  FoxAndChess ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
