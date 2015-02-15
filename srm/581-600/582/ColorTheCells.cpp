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


class ColorTheCells {
	
	vector<int> D;
	int N;
	public:
	
	int dodo2(vector<int>& V, int mask) {
		int i;
		int pt[10];
		int ret=0,ret2;
		
		FOR(i,N) pt[i]=-1;
		int cur=0;
		FOR(i,N) {
			int tar=V[i] + ((mask&(1<<V[i]))?-1:1);
			
			while(cur<tar) {
				cur++;
				ret=max(ret+1,pt[cur]+1);
			}
			while(cur>tar) {
				cur--;
				ret=max(ret+1,pt[cur]+1);
			}
			
			cur=tar;
			ret++;
			pt[V[i]]=ret+D[V[i]];
		}
		return ret;
		
	}
	
	
	int dodo(vector<int>& V) {
		int mask;
		int mi=1000000000;
		FOR(mask,1<<N) {
			if(mask&1) continue;
			if((mask&(1<<(N-1)))==0) continue;
			mi=min(mi,dodo2(V,mask));
		}
		return mi;
	}
	
	int minimalTime(vector <int> dryingTime) {
		int i;
		vector<int> V;
		
		D=dryingTime;
		N=D.size();
		FOR(i,N) V.push_back(i);
		int mi=1000000000;
		do {
			mi=min(mi,dodo(V));
		} while(next_permutation(V.begin(),V.end()));
		
		return mi;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, minimalTime(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 2, 100, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, minimalTime(Arg0)); }
	void test_case_2() { int Arr0[] = {33, 58, 21, 44}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26; verify_case(2, Arg1, minimalTime(Arg0)); }
	void test_case_3() { int Arr0[] = {35198, 26281, 72533, 91031, 44326, 43178, 85530}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26287; verify_case(3, Arg1, minimalTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  ColorTheCells ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
