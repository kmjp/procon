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

class SubtreeSum {
	public:
	
	int getSum(vector <int> p, vector <int> x) {
		ll mo=1000000007;
		int i,j;
		int N=x.size();
		vector<int> E[51];
		FOR(i,N-1) E[p[i]].push_back(i+1);
		
		ll tot=0;
		FOR(i,30) {
			ll ret=0;
			ll num[2][50]={};
			
			for(j=N-1;j>=0;j--) {
				num[(x[j]>>i)&1][j]=1;
				FORR(r,E[j]) {
					ll a0=num[0][j],a1=num[1][j];
					num[0][j] = a0 * (1+num[0][r]);
					num[1][j] = a1 * (1+num[0][r] + num[1][r]) + a0 * num[1][r];
				}
				ret += num[1][j];
			}
			
			tot += ((ret%mo)<<i)%mo;
		}
		return tot % mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(0, Arg2, getSum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 23; verify_case(1, Arg2, getSum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,0,0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 33999993; verify_case(2, Arg2, getSum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,0,1,0,2,2,3,0,0,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,5,6,7,0,8,9,5,1,2,3,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6378; verify_case(3, Arg2, getSum(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SubtreeSum ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
