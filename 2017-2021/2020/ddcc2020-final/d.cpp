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


int N,LS;
int A[202020],B[202020],C[202020];
vector<vector<int>> E[202020];
set<int> ES[202020];
int in[202020];
int id[202020];
vector<int> V;
vector<ll> D;
ll L;
vector<ll> MD[202020],MP[202020];
ll PD[202020],PP[202020],BP[202020];
ll DD[202020];

struct node {
	ll L,R;
	ll ML,MR,MP;
	int Lid,Rid,Pid[2];
};

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		if(l.L==-1) return r;
		if(r.L==-1) return l;
		V node;
		node.L=l.L;
		node.R=r.R;
		node.MP=max({l.MP,r.MP,l.MR+r.ML+r.L-l.R});
		
		if(node.MP==l.MP) {
			node.Pid[0]=l.Pid[0];
			node.Pid[1]=l.Pid[1];
		}
		else if(node.MP==r.MP) {
			node.Pid[0]=r.Pid[0];
			node.Pid[1]=r.Pid[1];
		}
		else {
			node.Pid[0]=l.Rid;
			node.Pid[1]=r.Lid;
		}
		
		if(l.ML>r.ML+r.L-l.L) {
			node.ML=l.ML;
			node.Lid=l.Lid;
		}
		else {
			node.ML=r.ML+r.L-l.L;
			node.Lid=r.Lid;
		}
		if(l.MR+r.R-l.R>r.MR) {
			node.MR=l.MR+r.R-l.R;
			node.Rid=l.Rid;
		}
		else {
			node.MR=r.MR;
			node.Rid=r.Rid;
		}
		return node;
	};
	
	SegTree_1(){val=vector<V>(NV*2);FORR(v,val) v.L=-1;}
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {.L=-1};
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v; //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_1<node,1<<20> st;

void dfs(int cur,int pre,int oid,ll d) {
	if(cur==oid && d) {
		L=d;
		return;
	}
	id[cur]=V.size();
	V.push_back(cur);
	D.push_back(d);
	FORR(e,E[cur]) if(id[e[0]]==-2 || (e[0]==oid&&id[cur]>=2)) dfs(e[0],cur,oid,d+e[2]);
}

void dfs2(int cur,int pre,ll d) {
	MD[cur].push_back(0);
	MD[cur].push_back(0);
	DD[cur]=d;
	FORR(e,E[cur]) if(id[e[0]]==-1 && e[0]!=pre) {
		dfs2(e[0],cur,d+e[2]);
		MP[cur].push_back(BP[e[0]]);
		MD[cur].push_back(MD[e[0]][0]+e[2]);
	}
	sort(ALL(MD[cur]));
	reverse(ALL(MD[cur]));
	sort(ALL(MP[cur]));
	reverse(ALL(MP[cur]));
	BP[cur]=MD[cur][0]+MD[cur][1];
	if(MP[cur].size()) BP[cur]=max(BP[cur],MP[cur][0]);
	
}

void dfs3(int cur,int pre,ll md, ll mp) {
	PP[cur]=mp;
	PD[cur]=md;
	FORR(e,E[cur]) if(id[e[0]]==-1 && e[0]!=pre) {
		ll nmd=max(md,((MD[cur][0]==MD[e[0]][0]+e[2])?MD[cur][1]:MD[cur][0]))+e[2];
		ll nmp=0;
		if(MD[cur][0]==MD[e[0]][0]+e[2]){
			nmp=MD[cur][1]+MD[cur][2]+md-min({MD[cur][1],MD[cur][2],md});
		}
		else if(MD[cur][1]==MD[e[0]][0]+e[2]){
			nmp=MD[cur][0]+MD[cur][2]+md-min({MD[cur][0],MD[cur][2],md});
		}
		else {
			nmp=MD[cur][0]+MD[cur][1]+md-min({MD[cur][0],MD[cur][1],md});
		}
		nmp=max(nmp,mp);
		if(MP[cur][0]==BP[e[0]]) {
			if(MP[cur].size()>=2) nmp=max(nmp,MP[cur][1]);
		}
		else nmp=max(nmp,MP[cur][0]);
		
		dfs3(e[0],cur,nmd,nmp);
	}
	
}


void setsegtree(int i,bool init=true) {
	node n;
	n.L=n.R=D[i];
	n.Lid=n.Rid=n.Pid[0]=n.Pid[1]=i;
	if(init) {
		n.ML=n.MR=MD[V[i]][0];
		n.MP=BP[V[i]];
	}
	else {
		n.ML=n.MR=n.MP=-1LL<<60;
	}
	st.update(i,n);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i]>>C[i];
		A[i]--;
		B[i]--;
		E[A[i]].push_back({B[i],i,C[i]});
		E[B[i]].push_back({A[i],i,C[i]});
		ES[A[i]].insert(B[i]);
		ES[B[i]].insert(A[i]);
		in[A[i]]++;
		in[B[i]]++;
	}
	
	queue<int> Q;
	FOR(i,N) {
		id[i]=-2;
		if(in[i]==1) Q.push(i);
	}
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		id[x]=-1;
		FORR(e,ES[x]) {
			ES[e].erase(x);
			in[e]--;
			if(in[e]==1) Q.push(e);
		}
	}
	FOR(i,N) if(id[i]==-2) {
		dfs(i,i,i,0);
		break;
	}
	FOR(i,N) if(id[i]>=0) dfs2(i,i,0);
	LS=V.size();
	FOR(i,2*LS) V.push_back(V[i%LS]);
	FOR(i,LS) D.push_back(D[i]+L);
	FOR(i,LS) D.push_back(D[i]+2*L);
	FOR(i,3*LS) setsegtree(i);
	
	//半周ずつ回す
	vector<vector<ll>> ring;
	FOR(i,3) {
		int LL=0,RR=0;
		node NT;
		NT.MP=-1;
		FOR(LL,LS) {
			while(D[RR]-D[LL]<=L/2) RR++;
			node NL=st.getval(LL,RR);
			if(NL.MP>NT.MP) NT=NL;
		}
		for(LL=RR=2*LS-1;RR>=LS;RR--) {
			while(D[RR]-D[LL]<=L/2) LL--;
			node NL=st.getval(LL+1,RR+1);
			if(NL.MP>NT.MP) NT=NL;
		}
		
		ring.push_back({NT.MP,NT.Pid[0]%LS,NT.Pid[1]%LS});
		if(i==0) {
			x=NT.Pid[0]%LS;
			y=NT.Pid[1]%LS;
			ring.push_back({NT.MP,x,y});
			setsegtree(x,false);
			setsegtree(x+LS,false);
			setsegtree(x+LS*2,false);
		}
		else if(i==1) {
			setsegtree(x);
			setsegtree(x+LS);
			setsegtree(x+LS*2);
			setsegtree(y,false);
			setsegtree(y+LS,false);
			setsegtree(y+LS*2,false);
		}
		else {
			setsegtree(y);
			setsegtree(y+LS);
			setsegtree(y+LS*2);
		}
	}
	sort(ALL(ring));
	reverse(ALL(ring));
	
	FOR(i,LS) {
		x=lower_bound(ALL(D),D[i+LS]+(L+1)/2)-D.begin();
		node NL=st.getval(x-LS,i+LS);
		node NR=st.getval(i+LS+1,x);
		ll md=0,mp=0;
		if(NL.L>=0) {
			md=max(md,(D[i+LS]-NL.R)+NL.MR);
			mp=max({mp,NL.MP});
		}
		if(NR.L>=0) {
			md=max(md,NR.L-D[i+LS]+NR.ML);
			mp=max(mp,NR.MP);
		}
		//関係ないところのmd
		FORR(r,ring) {
			if(r[1]!=i&&r[2]!=i) {
				mp=max(mp,r[0]);
				break;
			}
		}
		dfs3(V[i],V[i],md,mp);
	}
	
	FOR(i,N) {
		if(id[A[i]]>=0 && id[B[i]]>=0) {
			x=id[A[i]];
			y=id[B[i]];
			if(x>y) swap(x,y);
			if(x+1<y) x--;
			auto n=st.getval(x+1,x+LS+1);
			cout<<n.MP<<endl;
		}
		else {
			x=A[i];
			y=B[i];
			if(DD[x]>DD[y]) swap(x,y);
			
			ll mp=PP[x];
			if(MP[y].size()) mp=max(mp,MP[y][0]);
			mp=max(mp,MD[y][0]+MD[y][1]);
			mp=max(mp,MP[x][0]);
			vector<ll> T;
			FOR(j,min(3,(int)MD[x].size())) T.push_back(MD[x][j]);
			T.push_back(PD[x]);
			T.push_back(0);
			T.push_back(0);
			sort(ALL(T));
			reverse(ALL(T));
			if(T[0]==MD[y][0]+C[i]) {
				mp=max(mp,T[1]+T[2]);
			}
			else if(T[1]==MD[y][0]+C[i]) {
				mp=max(mp,T[0]+T[2]);
			}
			else {
				mp=max(mp,T[0]+T[1]);
			}
			cout<<mp<<endl;
			
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
