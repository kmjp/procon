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

int K;
ll len[101];
ll nb[101];

class MagicalGirlLevelThreeDivTwo {
	public:
	vector <string> f;
	
	ll okok(int id,ll val) {
		if(val<=0) return 0;
		if(id<K) return count(f[id].begin(),f[id].begin()+val,'1');
		ll ret=0;
		for(id=id-1;id>=0;id-=K) {
			if(val >= len[id]) ret+=nb[id], val -=len[id];
			else return ret + okok(id,val);
		}
		return ret;
	}
	
	int theCount(vector <string> first, int n, long long lo, long long hi) {
		int i,j;
		f=first;
		K=first.size();
		ZERO(len);
		ZERO(nb);
		
		FOR(i,K) len[i]=first[i].size(),nb[i]=count(first[i].begin(),first[i].end(),'1');
		
		for(i=K;i<=n;i++) {
			j=i-1;
			len[i]=0;
			while(j>=0) {
				len[i]+=len[j];
				nb[i]+=nb[j];
				j-=K;
				len[i]=min(len[i],10000000000000000LL);
				nb[i]=min(nb[i],10000000000000000LL);
			}
		}
		return okok(n,hi+1)-okok(n,lo);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"101", "01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; long long Arg2 = 2LL; long long Arg3 = 5LL; int Arg4 = 2; verify_case(0, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"01", "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; long long Arg2 = 4LL; long long Arg3 = 5LL; int Arg4 = 1; verify_case(1, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"1", "11", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 46; long long Arg2 = 10000LL; long long Arg3 = 11000LL; int Arg4 = 1001; verify_case(2, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"0", "00", "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 46; long long Arg2 = 10000LL; long long Arg3 = 11000LL; int Arg4 = 0; verify_case(3, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"00110110101101001111101101001011010011111011010010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; long long Arg2 = 999999999999915LL; long long Arg3 = 1000000000000000LL; int Arg4 = 50; verify_case(4, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	/*void test_case_5() { string Arr0[] = {"10000", "011011001011000001101000010100000111000110110", 
"000001010001011000001101110", "100100000110100001010000", 
"011011010", "01100000010101101110000011100011001000",
"0001010", "010011000", "000101001", "00", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 91; long long Arg2 = 123456LL; long long Arg3 = 123654LL; int Arg4 = 76; verify_case(5, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }*/
	void test_case_5() { string Arr0[] = {"10","001","0100","00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; long long Arg2 = 97959288696179LL; long long Arg3 = 97959288697179LL; int Arg4 = 50; verify_case(4, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MagicalGirlLevelThreeDivTwo ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

