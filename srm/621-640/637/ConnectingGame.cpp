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
	static const int MV = 1002;
	vector<edge> E[MV];
	int itr[MV],lev[MV];
	
	void add_edge(int x,int y,V cap) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		//E[y].push_back((edge){x,(int)E[x].size()-1,0}); // directed
		E[y].push_back((edge){x,(int)E[x].size()-1,cap}); // undirect
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


class ConnectingGame {
	public:
	int H,W;
	string isValid(vector <string> board) {
		int y,x,i;
		H=board.size();
		W=board[0].size();
		
		MaxFlow_dinic<int> mf;
		mf.add_edge(0,1000,1);
		mf.add_edge(W,1000,1);
		mf.add_edge(H*(W+1),1000,1);
		mf.add_edge(H*(W+1)+W,1000,1);
		
		FOR(x,W) {
			mf.add_edge(x,x+1,1);
			mf.add_edge(H*(W+1)+x,H*(W+1)+x+1,1);
		}
		FOR(y,H) {
			mf.add_edge(y*(W+1),(y+1)*(W+1),1);
			mf.add_edge(y*(W+1)+W,(y+1)*(W+1)+W,1);
		}
		
		FOR(y,H) FOR(x,W-1) if(board[y][x]!=board[y][x+1]) mf.add_edge(y*(W+1)+x+1,(y+1)*(W+1)+x+1,1);
		FOR(y,H-1) FOR(x,W) if(board[y][x]!=board[y+1][x]) mf.add_edge((y+1)*(W+1)+x,(y+1)*(W+1)+x+1,1);
		
		FOR(y,H-1) FOR(x,W-1) {
			if(board[y][x]==board[y][x+1]) continue;
			if(board[y][x]==board[y+1][x]) continue;
			if(board[y][x+1]==board[y+1][x+1]) continue;
			if(board[y+1][x]==board[y+1][x+1]) continue;
			if(board[y][x]==board[y+1][x+1]) continue;
			if(board[y+1][x]==board[y][x+1]) continue;
			
			MaxFlow_dinic<int> mf2=mf;
			if(mf2.maxflow((y+1)*(W+1)+(x+1),1000)==4) return "invalid";
		}
		return "valid";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AAB"
,"CCD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "invalid"; verify_case(0, Arg1, isValid(Arg0)); }
	void test_case_1() { string Arr0[] = {"AA"
,"BB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "valid"; verify_case(1, Arg1, isValid(Arg0)); }
	void test_case_2() { string Arr0[] = {"iii"
,"iwi"
,"iii"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "valid"; verify_case(2, Arg1, isValid(Arg0)); }
	void test_case_3() { string Arr0[] = {"SSnukee"
,"SKnuthe"
,"SSSothe"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "invalid"; verify_case(3, Arg1, isValid(Arg0)); }
	void test_case_4() { string Arr0[] = {"rng58"
,"rnggn"
,"rnnnn"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "valid"; verify_case(4, Arg1, isValid(Arg0)); }
//	void test_case_5() { string Arr0[] = {"ggssGGGGGG","ggssspGGGG","ggsssppGGG","ggWsspGGGG","gggsspGGiG","g7ssspGGGG","gggsseKK33","gggssssK33","gHgsssHA33","HHHHHHHHHH","HHHHHHHHH6","HHHHHHHHb6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "invalid"; verify_case(5, Arg1, isValid(Arg0)); }
void test_case_5() { string Arr0[] = {"kkkHHHeeeeeexxxIIIIIIIIIIIIIII",
"kkkHHHxeeeeexxxxIIIIIIIIIIIIII",
"HkkkHHxxxxxxxxxIIIIIINNNIIIIII",
"HHHHHHxxxxxxxxxIIIIINNNIIIIIii",
"vHHHHHHHHxxxxxHHIIINNNNNNNIIii",
"vHHHHHHHHxxxxHHHIIINNNNNNNNIii",
"vvvHHHHHHHxHHHHHHssNNNNNNIIIii",
"rvHHHHHHHHHHHHHHHssNNNNNNNIIii",
"rrrHHHHHHHHHHHHHHHKKKNNFFNNiii",
"rrrrHHrEEEEEEEEHHHKKKFFFFNNiii",
"rrrrrrrrEEEEEEEEaaaKFFFFNNiiii",
"QQQrrrrEEEEEEEEaaaaFFFFNNNNiii",
"QQQhhhhEEEEEEqqqaaaFFFFNNNNiii",
"QQhhhhhhhhEEEqqqqaaDDDDDNNNNNi",
"QQhhhhhhhEEEEqqqqqqDDDDDNNNN5i",
"QQhhhhhhhhhqqqqqqqqDDDDDYNN555",
"QQQhhhhhhhhqqqq7777DDDDYYYY555",
"QQQhnnhXhhhqqq77777DDDDDYY5555",
"QQQQnnXXXhhhq77777GDDDDDYY5555",
"QQQQnnXXXhhhq77777GDDDDDDYYY55",
"QQQQnXXXXhhhqqq7GGGDDDDDDDDDDD",
"nnnnnnXXXXXqqqq7GGGDDD99999DDD",
"nnnnnnnXXXXqXXXGGGGGGD999999DD",
"nnnnnnnnnXXXXXGGGGGGGDDD9999DD",
"nnnWWWWWnWWWWWSGGGGGGGDD9999DD",
"nnnWWWWWWWWWWWSSGGGGGGDD99988D",
"nnnnnnnWWWWWWWSSGGGGGGDMM9888D",
"WWnnnnWWWWWWWWSSSGGGGGMM88888D",
"WWWWWWWWWWWSSSSSSGGGMMMM88888D",
"pppWWWWWWWWSSSSSSSSMMMMM88888D"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "invalid"; verify_case(5, Arg1, isValid(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ConnectingGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
