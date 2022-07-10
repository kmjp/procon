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

vector<int> P[256];
int C[300][300];

template<int NV,class V> class MinCostFlow {
public:
	struct edge { int to; V capacity; V cost; int reve;};
	vector<edge> E[NV]; int prev_v[NV], prev_e[NV]; V dist[NV]; V pot[NV];
	void add_edge(int x,int y, V cap, V cost) {
		E[x].push_back((edge){y,cap,cost,(int)E[y].size()});
		E[y].push_back((edge){x,0, -cost,(int)E[x].size()-1}); /* rev edge */
	}
	
	V mincost(int from, int to, ll flow) {
		V res=0; int i,v;
		ZERO(prev_v); ZERO(prev_e); fill(pot, pot+NV, 0);
		while(flow>0) {
			fill(dist, dist+NV, numeric_limits<V>::max()/2);
			dist[from]=0;
			priority_queue<pair<V,int> > Q;
			Q.push(make_pair(0,from));
			while(Q.size()) {
				V d=-Q.top().first;
				int cur=Q.top().second;
				Q.pop();
				if(dist[cur]!=d) continue;
				if(d==numeric_limits<V>::max()/2) break;
				FOR(i,E[cur].size()) {
					edge &e=E[cur][i];
					if(e.capacity>0 && dist[e.to]>d+e.cost+pot[cur]-pot[e.to]) {
						dist[e.to]=d+e.cost+pot[cur]-pot[e.to];
						prev_v[e.to]=cur;
						prev_e[e.to]=i;
						Q.push(make_pair(-dist[e.to],e.to));
					}
				}
			}
			
			if(dist[to]==numeric_limits<V>::max()/2) return -1;
			V lc=flow;
			for(v=to;v!=from;v=prev_v[v]) lc = min(lc, E[prev_v[v]][prev_e[v]].capacity);
			FOR(i,NV) pot[i]+=dist[i];
			flow -= lc;
			res += lc*pot[to];
			for(v=to;v!=from;v=prev_v[v]) {
				edge &e=E[prev_v[v]][prev_e[v]];
				e.capacity -= lc;
				E[v][e.reve].capacity += lc;
			}
		}
		return res;
	}
};

class WW {
	public:
	int rearrange(string S) {
		int i,j,k;
		FOR(i,256) P[i].clear();
		FOR(i,S.size()) {
			P[(int)S[i]].push_back(i);
		}
		
		int N=S.size()/2;
		int nex=0;
		FOR(i,256) {
			if(P[i].size()%2) return -1;
			FOR(j,P[i].size()/2) {
				int a=P[i][j];
				int b=P[i][j+P[i].size()/2];
				FOR(k,N) {
					C[nex][k]=i*(abs(a-k)+abs(b-(N+k)));
				}
				nex++;
			}
		}
		
		MinCostFlow<330,int> mcf;
		FOR(i,N) {
			mcf.add_edge(300,i,1,0);
			mcf.add_edge(150+i,301,1,0);
			FOR(j,N) mcf.add_edge(i,150+j,1,C[i][j]);
		}
		
		return mcf.mincost(300,301,N);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "topcoder"; int Arg1 = -1; verify_case(0, Arg1, rearrange(Arg0)); }
	void test_case_1() { string Arg0 = "aaaaa"; int Arg1 = -1; verify_case(1, Arg1, rearrange(Arg0)); }
	void test_case_2() { string Arg0 = "topcodertopcoder"; int Arg1 = 0; verify_case(2, Arg1, rearrange(Arg0)); }
	void test_case_3() { string Arg0 = "intestines"; int Arg1 = 447; verify_case(3, Arg1, rearrange(Arg0)); }
	void test_case_4() { string Arg0 = "appeases"; int Arg1 = 667; verify_case(4, Arg1, rearrange(Arg0)); }
	void test_case_5() { string Arg0 = "abccba"; int Arg1 = 162; verify_case(5, Arg1, rearrange(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  WW ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

