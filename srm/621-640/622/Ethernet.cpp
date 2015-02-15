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

int memo[55][501];

class Ethernet {
	public:
	vector<pair<int,int> > E[55];
	
	int connect(vector <int> parent, vector <int> dist, int maxDist) {
		int N=parent.size()+1;
		int i,j,k,l,m,x,y;
		
		FOR(i,55) E[i].clear();
		ZERO(memo);
		
		FOR(i,N-1) E[parent[i]].push_back(make_pair(i+1,dist[i]));
		for(i=N-1;i>=0;i--) {
			FOR(j,maxDist+1) if(!E[i].empty()) {
				memo[i][j]=10000;
				
				for(k=1;k<=maxDist-j;k++) {
					l=maxDist-max(j,k);
					if(l>k) continue;
					FOR(x,E[i].size()) {
						m=0;
						FOR(y,E[i].size()) {
							int f=E[i][y].first,s=E[i][y].second;
							int t=s+((x==y)?max(j,l):max(j,k));
							m+=min((t>maxDist)?10000:memo[f][t],1+memo[f][0]);
						}
						memo[i][j]=min(m,memo[i][j]);
					}
				}
			}
		}
		
		return memo[0][0]+1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 1; verify_case(0, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 3; verify_case(1, Arg3, connect(Arg0, Arg1, Arg2)); }
/*	void test_case_1() { int Arr0[] = {0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; int Arg3 = 4; verify_case(1, Arg3, connect(Arg0, Arg1, Arg2)); }*/
	void test_case_2() { int Arr0[] = {0,1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 3; verify_case(2, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 2; verify_case(3, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_42() { int Arr0[] = {0,1,0,3,0,5,0,6,0,6,0,6,4,6,9,4,5,5,2,5,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {93,42,104,105,59,73,161,130,30,81,62,93,131,133,139,5,13,34,25,111,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 162; int Arg3 = 11; verify_case(4, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0, 1, 2, 1, 1, 2, 6, 3, 0, 2, 9, 5, 1, 9, 12, 12, 7, 5, 17, 19, 18, 16, 21, 8, 12, 6, 4, 17, 12, 0, 24, 2, 4, 21, 13, 9, 21, 33, 3, 36, 16, 14, 34, 22, 37, 8, 1, 17, 22, 45}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 2, 6, 5, 4, 5, 7, 1, 6, 2, 5, 4, 5, 2, 6, 3, 5, 1, 3, 4, 3, 4, 1, 2, 7, 6, 2, 7, 7, 2, 6, 6, 6, 2, 7, 6, 5, 6, 6, 5, 3, 7, 2, 2, 7, 2, 4, 5, 7, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; int Arg3 = 28; verify_case(4, Arg3, connect(Arg0, Arg1, Arg2)); }
// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  Ethernet ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
