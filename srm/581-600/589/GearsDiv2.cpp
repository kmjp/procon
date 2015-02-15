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


class GearsDiv2 {
	public:
	int N;
	map<string,int> M;
	
	int test(string D) {
		int i;
		if(M.find(D)!=M.end()) return M[D];
		
		int j=0;
		FOR(i,D.size()-1) if(D[i]==D[i+1]) j++;
		if(j<=1) return M[D]=j;
		
		int mi=100;
		for(i=1;i<D.size()-1;i++) if(D[i-1]==D[i] || D[i]==D[i+1]) 
				mi=min(mi,1+test(D.substr(0,i))+test(D.substr(i+1)));
		return M[D]=mi;
	}
	
	int getmin(string D) {
		N=D.size();
		M.clear();
		
		int i,j=0;
		FOR(i,D.size()) if(D[i]==D[(i+1)%N]) j++;
		if(j==0) return 0;
		
		int mi=100;
		FOR(i,N) {
			string S;
			FOR(j,N-1) S+=D[(i+1+j)%N];
			mi=min(mi,1+test(S));
		}
		
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LRRR"; int Arg1 = 1; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "RRR"; int Arg1 = 2; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "LRLR"; int Arg1 = 0; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "LRLLRRLLLRRRLLLL"; int Arg1 = 6; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "RRRRRRRLRRRRRRRLRLRLLRLRLRLRRLRLRLLLRLRLLRLLRRLRRR"; int Arg1 = 14; verify_case(4, Arg1, getmin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  GearsDiv2 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
