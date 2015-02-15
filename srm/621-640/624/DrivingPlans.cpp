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

vector<pair<int,int> > E[2001];
ll D[2][2001];
int mult[2001];
ll pat[2001];
ll mo=1000000009;

class DrivingPlans {
	public:
	int M;
	int count(int N, vector <int> A, vector <int> B, vector <int> C) {
		M=A.size();
		int i,x;
		
		ZERO(mult);
		FOR(i,N) E[i].clear();
		FOR(i,M) E[A[i]-1].push_back(make_pair(C[i],B[i]-1));
		FOR(i,M) E[B[i]-1].push_back(make_pair(C[i],A[i]-1));
		FOR(i,M) if(C[i]==0) mult[A[i]-1]=mult[B[i]-1]=1;
		
		FOR(i,N) D[0][i]=D[1][i]=1LL<<60;
		D[0][N-1]=D[1][0]=0;
		ZERO(pat);
		pat[0]=1;
		
		priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > Q,Q2;
		FOR(x,2) {
			Q.push(make_pair(0,(x==1)?0:(N-1)));
			while(!Q.empty()) {
				pair<int,int> k=Q.top();
				Q.pop();
				int cur=k.second;
				if(k.first != D[x][cur]) continue;
				if(x==1 && D[0][cur]+D[1][cur]!=D[0][0]) continue;
				if(x==1 && mult[cur]) return -1;
				
				FOR(i,E[cur].size()) {
					int tar=E[cur][i].second;
					if(D[x][tar] > D[x][cur]+E[cur][i].first) {
						D[x][tar] = D[x][cur]+E[cur][i].first;
						Q.push(make_pair(D[x][tar],tar));
					}
					if(x==1 && D[0][cur]==D[0][tar]+E[cur][i].first) pat[tar]=(pat[tar]+pat[cur])%mo;
				}
			}
		}
		
		return pat[N-1]%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {1,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {1,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 7; int Arr1[] = {1,1,2,3,4,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4,5,6,7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,2,2,3,3,4,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  DrivingPlans ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
