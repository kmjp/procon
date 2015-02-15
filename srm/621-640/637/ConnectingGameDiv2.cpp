#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 1100;
	vector<edge> E[MV];
	int itr[MV],lev[MV];
	
	void add_edge(int x,int y,V cap) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,0}); /* rev edge */
	}
	
	void bfs(int cur) {
		MINUS(lev);
		queue<int> q;
		lev[cur]=0;
		q.push(cur);
		while(q.size()) {
			int v=q.front(); q.pop();
			ITR(e,E[v]) if(e->cap>0 && lev[e->to]<0) lev[e->to]=lev[v]+1, q.push(e->to);
		}
	}
	
	int dfs(int from,int to,V cf) {
		if(from==to) return cf;
		ITR(e,E[from]) if(e->cap>0 && lev[from]<lev[e->to]) {
			V f=dfs(e->to,to,min(cf,e->cap));
			if(f>0) {
				e->cap-=f;
				E[e->to][e->reve].cap += f;
				return f;
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

int num[256],t[256],b[256];
int mat[256][256];


class ConnectingGameDiv2 {
	public:
	int getmin(vector <string> board) {
		int H,W,y,x,i;
		H=board.size();
		W=board[0].size();
		ZERO(num);
		ZERO(t);
		ZERO(b);
		ZERO(mat);
		
		FOR(x,W) t[board[0][x]]=1,b[board[H-1][x]]=1;
		FOR(y,H) FOR(x,W) num[board[y][x]]++;
		FOR(y,H) FOR(x,W) FOR(i,4) {
			int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
			int tx=x+dx[i],ty=y+dy[i];
			if(ty<0 || ty>=H || tx<0 || tx>=W) continue;
			if(board[y][x]!=board[ty][tx] ) mat[board[y][x]][board[ty][tx]]=1;
		}
		
		MaxFlow_dinic<int> mf;
		
		FOR(x,256) {
			if(t[x]) mf.add_edge(0,x+1,3000);
			if(b[x]) mf.add_edge(x+257,530,3000);
			mf.add_edge(x+1,x+257,num[x]);
			FOR(y,256) if(mat[x][y]) mf.add_edge(x+257,y+1,3000);
		}
		return mf.maxflow(0,530);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AA"
,"BC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arr0[] = {"AAB"
,"ACD"
,"CCD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arr0[] = {"iii"
,"iwi"
,"iii"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arr0[] = {"rng58"
,"Snuke"
,"Sothe"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arr0[] = {"yyAArJqjWTH5","yyEEruYYWTHG","hooEvutpkkb2","OooNgFFF9sbi","RRMNgFL99Vmm","R76XgFF9dVVV","SKnZUPf88Vee"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(4, Arg1, getmin(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ConnectingGameDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
