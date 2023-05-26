#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


class HockeyAllStars {
	public:
	long long split(vector <int> S, int K) {
		int N=13;
		while(S.size()<N*2) S.push_back(0);
		vector<pair<ll,ll>> D[2];
		int mask,i,s;
		FOR(s,2) {
			FOR(mask,1<<N) {
				for(int sm=mask;sm>=0;sm--) {
					sm=sm&mask;
					int dif=0;
					int u=0;
					FOR(i,N) {
						if(mask&(1<<i)) {
							if(sm&(1<<i)) dif+=S[i+(s*N)];
							else dif-=S[i+(s*N)];
						}
						else {
							u+=S[i+(s*N)];
						}
					}
					D[s].push_back({dif,u});
				}
			}
			sort(ALL(D[s]));
		}
		ll ret=1LL<<60;
		FOR(s,2) {
			ll mi=1LL<<60;
			for(int L=0,R=0;L<D[0].size();L++) {
				while(R<D[0].size()&&D[1][R].first<=D[0][L].first) {
					mi=min(mi,D[1][R].second-D[1][R].first*K);
					R++;
				}
				ret=min(ret,D[0][L].first*K+D[0][L].second+mi);
			}
			
			
			swap(D[0],D[1]);
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100, 200, 300, 400, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; long long Arg2 = 0LL; verify_case(0, Arg2, split(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; long long Arg2 = 100LL; verify_case(1, Arg2, split(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100, 200, 300, 1000, 4000, 4010, 400}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 20LL; verify_case(2, Arg2, split(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {100, 200, 300, 1000, 4000, 4010, 400}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; long long Arg2 = 8010LL; verify_case(3, Arg2, split(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {10, 20, 147, 147, 1000, 1001}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; long long Arg2 = 130LL; verify_case(4, Arg2, split(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  HockeyAllStars ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

