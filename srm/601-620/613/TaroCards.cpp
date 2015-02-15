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

const int CN=55;
ll C[CN][CN];

class TaroCards {
	public:
	vector<int> V[10];
	int N;
	long long getNumber(vector <int> first, vector <int> second, int K) {
		N=first.size();
		int i,j,x,mask;
		
		FOR(x,CN) C[x][0]=C[x][x]=1;
		for(i=1;i<CN;i++) for(j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j]);
		if(K>=max(N,10)) return 1LL<<N;
		
		FOR(i,10) V[i].clear();
		FOR(i,N) V[second[i]-1].push_back(first[i]-1);
		
		ll ret=0;
		FOR(mask,1<<10) {
			if(K-__builtin_popcount(mask)<0) continue;
			
			int bi=0,kk;
			ll dp[11][51];
			ZERO(dp);
			dp[0][K-__builtin_popcount(mask)]=1;
			
			FOR(i,10) if(mask & (1<<i)) {
				int inc=0,exc=0;
				
				ITR(it,V[i]) if(*it<=10 && (mask & (1<<*it))) inc++;
				exc=V[i].size()-inc;
				
				FOR(x,exc+1) {
					FOR(kk,51) {
						if(x==0) dp[bi+1][kk]+=((1LL<<inc)-1)*dp[bi][kk];
						else if(x>0 && kk-x>=0) dp[bi+1][kk-x]+=(1LL<<inc)*C[exc][x]*dp[bi][kk];
					}
				}
				bi++;
			}
			FOR(x,51) ret+=dp[bi][x];
		}
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; long long Arg3 = 3LL; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {3, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; long long Arg3 = 8LL; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {4, 2, 1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; long long Arg3 = 16LL; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 10, 9, 3, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; long long Arg3 = 17LL; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; long long Arg3 = 1LL; verify_case(4, Arg3, getNumber(Arg0, Arg1, Arg2)); }
//	void test_case_5() { int Arr0[] = {6, 20, 1, 11, 19, 14, 2, 8, 15, 21, 9, 10, 4, 16, 12, 17, 13, 22, 7, 18, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 5, 10, 7, 6, 2, 1, 10, 10, 7, 9, 4, 5, 9, 5, 10, 10, 3, 6, 6, 4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; long long Arg3 = 2239000LL; verify_case(5, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {28, 20, 33, 49, 39, 40, 1, 16, 37, 45, 13, 27, 21, 26, 18, 6, 8, 30, 47, 24, 10, 17, 31, 4, 42, 36, 25, 3, 5, 35, 50, 34, 19, 48, 14, 41, 15, 23, 22, 32, 43, 29, 46, 38, 12, 2, 44, 11, 7, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; long long Arg3 = 1185043478LL; verify_case(5, Arg3, getNumber(Arg0, Arg1, Arg2)); }
// END CUT HERE
};

// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TaroCards ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

