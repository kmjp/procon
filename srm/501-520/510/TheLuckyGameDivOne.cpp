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

class TheLuckyGameDivOne {
	public:
	ll A,B,BL,JL;
	vector<ll> cand,key;
	vector<int> value;
	
	int N;
	void add(ll v) {
		if(v>B) return;
		if(v>=A) cand.push_back(v);
		add(v*10+4);
		add(v*10+7);
	}
	
	int lb(ll val) {
		return lower_bound(cand.begin(),cand.end(),val+BL)-lower_bound(cand.begin(),cand.end(),val);
	}
	int test(ll val) {
		if(val<A || val+JL-1>B) return -1;
		int s = upper_bound(key.begin(),key.end(),val) - key.begin()-1;
		int e = upper_bound(key.begin(),key.end(),val+JL-BL) - key.begin();
		int mi=value[s];
		for(;s<e;s++) mi=min(mi,value[s]);
		return mi;
		
	}
	int find(long long a, long long b, long long jLen, long long bLen) {
		int x,y;
		
		A=a,B=b,BL=bLen,JL=jLen;
		cand.clear();
		add(0);
		sort(cand.begin(),cand.end());
		
		N=cand.size();
		
		key.clear(); value.clear();
		key.push_back(a);
		key.push_back(b-(bLen-1));
		
		FOR(x,N) {
			if(cand[x]+1 >= a && cand[x]+bLen < b) key.push_back(cand[x]+1);
			if(cand[x]-bLen+1 >= a && cand[x] < b ) key.push_back(cand[x]-(bLen-1));
		}
		
		sort(key.begin(),key.end());
		key.erase(unique(key.begin(),key.end()),key.end());
		ITR(it,key) value.push_back(lb(*it));
		
		
		set<ll> key2;
		FOR(x,key.size()) {
			key2.insert(key[x]-1);
			key2.insert(key[x]);
			key2.insert(key[x]+1);
			key2.insert(key[x]-1-(jLen-1));
			key2.insert(key[x]-(jLen-1));
			key2.insert(key[x]+1-(jLen-1));
			key2.insert(key[x]-1+(jLen-1));
			key2.insert(key[x]+(jLen-1));
			key2.insert(key[x]+1+(jLen-1));
		}
		
		int ma=0;
		ITR(it,key2) ma=max(ma,test(*it));
		
		return ma;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 10LL; long long Arg2 = 2LL; long long Arg3 = 1LL; int Arg4 = 0; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 100LL; long long Arg2 = 100LL; long long Arg3 = 100LL; int Arg4 = 6; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 4LL; long long Arg1 = 8LL; long long Arg2 = 3LL; long long Arg3 = 2LL; int Arg4 = 1; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	//void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 100LL; long long Arg2 = 75LL; long long Arg3 = 50LL; int Arg4 = 2; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 160LL; long long Arg1 = 2650LL; long long Arg2 = 1563LL; long long Arg3 = 1480LL; int Arg4 = 8; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TheLuckyGameDivOne ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

