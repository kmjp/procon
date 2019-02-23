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

int tar[10][50];

class TransformBoardDiv2 {
	public:
	vector<string> S;
	void add(vector<int>& R,int y1,int x1,int y2,int x2) {
		if(S[y1][x1]==S[y2][x2]) {
			S[y1][x1]=S[y2][x2]='.';
		}
		else {
			S[y1][x1]='.';
			S[y2][x2]='#';
		}
		R.push_back(y1*1000000+x1*10000+y2*100+x2);
	}
	
	vector <int> getOperations(vector <string> S_, vector <string> T) {
		S=S_;
		MaxFlow_dinic<int> mf;
		int H=S.size(), W=S[0].size(), N=H*W;
		int SS=0,TS=0;
		int x,y,x2,y2;
		FOR(y,H) {
			FOR(x,W) {
				if(T[y][x]=='#') TS++,mf.add_edge(N+y*W+x,2*N+1,1);
				if(S[y][x]=='#') {
					SS++;
					mf.add_edge(2*N,y*W+x,1);
					for(x2=x;x2<W;x2++) for(y2=y;y2<H;y2++) mf.add_edge(y*W+x,N+y2*W+x2,1);
				}
			}
		}
		
		if(SS<TS) return {-1};
		if((SS-TS)%2) return {-1};
		if(mf.maxflow(2*N,2*N+1)!=TS) return {-1};

		MINUS(tar);
		int pre=-1;
		FOR(y,H) FOR(x,W) if(S[y][x]=='#') {
			FORR(e,mf.E[y*W+x]) if(e.cap==0 && e.to<2*N) tar[y][x]=e.to-N;
			if(tar[y][x]==-1) {
				if(pre==-1) pre=y*W+x;
				else tar[pre/W][pre%W]=N+y*W+x, pre=-1;
			}
		}
		vector<int> R;
		for(int step=0;step<2;step++) {
			for(y=H-1;y>=0;y--) for(x=W-1;x>=0;x--) if(S[y][x]=='#' && tar[y][x]>=0) {
				int y2=tar[y][x]%N/W;
				int x2=tar[y][x]%N%W;
				
				if(step==0 && tar[y][x]<N) continue;
				
				if(y==y2 && x==x2) continue;
				
				if(y==y2 || x==x2) {
					add(R,y,x,y2,x2);
				}
				else {
					if(x<x2) {
						if(S[y][x2]=='#') {
							add(R,y,x2,y2,x2);
							add(R,y,x,y,x2);
						}
						else {
							add(R,y,x,y,x2);
							add(R,y,x2,y2,x2);
						}
					}
					else {
						add(R,y,x,y2,x);
						add(R,y2,x2,y2,x);
					}
				}
			}
		}
		
		FOR(y,H) assert(S[y]==T[y]);
		
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"#.",".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..",".#"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 10101 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getOperations(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"..",".#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"#.",".."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getOperations(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"####", "..##", "####", "##.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".#..", "..#.", ".###", "#..."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 1000103 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getOperations(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TransformBoardDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

