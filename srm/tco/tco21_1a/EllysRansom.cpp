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

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 40*30;
	vector<edge> E[MV];
	int itr[MV],lev[MV];
	void add_edge(int x,int y,V cap,bool undir=false) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,undir?cap:0});
	}
	void bfs(int cur) {
		MINUS(lev);
		queue<int> q;
		lev[cur]=0;
		q.push(cur);
		while(q.size()) {
			int v=q.front(); q.pop();
			FORR(e,E[v]) if(e.cap>0 && lev[e.to]<0) lev[e.to]=lev[v]+1, q.push(e.to);
		}
	}
	V dfs(int from,int to,V cf) {
		if(from==to) return cf;
		for(;itr[from]<E[from].size();itr[from]++) {
			edge* e=&E[from][itr[from]];
			if(e->cap>0 && lev[from]<lev[e->to]) {
				V f=dfs(e->to,to,min(cf,e->cap));
				if(f>0) {
					e->cap-=f;
					E[e->to][e->reve].cap += f;
					return f;
				}
			}
		}
		return 0;
	}
	V maxflow(int from, int to) {
		V fl=0,tf;
		while(1) {
			bfs(from);
			if(lev[to]<0) return fl;
			ZERO(itr);
			while((tf=dfs(from,to,numeric_limits<V>::max()))>0) fl+=tf;
		}
	}
};


class EllysRansom {
	public:
	string getRansom(string A, string B, string T) {
		MaxFlow_dinic<int> mf;
		vector<int> P[26][26];
		int C[26]={};
		int i,x,y;
		FOR(i,A.size()) {
			P[A[i]-'A'][B[i]-'A'].push_back(i);
		}
		FORR(c,T) C[c-'A']++;
		
		FOR(x,26) FOR(y,26) {
			mf.add_edge(1000,x*26+y,P[x][y].size());
			mf.add_edge(x*26+y,1001+x,1000);
			if(x!=y) mf.add_edge(x*26+y,1001+y,1000);
		}
		FOR(x,26) mf.add_edge(1001+x,1030,C[x]);
		
		int ret=mf.maxflow(1000,1030);
		if(ret!=T.size()) return "NO SOLUTION";
		
		string R=string(A.size(),'_');
		FOR(x,26) FOR(y,26) {
			int a=0,b=0;
			FORR(e,mf.E[x*26+y]) {
				if(e.to>=1001) {
					if(x==y) a=1000-e.cap;
					else {
						if(e.to==1001+x) a=1000-e.cap;
						if(e.to==1001+y) b=1000-e.cap;
					}
				}
			}
			while(a--) {
				int p=P[x][y].back();
				R[p]=A[p];
				P[x][y].pop_back();
			}
			while(b--) {
				int p=P[x][y].back();
				R[p]=B[p];
				P[x][y].pop_back();
			}
			
		}
		return R;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "GOODLUCKANDHAVEFUNN"; string Arg1 = "RPSETSUJMITITUOHTIW"; string Arg2 = "TOPCODER"; string Arg3 = "RPOET_C___D___O____"; verify_case(0, Arg3, getRansom(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "HELP"; string Arg1 = "ELLY"; string Arg2 = "HELL"; string Arg3 = "NO SOLUTION"; verify_case(1, Arg3, getRansom(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "NEVERMINDTHENOISEYOUHEARD"; string Arg1 = "DEBRUOYREDNUTSAEBATSUJSTI"; string Arg2 = "ENTERSANDMANYEAH"; string Arg3 = "NE_ERMYNDTHENSA__A____A__"; verify_case(2, Arg3, getRansom(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "THISWASATRIUMPHIMMAKINANOTEHEREHUGE"; string Arg1 = "EVILALLITSERAOHWELPOEPEHTROFSSECCUS"; string Arg2 = "APERTURESCIENCEPORTALHASEVILTESTS"; string Arg3 = "TVISALSATRERAPHIELPOENE_TTE_SRECCUS"; verify_case(3, Arg3, getRansom(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysRansom ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

