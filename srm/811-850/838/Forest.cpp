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

vector<ll> cand;
ll p10[10];
unordered_map<ll,int> M;

double fromP[30000];
double fromS[30000];
double toP[30000];
double toS[30000];
ll memo[30000][10][10];

class Forest {
	public:
	
	void dfs(int N,int cur,ll v) {
		if(cur==N) {
			cand.push_back(v);
			return;
		}
		int i;
		for(i=0;i<=cur;i++) {
			if(i<cur&&((v/p10[i])%10!=i)) continue;
			dfs(N,cur+1,v+i*p10[cur]);
		}
	}
	ll merge(ll v,int a,int b) {
		
		if(memo[M[v]][a][b]>=0) return memo[M[v]][a][b];
		ll ov=v;
		int a1=(v/p10[a])%10;
		int b1=(v/p10[b])%10;
		int m=min(a1,b1);
		int i;
		FOR(i,9) {
			int c=(v/p10[i])%10;
			
			if(c==a1||c==b1) {
				v-=c*p10[i];
				v+=m*p10[i];
			}
		}
		assert(M.count(v));
		return memo[M[ov]][a][b]=v;
	}
	
	double solve(int N, vector <int> X, vector <int> Y, vector <int> L, int P) {
		vector<pair<int,pair<int,int>>> C;
		int i;
		p10[0]=1;
		FOR(i,9) p10[i+1]=p10[i]*10;
		FOR(i,L.size()) C.push_back({L[i],{X[i],Y[i]}});
		double hit=1-P/100.0;
		
		MINUS(memo);
		
		cand.clear();
		dfs(9,0,0);
		FOR(i,cand.size()) M[cand[i]]=i;
		ZERO(fromP);
		ZERO(fromS);
		fromP[M[876543210]]=1;
		sort(ALL(C));
		FORR(c,C) {
			int l=c.first;
			int x=c.second.first;
			int y=c.second.second;
			ZERO(toP);
			ZERO(toS);
			FOR(i,cand.size()) if(fromP[i]) {
				ll a=cand[i];
				ll b=merge(cand[i],x,y);
				if(a==b) {
					toP[i]+=fromP[i];
					toS[i]+=fromP[i]*fromS[i];
				}
				else {
					toP[i]+=(1-hit)*fromP[i];
					toS[i]+=(1-hit)*fromP[i]*fromS[i];
					toP[M[b]]+=hit*fromP[i];
					toS[M[b]]+=hit*fromP[i]*(l+fromS[i]);
				}
			}
			
			swap(fromS,toS);
			swap(fromP,toP);
			FOR(i,cand.size()) if(fromP[i]) fromS[i]/=fromP[i];
		}
		
		double ret=0;
		FOR(i,cand.size()) ret+=fromS[i]*fromP[i];
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {0, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 4, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; double Arg5 = 7.0; verify_case(0, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {0, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 4, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 100; double Arg5 = 0.0; verify_case(1, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {47}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 90; double Arg5 = 4.699999999999999; verify_case(2, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 3; int Arr1[] = {0, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 4, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 50; double Arg5 = 5.375; verify_case(3, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Forest ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

