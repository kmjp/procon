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

int mat[51][51];
string DE="Demon",AN="Angel",UN="Unknown";

template<int NV,class V> class MinCostFlow {
public:
	struct edge { int to, capacity; V cost; int reve;};
	vector<edge> E[NV]; int prev_v[NV], prev_e[NV]; V dist[NV];
	void add_edge(int x,int y, int cap, V cost) {
		E[x].push_back((edge){y,cap,cost,(int)E[y].size()});
		E[y].push_back((edge){x,0, -cost,(int)E[x].size()-1}); /* rev edge */
	}
	
	V mincost(int from, int to, ll flow) {
		V res=0; int i,v;
		ZERO(prev_v); ZERO(prev_e);
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
					if(e.capacity>0 && dist[e.to]>d+e.cost) {
						dist[e.to]=d+e.cost;
						prev_v[e.to]=cur;
						prev_e[e.to]=i;
						Q.push(make_pair(-dist[e.to],e.to));
					}
				}
			}
			
			if(dist[to]==numeric_limits<V>::max()/2) return -1;
			int lc=flow;
			for(v=to;v!=from;v=prev_v[v]) lc = min(lc, E[prev_v[v]][prev_e[v]].capacity);
			flow -= lc;
			res += lc*dist[to];
			for(v=to;v!=from;v=prev_v[v]) {
				edge &e=E[prev_v[v]][prev_e[v]];
				e.capacity -= lc;
				E[v][e.reve].capacity += lc;
			}
		}
		return res;
	}
};

class AngelDemonGame {
	public:
	int N;
	string winner(vector <string> G, int A, int D) {
		MinCostFlow<50,int> mcf;
		
		N=G.size();
		if(D>=N-1) return DE;
		
		int x,y;
		FOR(x,N) FOR(y,N) if(x!=y) mcf.add_edge(x,y,1,G[x][y]=='N');
		if(mcf.mincost(0,N-1,D+1)<=A) return AN;
		return UN;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYNY",
 "YNYY",
 "NYNN",
 "YYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; string Arg3 = "Angel"; verify_case(0, Arg3, winner(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"NYNY",
 "YNYY",
 "NYNN",
 "YYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 6; string Arg3 = "Demon"; verify_case(1, Arg3, winner(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"NNNN",
 "NNNN",
 "NNNN",
 "NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; string Arg3 = "Unknown"; verify_case(2, Arg3, winner(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"NYNNNY",
 "YNNYNN",
 "NNNNYN",
 "NYNNNN",
 "NNYNNN",
 "YNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 4; string Arg3 = "Unknown"; verify_case(3, Arg3, winner(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"NYNNNY",
 "YNNYNN",
 "NNNNYN",
 "NYNNNN",
 "NNYNNN",
 "YNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 4; string Arg3 = "Angel"; verify_case(4, Arg3, winner(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"NYNNNY",
 "YNNYNN",
 "NNNNYN",
 "NYNNNN",
 "NNYNNN",
 "YNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 8; string Arg3 = "Demon"; verify_case(5, Arg3, winner(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AngelDemonGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

