#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

deque<pair<int,int>> Q[101010];

struct HLdecomp {
	static const int MD=20;
	int N,NE,id;
	vector<vector<int>> E;
	vector<int> D,S,B,C; // depth, size, base,heavy child
	
	vector<int> L,R,rev; // EulerTour
	vector<vector<int>> P,Cs; // parent for LCA,children
	void init(int N) { this->N=N, NE=0, E.clear(),E.resize(N); Cs.clear(),Cs.resize(N);
		D=S=B=C=L=R=rev=vector<int>(N,0); id=0; int i; P.clear(); FOR(i,MD+1) P.push_back(vector<int>(N,0));}
	void add_edge(int a,int b){ E[a].push_back(b),E[b].push_back(a); NE++;} // undir
	void dfs(int cur,int pre) { // get depth, parent, size, largest subtree
		int i;
		P[0][cur]=pre;S[cur]=1;C[cur]=-1;B[cur]=cur;
		D[cur]=(pre==cur)?0:(D[pre]+1);
		FOR(i,E[cur].size()) if(E[cur][i]!=pre) {
			int r=E[cur][i]; dfs(r,cur); S[cur]+=S[r];
			if(C[cur]==-1 || S[r]>S[C[cur]]) C[cur]=r;
		}
	}
	void dfs2(int cur,int pre) { // set base and list
		if(pre!=cur && C[pre]==cur) B[cur]=B[pre];
		else B[cur]=cur;
		Cs[B[cur]].push_back(cur);
		L[cur]=id++;
		rev[L[cur]]=cur;
		// DFSèáÇêÊçs
		if(C[cur]!=-1) dfs2(C[cur],cur);
		FORR(r,E[cur]) if(r!=pre && r!=C[cur]) dfs2(r,cur);
		R[cur]=id;
	}
	pair<int,int> lca(int a,int b) {
		int ret=0,i,aa=a,bb=b;
		if(D[aa]>D[bb]) swap(aa,bb);
		for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
		for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
		return make_pair((aa==bb)?aa:P[0][aa], D[a]+D[b]-2*D[(aa==bb)?aa:P[0][aa]]);
	}
	void decomp(int root=0){
		assert(NE==N-1);
		dfs(root,root); dfs2(root,root);
		int i,x; FOR(i,MD) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	}
};

HLdecomp hl;

//Ç≥ÇÁÇ…íZèk
template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;
map<int,int> mp;
ll ret;

void dfs(int cur,int v) {
	//cout<<cur<<" "<<hl.B[cur]<<" "<<hl.P[0][hl.B[cur]]<<" "<<v<<endl;
	int b=hl.B[cur];
	if(b!=0) dfs(hl.P[0][hl.B[cur]],v);
	int num=hl.D[cur]+1-hl.D[b];
	int cn=num;
	/*
	FORR(q,Q[b]) cout<<q.first<<":"<<q.second<<" ";
	cout<<"  "<<num<<endl;
	*/
	while(cn) {
		int a=min(cn,Q[b].front().second);
		//cout<<cur<<":"<<hl.B[cur]<<" "<<b<<":"<<hl.B[b]<<" "<<hl.P[0][hl.B[b]]<<" "<<v<<" "<<cn<<" "<<a<<endl;
		ret+=1LL*bt(Q[b].front().first-1)*a;
		//cout<<"add "<<Q[b].front().first<<" "<<a<<endl;
		bt.add(Q[b].front().first,a);
		mp[Q[b].front().first]+=a;
		
		if(a<Q[b].front().second) {
			Q[b].front().second-=a;
		}
		else {
			Q[b].pop_front();
		}
		cn-=a;
	}
	if(Q[b].size()&&Q[b].front().first==v) {
		Q[b].front().second+=num;
	}
	else {
		Q[b].push_front({v,num});
	}
	
}




int N;
ll C[101010];
vector<int> E[101010];
int P[101010];
int order[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	hl.init(N);
	vector<int> V;
	V.push_back(0);
	FOR(i,N) {
		cin>>C[i];
		V.push_back(C[i]);
	}
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	FOR(i,N) C[i]=N+2-(lower_bound(ALL(V),C[i])-V.begin());
	FOR(i,N-1) {
		cin>>x>>y;
		x--,y--;
		P[y]=x;
		order[i]=y;
		hl.add_edge(x,y);
	}
	hl.decomp();
	
	Q[0].push_back({C[0],1});
	FOR(i,N-1) {
		x=order[i];
		mp.clear();
		ret=0;
		
		dfs(P[x],C[x]);
		
		if(Q[hl.B[x]].empty()) {
			Q[hl.B[x]].push_back({C[x],1});
		}
		else {
			Q[hl.B[x]].back().second++;
		}
		
		FORR(m,mp) bt.add(m.first,-m.second);
		cout<<ret<<endl;
		
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
