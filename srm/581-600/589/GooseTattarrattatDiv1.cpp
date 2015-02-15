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
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

class UF {
	public:
	static const int ufmax=502;
	int ufpar[ufmax],ufrank[ufmax];
	UF() { init();}
	void init(){int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; } }
	int find(int x) {	return (ufpar[x]==x)?(x):(ufpar[x] = find(ufpar[x]));}
	int operator[](int x) {return find(x);}
	void unite(int x,int y) {
		x = find(x); y = find(y);
		if(x==y) return;
		if(ufrank[x]<ufrank[y]) ufpar[x]=y;
		else {ufpar[y]=x; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
	}
};

class GooseTattarrattatDiv1 {
	public:
	int mi;
	int N;
	
	int getmin(string S) {
		N=S.size();
		UF uf;
		int i,j;
		uf.init();
		FOR(i,N) FOR(j,N) if(S[i]==S[j]) uf.unite(i,j);
		FOR(i,N) uf.unite(i,N-1-i);
		
		int vis[51];
		int ret=0;
		ZERO(vis);
		FOR(i,N) {
			if(uf.find(i)!=i) continue;
			int tot=0;
			int num[26];
			ZERO(num);
			FOR(j,N) {
				if(uf.find(j)==i) {
					num[S[j]-'a']++;
					tot++;
				}
			}
			int ma=0;
			FOR(j,26) ma=max(ma,num[j]);
			ret += tot-ma;
		}
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "geese"; int Arg1 = 2; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "tattarrattat"; int Arg1 = 0; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "xyyzzzxxx"; int Arg1 = 2; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy"; int Arg1 = 11; verify_case(3, Arg1, getmin(Arg0)); }
	//void test_case_3() { string Arg0 = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag"; int Arg1 = 11; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "abaabb"; int Arg1 = 3; verify_case(4, Arg1, getmin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  GooseTattarrattatDiv1 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
