#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

class MaxFlow {
public:
	struct edge { int to, capacity, reve;};
	static const int MV = 10000;
	vector<edge> E[MV];
	int vis[MV];
	
	void init() { for(int i=0;i<MV;i++) E[i].clear();}
	MaxFlow() {init();}
	void add_edge(int x,int y, int cap) {
		E[x].push_back((edge){y,cap,(int)E[y].size()});
		E[y].push_back((edge){x,0, (int)E[x].size()-1}); /* rev edge */
	}
	
	int dfs(int from,int to,int cf) {
		int i,tf;
		if(from==to) return cf;
		vis[from]=1;
		FOR(i,E[from].size()) {
			edge& e=E[from][i];
			if(vis[e.to]==0 && e.capacity>0 && (tf = dfs(e.to,to,min(cf,e.capacity)))>0) {
				e.capacity -= tf;
				E[e.to][e.reve].capacity += tf;
				return tf;
			}
		}
		return 0;
	}
	
	int maxflow(int from, int to) {
		int fl=0,tf;
		while(1) {
			ZERO(vis);
			if((tf = dfs(from,to,1<<29))==0) return fl;
			fl+=tf;
		}
	}
};


class BlockTheBlockPuzzle {
	public:
	int N,gx,gy;
	int minimumHoles(vector <string> board) {
		int y,x,s,t;
		N=board.size();
		queue<int> Q;
		FOR(y,N) FOR(x,N) if(board[y][x]=='$') gy=y,gx=x;
		
		MaxFlow mf;
		mf.init();
		FOR(y,N) FOR(x,N) {
			if(abs(y-gy)%3==0 && abs(x-gx)%3==0) {
				if(board[y][x]=='H') continue;
				if(board[y][x]=='$') mf.add_edge(100+y*50+x,1,2500);
				if(board[y][x]=='b') mf.add_edge(0,3000+y*50+x,2500);
				if(board[y][x]=='.') mf.add_edge(100+y*50+x,3000+y*50+x,1);
				if(x+3<N) {
					s=(board[y][x+1]=='.')+(board[y][x+2]=='.');
					if(board[y][x+1]=='b' || board[y][x+2]=='b') s=2500;
					if(s>0) {
						mf.add_edge(3000+y*50+x,100+y*50+(x+1),s);
						mf.add_edge(100+y*50+(x+1),100+y*50+x,s);
					}
				}
				if(x>=3) {
					s=(board[y][x-1]=='.')+(board[y][x-2]=='.');
					if(board[y][x-1]=='b' || board[y][x-2]=='b') s=2500;
					if(s>0) {
						mf.add_edge(3000+y*50+x,100+y*50+(x-2),s);
						mf.add_edge(100+y*50+(x-2),100+y*50+x,s);
					}
				}
				if(y+3<N) {
					s=(board[y+1][x]=='.')+(board[y+2][x]=='.');
					if(board[y+1][x]=='b' || board[y+2][x]=='b') s=2500;
					if(s>0) {
						mf.add_edge(3000+y*50+x,100+(y+1)*50+x,s);
						mf.add_edge(100+(y+1)*50+x,100+y*50+x,s);
					}
				}
				if(y>=3) {
					s=(board[y-1][x]=='.')+(board[y-2][x]=='.');
					if(board[y-1][x]=='b' || board[y-2][x]=='b') s=2500;
					if(s>0) {
						mf.add_edge(3000+y*50+x,100+(y-2)*50+x,s);
						mf.add_edge(100+(y-2)*50+x,100+y*50+x,s);
					}
				}
			}
			
		}
		x=mf.maxflow(0,1);
		if(x>=2500) return -1;
		return x;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"b..$",
 "....",
 "HHHH",
 "HHHH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimumHoles(Arg0)); }
	void test_case_1() { string Arr0[] = {"............H..",
 "...............",
 "...............",
 "HHH$HHH.....H..",
 "HHHHHHH........",
 "HHHHHHHH.......",
 "......b..H.....",
 "...............",
 "...............",
 "...H..H..H.....",
 "...............",
 "...............",
 "...............",
 "...............",
 "..............."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minimumHoles(Arg0)); }
	void test_case_2() { string Arr0[] = {
 "HHH$",
 "HHH.",
 "HHH.",
 "b...",
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, minimumHoles(Arg0)); }
/*	void test_case_2() { string Arr0[] = {"............H..",
 "...............",
 "...............",
 "HHH$HHH........",
 "HHHHHHH........",
 "HHHHHHHH.......",
 "......b..H.....",
 "...............",
 "...............",
 "...H..H..H.....",
 "...............",
 "...............",
 "...............",
 "...............",
 "..............."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, minimumHoles(Arg0)); }*/
	void test_case_3() { string Arr0[] = {"b..$...",
 "...H...",
 ".......",
 "b..b..b",
 "...H...",
 ".......",
 "b..b..b"}

; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, minimumHoles(Arg0)); }
	void test_case_4() { string Arr0[] = {"b..b..b",
 "..b..b.",
 ".......",
 "b..$bbb",
 ".b.....",
 "....b..",
 "b..b..b"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, minimumHoles(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  BlockTheBlockPuzzle ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
