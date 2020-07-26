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

// O(V^2 E)‚È‚Ì‚Åƒtƒ[‚ª¬‚³‚¢‚Æ‚«‚ÍFord-Fulkerson‚É‚·‚×‚«
template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 1100;
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
			ITR(e,E[v]) if(e->cap>0 && lev[e->to]<0) lev[e->to]=lev[v]+1, q.push(e->to);
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

vector<int> E[31][31];
int vis[31][31];
int N;
class ParkPlace {
	public:
	
	void dfs(int y,int x,int py,int px,string& S) {
		if(vis[y][x]) return;
		vis[y][x]=1;
		FORR(e,E[y][x]) {
			int ty=e/N;
			int tx=e%N;
			if(ty==py&&tx==px) continue;
			if(ty>y) S+='S';
			if(ty<y) S+='N';
			if(tx>x) S+='E';
			if(tx<x) S+='W';
			dfs(ty,tx,y,x,S);
			break;
		}
	}
	
	vector <string> construct(int N, vector <string> place) {
		::N=N;
		MaxFlow_dinic<int> mf;
		int y,x;
		int C[2]={};
		FOR(y,N) FOR(x,N) if(place[y][x]=='.') {
			C[(x+y)%2]++;
			if((x+y)%2==0) {
				mf.add_edge(1000,y*N+x,2);
				if(x) mf.add_edge(y*N+x,y*N+x-1,1);
				if(y) mf.add_edge(y*N+x,(y-1)*N+x,1);
				if(x+1<N) mf.add_edge(y*N+x,y*N+x+1,1);
				if(y+1<N) mf.add_edge(y*N+x,(y+1)*N+x,1);
			}
			else {
				mf.add_edge(y*N+x,1001,2);
			}
		}
		
		if(C[0]!=C[1]) return {};
		int ret=mf.maxflow(1000,1001);
		if(ret!=C[0]*2) return {};
		
		FOR(y,N) FOR(x,N) E[y][x].clear(), vis[y][x]=0;
		FOR(y,N) FOR(x,N) if((y+x)%2==0 && place[y][x]=='.') {
			FORR(e,mf.E[y*N+x]) {
				if(e.to<1000&&e.cap==0) {
					E[y][x].push_back(e.to);
					E[e.to/N][e.to%N].push_back(y*N+x);
				}
			}
		}
		
		vector<string> RR;
		FOR(y,N) FOR(x,N) if(place[y][x]=='.' && vis[y][x]==0) {
			string S;
			S=to_string(y)+" "+to_string(x)+" ";
			dfs(y,x,100,100,S);
			RR.push_back(S);
		}
		
		return RR;
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 4; string Arr1[] = { "#..#" ,
  "...." ,
  "...." ,
  "#..#" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 1 ESESWSWNWNEN" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, construct(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; string Arr1[] = { "...." ,
  "..#." ,
  ".#.." ,
  "...." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, construct(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; string Arr1[] = { "....." ,
  "....." ,
  "..#.." ,
  "....." ,
  "....." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 0 EEEESSWNWWSWNN", "3 0 ESWN", "3 2 EESWWN" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, construct(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; string Arr1[] = { "......" ,
  "...#.." ,
  ".#...." ,
  "....#." ,
  "......" ,
  "......" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, construct(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 6; string Arr1[] = { "......" ,
  "....#." ,
  "..#..." ,
  "...#.." ,
  ".#...." ,
  "......" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 0 EEEEESSSWNWNWWSWNN", "3 0 EESSWWNN", "4 3 EESWWN" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, construct(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 16; string Arr1[] = { "................" ,
  "................" ,
  ".####.####.####." ,
  ".####.####.####." ,
  ".#..#.#..#.#..#." ,
  ".#..#.#..#.#..#." ,
  ".#..#.#..#.#..#." ,
  ".#..#.####.####." ,
  "....#.####.####." ,
  "....#.#..#.#..#." ,
  "....#.#..#.#..#." ,
  "....#.#..#.#..#." ,
  "....#.####.####." ,
  "....#.####.####." ,
  "................" ,
  "................" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 0 ESENESENEESWSSSSSSSSSSSSSESWWNWSWWWNEENENWWSWNNENWNEEENWWWNNNNNNNN", "0 7 ESWN", "0 9 EESENESENESSSSSSSSSSSSSSSWNWSWNWSWWNENNNNNNNNNNNNNWN", "4 2 ESWN", "4 7 ESSWNN", "4 12 ESSWNN", "6 2 ESWN", "9 7 ESSWNN", "9 12 ESSWNN", "10 2 ESWN", "14 7 ESWN" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, construct(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ParkPlace ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

