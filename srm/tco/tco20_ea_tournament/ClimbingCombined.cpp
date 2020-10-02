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

class ClimbingCombined {
	public:
	int findBestPlacements(int N, vector <int> S) {
		int i,j;
		FOR(i,N) S[i]*=(i+1);
		sort(ALL(S));
		reverse(ALL(S));
		ll ret=N;
		FOR(i,N) {
			set<int> T;
			for(j=2;j<=N;j++) T.insert(j);
			FOR(j,N) if(i!=j) {
				int ma=(S[i]+S[j]-1)/S[j];
				auto it=T.lower_bound(ma);
				if(it==T.end()) {
					ret++;
					T.erase(prev(it));
				}
				else {
					T.erase(it);
				}
			}
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arr1[] = {5, 7, 1, 8, 2, 3, 4, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(0, Arg2, findBestPlacements(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 8; int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 17; verify_case(1, Arg2, findBestPlacements(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {2, 3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, findBestPlacements(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arr1[] = {8, 3, 2, 4, 1, 7, 10, 6, 5, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 17; verify_case(3, Arg2, findBestPlacements(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ClimbingCombined ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

