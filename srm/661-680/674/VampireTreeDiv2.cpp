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
vector<int> E[1010];
pair<int,ll> memo[1010][2];
int must0[1010];
int must1[1010];

class VampireTreeDiv2 {
	public:
	
	pair<int,ll> dfs(int cur,int need) {
		if(memo[cur][need].first>=-1000) return memo[cur][need];
		
		int mi=10010;
		ll pat=0;
		
		if(must0[cur]==0) {
			int mi2=1;
			ll pat2=1;
			FORR(r,E[cur]) {
				auto a=dfs(r,0);
				mi2+=a.first;
				pat2=pat2*a.second%mo;
			}
			mi=mi2, pat=pat2;
		}
		
		if(need==0 && must1[cur]==0) {
			int mi2=0;
			ll pat2=1;
			FORR(r,E[cur]) {
				auto a=dfs(r,1);
				mi2+=a.first;
				pat2=pat2*a.second%mo;
			}
			if(mi2<mi) mi=mi2, pat=pat2;
			else if(mi2==mi) pat=(pat+pat2)%mo;
		}
		return memo[cur][need] = {mi,pat};
	}
	
	int countMinSamples(vector <int> A, vector <int> B) {
		int mi=1010;
		ll ret=0;
		int N=A.size(),i;
		vector<int> ind;
		
		FOR(i,N+1) E[i].clear();
		FOR(i,N) {
			E[A[i]].push_back(i+1);
			if(B[i]!=-1) ind.push_back(i);
		}
		
		for(int mask=0;mask<1<<(ind.size());mask++) {
			ZERO(must0);
			ZERO(must1);
			FOR(i,ind.size()) {
				if(mask&(1<<i)) {
					must1[A[ind[i]]]=must1[B[ind[i]]]=1;
					must0[ind[i]+1]=1;
				}
				else {
					must1[ind[i]+1]=1;
				}
			}
			
			FOR(i,N+1) memo[i][0].first=memo[i][1].first=-1010;
			auto v = dfs(0,0);
			if(v.first<mi) mi=v.first, ret=0;
			if(v.first==mi) ret += v.second;
		}
		
		return ret % mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, countMinSamples(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, countMinSamples(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 0, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, -1, -1, -1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, countMinSamples(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, -1, -1, -1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(3, Arg2, countMinSamples(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0, 1, 1, 2, 1, 2, 2, 5, 7, 6, 5, 10, 6, 6, 12, 6, 6, 2, 8, 0, 16, 5, 8, 2, 14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, -1, -1, -1, 0, -1, -1, -1, 2, 7, 10, 11, 7, 9, -1, 5, -1, 15, 4, 7, 9, -1, 13, 6, 24}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 78; verify_case(4, Arg2, countMinSamples(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {0,1,0,3,0,5,0,7,0,9,0,11,0,13,0,15,0,17,0,19,0,21,0,23,0,25,0,27,0,29,0,31,0,33,0,35,0,37,0,39,0,41,0,43,0,45,0,47,0,49,0,51,0,53,0,55,0,57,0,59,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 73741818; verify_case(5, Arg2, countMinSamples(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  VampireTreeDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
