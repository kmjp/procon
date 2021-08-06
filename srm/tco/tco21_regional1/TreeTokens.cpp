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

vector<int> E[101010];
ll p2[101010];
const ll mo=1000000007;
class TreeTokens {
	public:
	
	pair<ll,ll> dfs(int cur,int pre,int d) {
		if(E[cur].size()==1) {
			return {0,d};
		}
		else {
			pair<int,int> p={0,0};
			FORR(e,E[cur]) if(e!=pre) {
				auto q=dfs(e,cur,d+1);
				(p.first+=q.first)%=mo;
				if(p.second<=q.second) {
					if(p.second) p.first+=p2[p.second-d]-1;
					p.second=q.second;
				}
				else {
					p.first+=p2[q.second-d]-1;
				}
			}
			p.first%=mo;
			return p;
		}
	}
	
	int placeMax(int N, int G, int L, int seed) {
		ll state = seed;
		int i;
		p2[0]=1;
		FOR(i,N) {
			E[i].clear();
			p2[i+1]=p2[i]*2%mo;
		}
		for(i=1;i<N;i++) {
			state = (state * 1103515245 + 12345)%(1LL<<31);
			int tmp = (state / 1000)%L;
			int p = max(0, i-1-tmp);
			E[i].push_back(p);
			E[p].push_back(i);
		}
		ll ret=0;
		FORR(e,E[G]) {
			auto p=dfs(e,G,1);
			ret+=p.first;
			ret+=p2[p.second]-1;
		}
		return (ret%mo+mo)%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 1000000; int Arg3 = 1234567; int Arg4 = 4; verify_case(0, Arg4, placeMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 1; int Arg3 = 1234567; int Arg4 = 15; verify_case(1, Arg4, placeMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 0; int Arg2 = 2; int Arg3 = 4742; int Arg4 = 4; verify_case(2, Arg4, placeMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 5; int Arg2 = 3; int Arg3 = 47; int Arg4 = 17; verify_case(3, Arg4, placeMax(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TreeTokens ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

