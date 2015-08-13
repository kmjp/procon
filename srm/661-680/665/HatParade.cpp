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

ll mo=1000000007;

class HatParade {
	public:
	int N;
	ll tsum;
	map<pair<vector<pair<ll,ll>>,ll>,ll> memo;
	
	ll dfs(vector<pair<ll,ll>> M,ll lsum,ll rsum) {
		if(M.empty()) return 1;
		if(lsum>rsum) swap(lsum,rsum);
		if(memo.count({M,lsum})) return memo[{M,lsum}];
		
		ll ret=0;
		int i;
		FOR(i,M.size()) {
			if((lsum+M[i].first==M[i].second) || (M[i].second==tsum-lsum)) {
				vector<pair<ll,ll>> M2=M;
				M2.erase(M2.begin()+i);
				ret += dfs(M2,lsum+M[i].first,rsum);
			}
		}
		return memo[{M,lsum}]=ret%mo;
	}
	
	int getPermutation(vector <int> value, vector <int> sum) {
		
		memo.clear();
		N=value.size();
		
		int i;
		tsum=0;
		vector<pair<ll,ll>> M;
		FOR(i,N) M.push_back({value[i],sum[i]}), tsum+=value[i];
		sort(M.begin(),M.end());
		
		return dfs(M,0,0);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 1, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, getPermutation(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9, 1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, getPermutation(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4, 4, 4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {16, 16, 8, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(2, Arg2, getPermutation(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 27, 6, 22, 18, 21, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, getPermutation(Arg0, Arg1)); }
	
// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  HatParade ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
