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
vector<int> E[52];
ll mo=1000000007;
ll pat[52][52];

class FoxConnection2 {
	public:
	
	ll dfspat(int cur,int pre,int mimi,int left) {
		if(left<=1) return 1;
		if(pat[cur][left]>=0) return pat[cur][left];
		left--;
		
		ll dp[2][51];
		ZERO(dp);
		dp[0][left]=1;
		int i,x,y;
		FOR(i,E[cur].size()) {
			int curr=i%2,tar=curr^1;
			int nep=E[cur][i];
			if(nep==pre || nep<mimi) {
				memmove(dp[tar],dp[curr],sizeof(dp[tar]));
			}
			else {
				ZERO(dp[tar]);
				FOR(x,left+1) FOR(y,x+1) {
					dp[tar][x-y] += dp[curr][x]*dfspat(nep,cur,mimi,y);
					dp[tar][x-y] %= mo;
				}
			}
		}
		return pat[cur][left+1]=dp[E[cur].size()%2][0];
	}
	
	int ways(vector <int> A, vector <int> B, int k) {
		int N=A.size()+1;
		K=k;
		int i,x,y;
		
		FOR(x,N) E[x].clear();
		FOR(x,N-1) E[A[x]-1].push_back(B[x]-1),E[B[x]-1].push_back(A[x]-1);
		
		ll ret=0;
		FOR(x,N) {
			MINUS(pat);
			ret += dfspat(x,51,x,k);
		}
		return (int)(ret%mo);
	
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 3; verify_case(0, Arg3, ways(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 6; verify_case(1, Arg3, ways(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 3; verify_case(2, Arg3, ways(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,2,2,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 6; verify_case(3, Arg3, ways(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1,2,2,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 4; verify_case(4, Arg3, ways(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 923263934; verify_case(5, Arg3, ways(Arg0, Arg1, Arg2)); }
	//void test_case_6() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; verify_case(6, Arg3, ways(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arr0[] = {6, 10, 12, 7, 13, 2, 16, 5, 11, 1, 3, 14, 4, 8, 15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9, 9, 10, 6, 6, 13, 10, 2, 10, 7, 1, 12, 1, 11, 14}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 47; verify_case(6, Arg3, ways(Arg0, Arg1, Arg2)); }
// END CUT HERE
};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FoxConnection2 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

