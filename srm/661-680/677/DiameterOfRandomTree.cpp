#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
vector<int> E[100];
double dp[55][110][110];

class DiameterOfRandomTree {
	public:
	
	void go(int cur,int pre) {
		int a,b,c,d,i;
		double from[110][110]={};
		double to[110][110];
		from[0][0]=1;
		
		FORR(tar,E[cur]) if(tar!=pre) {
			go(tar,cur);
			ZERO(to);
			
			FOR(a,103) FOR(b,103) if(from[a][b]>=1e-12) {
				FOR(c,103) FOR(d,103) if(dp[tar][c][d]>=1e-12) {
					for(i=1;i<=2;i++) {
						int longer=max(a,c+i);
						int dia=max(b,max(d,a+c+i));
						to[longer][dia] += from[a][b] * dp[tar][c][d] * 0.5;
					}
				}
			}
			swap(from,to);
		}
		memmove(dp[cur],from,sizeof(from));
		
	}
	
	double getExpectation(vector <int> a, vector <int> b) {
		int i,j;
		ZERO(dp);
		N=a.size()+1;
		
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			E[a[i]].push_back(b[i]);
			E[b[i]].push_back(a[i]);
		}
		go(0,-1);
		
		double ret=0;
		FOR(i,110) FOR(j,110) ret+=dp[0][i][j]*max(i,j);
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.0; verify_case(0, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.375; verify_case(1, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,0,0,1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.25; verify_case(2, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.9609375; verify_case(3, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,0,0,1,2,3,5,6,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 10.53125; verify_case(4, Arg2, getExpectation(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DiameterOfRandomTree ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
