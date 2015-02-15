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

double prob[2001][2001];
double dp[2001][2001];

class DoraemonPuzzleGame {
	public:
	pair<int,int> P[2001];
	double solve(vector <int> X, vector <int> Y, int m) {
		int N=X.size(),i,x;
		
		FOR(i,N) P[i]=make_pair(Y[i],i);
		m-=N;
		sort(P,P+N);
		
		ZERO(prob);
		ZERO(dp);
		
		prob[0][0]=1;
		FOR(i,N) {
			int t=P[i].second;
			
			FOR(x,m+1) if(prob[i][x]>0) {
				double mul=1000.0/(X[t]+Y[t]);
				
				dp[i][x]/=prob[i][x];
				if(x>=m) {
					prob[i+1][x]+=prob[i][x];
					dp[i+1][x]+=prob[i][x]*(dp[i][x]+mul);
				}
				else if(x+(N-i)==m) {
					prob[i+1][x+1]+=prob[i][x];
					dp[i+1][x+1]+=prob[i][x]*(dp[i][x]+1000.0/Y[t]);
				}
				else {
					prob[i+1][x+1]+=prob[i][x]*Y[t]/(double)(X[t]+Y[t]);
					prob[i+1][x]+=prob[i][x]*X[t]/(double)(X[t]+Y[t]);
					dp[i+1][x+1]+=prob[i][x]*Y[t]/(double)(X[t]+Y[t])*(dp[i][x]+mul);
					dp[i+1][x]+=prob[i][x]*X[t]/(double)(X[t]+Y[t])*(dp[i][x]+mul);
				}
			}
		}
		
		return dp[N][m];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {800}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {200}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; double Arg3 = 5.0; verify_case(0, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,999,999}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {999,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; double Arg3 = 3.0; verify_case(1, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {500,500}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {500,500}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; double Arg3 = 2.5; verify_case(2, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {250,250,250,250}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {250,250,250,250}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; double Arg3 = 8.25; verify_case(3, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {250,500,250}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {500,250,500}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; double Arg3 = 4.962962962962963; verify_case(4, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {600,900,800,500,900,200,400,100,800,300,900,300,800,700,800,600,800,900,400,100,100,700,600,100,500,
800,700,600,900,600,300,100,300,100,700,500,900,200,800,400,300,700,300,400,700,300,400,800,300,200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {400,100,200,500,100,800,600,900,200,700,100,700,200,300,200,400,200,100,600,900,900,300,400,900,500,
200,300,400,100,400,700,900,700,900,300,500,100,800,200,600,700,300,700,600,300,700,600,200,700,800}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 95; double Arg3 = 119.33578280666175; verify_case(5, Arg3, solve(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  DoraemonPuzzleGame ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
