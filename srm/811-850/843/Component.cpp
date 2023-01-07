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

map<vector<pair<int,int>>,double> M;
vector<vector<pair<int,int>>> C[55];

class Component {
	public:
	int S;
	void dfs(vector<pair<int,int>> V,int nex,int lef) {
		if(lef==0) {
			V=normalize(V);
			M[V]=0;
			int len=0;
			FORR2(a,b,V) len+=b;
			C[len].push_back(V);
		}
		else {
			int i;
			for(i=1;i<=min(nex,lef);i++) {
				vector<pair<int,int>> NV=V;
				NV.push_back({i,1});
				dfs(NV,i,lef-i);
			}
		}
	}
	
	vector<pair<int,int>> normalize(vector<pair<int,int>> V) {
		map<int,int> M;
		int ov=0;
		FORR2(a,b,V) {
			if(b<0) return {};
			if(b==0) continue;
			if(a>=S+1) ov+=a;
			else M[a]+=b;
		}
		V.clear();
		FORR2(a,b,M) V.push_back({a,b});
		if(ov) V.push_back({ov,1});
		return V;
	}
	
	
	double solve(int N, int S) {
		this->S=S;
		if(S<=2||N==S) return 1;
		
		M.clear();
		int i;
		FOR(i,51) C[i].clear();
		dfs({},N,N);
		M[C[1][0]]=1;
		
		int x,y;
		for(i=2;i<=N;i++) {
			FORR(V,C[i]) {
				int isS=0;
				int tpat=N*(N-1)/2;
				int sum=0;
				FORR2(a,b,V) {
					if(a==S) isS=1;
					tpat-=a*(a-1)/2*b;
				}
				if(isS) continue;
				
				double ret=0;
				FOR(x,V.size()) {
					vector<pair<int,int>> W=V;
					W[x].second--;
					W[x].second--;
					W.push_back({W[x].first*2,1});
					W=normalize(W);
					if(W.size()) {
						assert(M.count(W));
						ret+=M[W]*V[x].first*V[x].first*V[x].second*(V[x].second-1)/2;
					}
					FOR(y,x) {
						vector<pair<int,int>> W=V;
						W[x].second--;
						W[y].second--;
						W.push_back({W[x].first+W[y].first,1});
						W=normalize(W);
						if(W.size()) {
							assert(M.count(W));
							ret+=M[W]*V[x].first*V[y].first*V[x].second*V[y].second;
						}
					}
				}
				
				M[V]=ret/tpat;
				
			}
		}
		
		return 1-M[C[N][0]];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 2; double Arg2 = 1.0; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 5; double Arg2 = 1.0; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 3; double Arg2 = 0.7999999999999999; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 4; double Arg2 = 0.7042957042957044; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 1; double Arg2 = 1.0; verify_case(4, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Component ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

