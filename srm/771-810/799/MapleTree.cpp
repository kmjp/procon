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
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
vector<pair<int,int>> E[2020];
const ll mo=1000000007;

ll dp[2020][2020];
vector<pair<int,int>> tar[2020][2020];

vector<pair<ll,int>> V;

void dfs(int cur,int pre,int id,ll d) {
	V.push_back({d,cur});
	dp[id][cur]=d;
	int x=lower_bound(ALL(V),make_pair(d/2,0))-V.begin();
	if(id<cur) {
		if(V[x].first!=d/2) {
			int a=V[x-1].second;
			int b=V[x].second;
			if(a<b) tar[a][b].push_back({id,cur});
			else tar[b][a].push_back({cur,id});
		}
		else {
			tar[V[x].second][V[x].second].push_back({cur,id});
		}
	}
	FORR(e,E[cur]) if(e.first!=pre) dfs(e.first,cur,id,d+e.second);
	V.pop_back();
}

void dfs2(int cur,int pre,vector<ll>& A,ll d) {
	A.push_back(d);
	FORR(e,E[cur]) if(e.first!=pre) dfs2(e.first,cur,A,d+e.second);
	
}
class MapleTree {
	public:
	int sum(vector <int> p, vector <int> length) {
		N=p.size()+1;
		int i,j,x,y;
		
		FOR(i,N+1) E[i].clear();
		FOR(x,N) FOR(y,N) tar[x][y].clear();
		FOR(i,p.size()) {
			E[p[i]].push_back({i+1,length[i]*2});
			E[i+1].push_back({p[i],length[i]*2});
		}
		FOR(i,N) dfs(i,i,i,0);
		ll ret=0;
		FOR(i,N) {
			set<ll> cand;
			FORR(a,tar[i][i]) {
				cand.insert(dp[a.first][a.second]/2);
			}
			vector<vector<ll>> A;
			FORR(e,E[i]) {
				vector<ll> B;
				dfs2(e.first,i,B,e.second);
				sort(ALL(B));
				A.push_back(B);
			}
			FORR(c,cand) {
				ll dp[3]={1,0,0};
				FORR(b,A) {
					ll v=1;
					ll le=1,eq=0;
					FORR(a,b) {
						if(a<c) (le+=v)%=mo;
						if(a==c) (eq+=v)%=mo;
						v=v*2%mo;
					}
					ll dp2[3]={dp[0],dp[1],dp[2]};
					dp[0]=dp2[0]*le%mo;
					dp[1]=(dp2[1]*le+dp2[0]*eq)%mo;
					dp[2]=(dp2[1]*eq+dp2[2]*(le+eq))%mo;
				}
				(ret+=dp[2]*c*2*2)%=mo;
			}
		}
		FOR(x,N) FOR(y,N) if(x!=y&&tar[x][y].size()) {
			vector<ll> A,B;
			dfs2(x,y,A,0);
			dfs2(y,x,B,0);
			sort(ALL(A));
			sort(ALL(B));
			map<ll,ll> MA,MB;
			ll v=1;
			FORR(a,A) (MA[a]+=v)%=mo, v=v*2%mo;
			v=1;
			FORR(a,B) (MB[a]+=v)%=mo, v=v*2%mo;

			set<pair<ll,ll>> cand;
			FORR(e,tar[x][y]) cand.insert({dp[e.first][x],dp[y][e.second]});
			FORR(e,cand) {
				ll s=e.first,t=e.second;
				ll len=s+t+dp[x][y];
				(ret+=MA[s]*MB[t]%mo*len)%=mo;
			}
			
		}
		
		return ret*(mo+1)/2%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 1, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 1, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 249; verify_case(0, Arg2, sum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 10, 10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 720; verify_case(1, Arg2, sum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 10, 10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 480; verify_case(2, Arg2, sum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(3, Arg2, sum(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MapleTree ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

