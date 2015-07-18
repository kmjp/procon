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

int dp[101];

class YetAnotherCardGame {
	public:
	int maxCards(vector <int> petr, vector <int> snuke) {
		int N=petr.size(),i,x,y,z;
		sort(petr.begin(),petr.end());
		sort(snuke.begin(),snuke.end());
		
		ZERO(dp);
		FOR(i,N) {
			for(x=100;x>=0;x--) {
				FOR(z,N) if(petr[z]>x) break;
				if(z<N) dp[petr[z]]=max(dp[petr[z]],dp[x]+1);
			}
			for(x=100;x>=0;x--) {
				FOR(z,N) if(snuke[z]>x) break;
				if(z<N) dp[snuke[z]]=max(dp[snuke[z]],dp[x]+1);
			}
		}
		
		return *max_element(dp,dp+101);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, maxCards(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, maxCards(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 4, 6, 7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 7, 1, 5, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(2, Arg2, maxCards(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {19, 99, 86, 30, 98, 68, 73, 92, 37, 69, 93, 28, 58, 36, 86, 32, 46, 34, 71, 29}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {28, 29, 22, 75, 78, 75, 39, 41, 5, 14, 100, 28, 51, 42, 9, 25, 12, 59, 98, 83}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 28; verify_case(3, Arg2, maxCards(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  YetAnotherCardGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
