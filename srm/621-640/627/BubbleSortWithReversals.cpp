#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int num[55][55][55];
int num2[55],dp[55][55];

class BubbleSortWithReversals {
	public:
	int getMinSwaps(vector <int> A, int K) {
		int i,x,y,z,j;
		int L=A.size();
		ZERO(num);
		ZERO(num2);
		FOR(y,L) FOR(x,y) num2[y]+=A[x]>A[y];
		FOR(z,L) FOR(y,z) FOR(x,y+1) {
			for(i=x;i<y;i++) num[x][y][z]+=num2[i];
			for(i=y;i<=z;i++) {
				FOR(j,y) num[x][y][z]+=A[j]>A[i];
				for(j=i+1;j<=z;j++) num[x][y][z]+=A[i]<A[j];
			}
		}
		
		
		FOR(x,51) FOR(y,51) dp[x][y]=10000;
		dp[0][K]=0;
		int ret=10000;
		for(x=0;x<L;x++) {
			FOR(y,x) {
				dp[x][K-1]=min(dp[x][K-1],num[0][y][x]);
				FOR(i,K-1) FOR(z,y) dp[x][i]=min(dp[x][i],dp[z][i+1]+num[z+1][y][x]);
			}
			
			j=0;
			for(y=x+1;y<L;y++) j+=num2[y];
			FOR(i,K+1) ret=min(ret,j+dp[x][i]);
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6,8,8,7,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(0, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {7,2,2,13,5,5,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {12,5,1,10,12,6,6,10,6,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 12; verify_case(2, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; verify_case(3, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {482,619,619,601,660,660,691,691,77,77,96,77}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 22; verify_case(4, Arg2, getMinSwaps(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  BubbleSortWithReversals ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
