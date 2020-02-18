#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll V[1010];
ll dp[1010101];
class CollectingCoins {
	public:
	long long maxValue(int m, int k, vector <int> v, vector <int> d) {
		int N=v.size();
		int i,j;
		m++;
		
		for(i=1;i<k;i++) {
			V[i+1]=0;
			FOR(j,N) {
				int num=i/d[j]*(d[j]-1)+i%d[j];
				V[i+1]+=num*v[j];
			}
		}
		
		ZERO(dp);
		for(i=1;i<=k;i++) dp[i]=V[i];
		for(i=1;i<=1000000;i++) {
			for(j=2;j<=k;j++) dp[i+j]=max(dp[i+j],dp[i]+dp[j]);
		}
		ll ma=0;
		for(i=2;i<=k;i++) {
			int cur=m%i;
			int lef=(m-cur)/i;
			while(cur<=1000000 && cur<=m) {
				ma=max(ma,dp[cur]+1LL*lef*dp[i]);
				cur+=i;
				lef--;
			}
		}
		
		return ma;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 3; int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 4LL; verify_case(0, Arg4, maxValue(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 4; int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 10LL; verify_case(1, Arg4, maxValue(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_21() { int Arg0 = 10; int Arg1 = 17; int Arr2[] = {10,20}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {30,40}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 300LL; verify_case(2, Arg4, maxValue(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1000000000; int Arg1 = 1000; int Arr2[] = {10,20}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {30,40}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 300LL; verify_case(2, Arg4, maxValue(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CollectingCoins ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

