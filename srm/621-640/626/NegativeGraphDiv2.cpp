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

ll cost[51][51],one[51][51];
ll cost2[51][51],one2[51][51];
ll mamat[51][51];

class NegativeGraphDiv2 {
	public:
	long long findMin(int N, vector <int> s, vector <int> t, vector <int> weight, int charges) {
		int i,x,y,z;
		int E=s.size();
		
		FOR(x,N) FOR(y,N) cost[x][y]=one[x][y]=1LL<<60;
		FOR(x,N) FOR(y,N) mamat[x][y]=-1;
		FOR(x,N) cost[x][x]=one[x][x]=0;
		FOR(i,E) {
			cost[s[i]-1][t[i]-1]=min(cost[s[i]-1][t[i]-1],(ll)weight[i]);
			mamat[s[i]-1][t[i]-1]=max(mamat[s[i]-1][t[i]-1],(ll)weight[i]);
		}
		
		FOR(x,N) FOR(y,N) FOR(z,N) cost[y][z]=min(cost[y][z],cost[y][x]+cost[x][z]);
		FOR(x,N) FOR(y,N) FOR(z,N) FOR(i,N) if(mamat[z][i]>=0) one[x][y]=min(one[x][y],cost[x][z]-mamat[z][i]+cost[i][y]);
		
		while(charges>0) {
			if(charges&1) {
				FOR(x,N) FOR(y,N) cost2[x][y]=1LL<<60;
				FOR(x,N) FOR(y,N) FOR(z,N) cost2[y][z]=min(cost2[y][z],cost[y][x]+one[x][z]);
				FOR(x,N) FOR(y,N) cost[x][y]=cost2[x][y];
			}
			FOR(x,N) FOR(y,N) one2[x][y]=1LL<<60;
			FOR(x,N) FOR(y,N) FOR(z,N) one2[y][z]=min(one2[y][z],one[y][x]+one[x][z]);
			FOR(x,N) FOR(y,N) one[x][y]=one2[x][y];
			charges>>=1;
		}
		
		
		return cost[0][N-1];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1,1,2,2,3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,1,3,1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,5,1,10,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; long long Arg5 = -9LL; verify_case(0, Arg5, findMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 1; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {100}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1000; long long Arg5 = -100000LL; verify_case(1, Arg5, findMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {1,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6,1,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; long long Arg5 = -9LL; verify_case(2, Arg5, findMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {98765}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 100; long long Arg5 = -98765LL; verify_case(3, Arg5, findMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  NegativeGraphDiv2 ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
