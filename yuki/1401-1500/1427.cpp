#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 102;
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

int H,W;
string S[10];
int line;

void dfs(vector<string>& T,int did) {
	if(T.size()>H) return;
	if(did==line) {
		MaxFlow_dinic<int> mf;
		int x,y;
		int num=0;
		FOR(y,T.size()) FOR(x,W) {
			if(T[y][x]=='#') num++;
			if((y+x)%2==0) {
				if(T[y][x]=='#') mf.add_edge(100,y*10+x,1);
				if(y) mf.add_edge(y*10+x,(y-1)*10+x,1);
				if(y+1<T.size()) mf.add_edge(y*10+x,(y+1)*10+x,1);
				if(x) mf.add_edge(y*10+x,y*10+x-1,1);
				if(x+1<W) mf.add_edge(y*10+x,y*10+x+1,1);
			}
			else {
				if(T[y][x]=='#') mf.add_edge(y*10+x,101,1);
			}
		}
		if(mf.maxflow(100,101)*2==num) {
			int pat=0;
			FOR(y,T.size()) FOR(x,W) {
				if(T[y][x]=='#' && (y+x)%2==0) {
					T[y][x]=(pat<26)?('a'+pat):('A'+pat-26);
					FORR(e,mf.E[y*10+x]) if(e.cap==0&&e.to!=100) {
						T[e.to/10][e.to%10]=T[y][x];
					}
					pat++;
				}
			}
			
			while(T.size()<H) T.push_back(string(W,'.'));
			reverse(ALL(T));
			cout<<"Yes"<<endl;
			FORR(t,T) cout<<t<<endl;
			exit(0);
		}
	}
	
	if(did<line) {
		T.push_back(S[H-1-did]);
		dfs(T,did+1);
		T.pop_back();
	}
	T.push_back(string(W,'#'));
	dfs(T,did);
	T.pop_back();
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	int emp=0;
	for(y=H-1;y>=0;y--) {
		int num=0;
		FOR(x,W) num+=S[y][x]=='#';
		if(num==W) return _P("No\n");
		if(num==0) {
			emp=1;
		}
		else {
			line++;
			if(emp) return _P("No\n");
		}
	}
	
	vector<string> T;
	dfs(T,0);
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
