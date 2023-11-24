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

int N;
int V[202020];
vector<int> E[202020];
int P[202020]; //親
int S[202020]; //subtreeサイズ
int G[202020]; //グループ

//グループ毎の属性
int L[202020],R[202020]; //葉と根




const int DI=500;

int C[202020];
int CC[202020/DI][202020];
int BMA[202020/DI];

int ret[202020];
int id;
int VL[202020],VR[202020],rev[202020];


int Q;
int QU[202020],QV[202020],QB[202020];
int QUL[202020],QUR[202020],QVL[202020],QVR[202020];



void add(int v) { //頂点vを追加
	v=V[rev[v]];
	CC[v/DI][C[v]]--;
	C[v]++;
	CC[v/DI][C[v]]++;
	chmax(BMA[v/DI],C[v]);
}

void del(int v) { //頂点vを削除
	v=V[rev[v]];
	if(C[v]==BMA[v/DI]&&CC[v/DI][C[v]]==1) BMA[v/DI]--;
	CC[v/DI][C[v]]--;
	C[v]--;
	CC[v/DI][C[v]]++;
}

int getret() {
	int ma=0;
	int i,j;
	FOR(i,202020/DI) ma=max(ma,BMA[i]);
	FOR(i,202020/DI) if(BMA[i]==ma) {
		for(j=i*DI;j<(i+1)*DI;j++) if(C[j]==ma) return j;
	}
	return 0;
}


int dfs1(int cur,int pre) {
	P[cur]=pre;
	S[cur]=1;
	int i,ma=-1,id=-1;
	FOR(i,E[cur].size()) if(E[cur][i]!=pre) {
		S[cur]+=dfs1(E[cur][i],cur);
		if(S[E[cur][i]]>ma) {
			ma=S[E[cur][i]];
			id=i;
		}
	}
	if(id!=-1) {
		//heavy edgeを先頭に
		swap(E[cur][0],E[cur][id]);
	}
	return S[cur];
}

void dfs2(int cur,int pre) {
	rev[id]=cur;
	VL[cur]=id++;
	FORR(e,E[cur]) if(e!=pre) dfs2(e,cur);
	VR[cur]=id;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>V[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs1(0,0);
	
	MINUS(G);
	vector<pair<int,int>> cand;
	FOR(i,N) cand.push_back({S[i],i});
	sort(ALL(cand));
	
	int cg=0;
	FORR2(si,i,cand) {
		if(si<DI||G[i]!=-1) {
			continue;
		}
		L[cg]=i;
		int v=i;
		while(G[v]==-1&&S[v]-S[i]<2000) {
			G[v]=cg;
			v=P[v];
		}
		cg++;
	}
	
	dfs2(0,0);
	FOR(i,N) if(S[i]<DI) G[i]=cg+VL[i]/2000;
	
	cin>>Q;
	vector<pair<ll,ll>> Qs;
	FOR(i,Q) {
		cin>>QU[i]>>QV[i];
		QU[i]--,QV[i]--;
		if(VL[QU[i]]>VL[QV[i]]) swap(QU[i],QV[i]);
		
		QUL[i]=VL[QU[i]];
		QUR[i]=VR[QU[i]];
		QVL[i]=VL[QV[i]];
		QVR[i]=VR[QV[i]];
		QB[i]=G[QU[i]];
		Qs.push_back({QB[i],1LL*QVL[i]*1000000+i});
	}
	sort(ALL(Qs));
	int UL=0,UR=0,VL=0,VR=0;
	FORR2(b,v,Qs) {
		i=v%1000000;
		if(b<cg) {
			//heavy edge
			while(UR<QUR[i]) add(UR++);
			while(UL>QUL[i]) add(--UL);
			while(UR>QUR[i]) del(--UR);
			while(UL<QUL[i]) del(UL++);
		}
		else {
			while(UL<UR) del(UL++);
			UL=UR=QUL[i];
			while(UR<QUR[i]) add(UR++);
		}
		while(VR<QVR[i]) add(VR++);
		while(VL>QVL[i]) add(--VL);
		while(VR>QVR[i]) del(--VR);
		while(VL<QVL[i]) del(VL++);
		ret[i]=getret();
	}
	FOR(i,Q) cout<<ret[i]<<endl;
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
