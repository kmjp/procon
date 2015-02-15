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

const int ma=3001;
int st[ma][ma];

class EmoticonsDiv2 {
	public:
	int printSmiles(int smiles) {
		int x,y;
		FOR(x,ma) FOR(y,ma) st[x][y]=9999999;
		st[1][0]=0;
		queue<pair<int,int> > Q;
		Q.push(make_pair(1,0));
		
		
		int loop=0;
		while(!Q.empty()) {
			loop++;
			int cn=Q.front().first;
			int cl=Q.front().second;
			Q.pop();
			
			if(st[cn][cn]>st[cn][cl]+1) {
				st[cn][cn]=st[cn][cl]+1;
				Q.push(make_pair(cn,cn));
			}
			if(cn+cl<ma && st[cn+cl][cl]>st[cn][cl]+1) {
				st[cn+cl][cl]=st[cn][cl]+1;
				if(cn+cl==smiles) return st[cn+cl][cl];
				Q.push(make_pair(cn+cl,cl));
			}
		}
		
		return 99999;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; verify_case(0, Arg1, printSmiles(Arg0)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 5; verify_case(1, Arg1, printSmiles(Arg0)); }
	void test_case_2() { int Arg0 = 11; int Arg1 = 11; verify_case(2, Arg1, printSmiles(Arg0)); }
	void test_case_3() { int Arg0 = 16; int Arg1 = 8; verify_case(3, Arg1, printSmiles(Arg0)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 21; verify_case(4, Arg1, printSmiles(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EmoticonsDiv2 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

