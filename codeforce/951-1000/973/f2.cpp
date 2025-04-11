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

template<class V,int NV> class RMQ {
private:
	V table[NV+1][1<<NV];
	int LG[1<<NV];
	int NV2;
public:
	static V const def=-(1<<30);
	V comp(V l,V r){ return max(l,r);};
	RMQ() {
		int i,x;
		NV2=1<<NV;
		LG[1]=0;
		for(i=2;i<NV2;i++) LG[i]=LG[i/2]+1;
		FOR(i,NV) FOR(x,NV2) table[i][x]=def;
	}
	void set(int x,V v){ table[0][x]=v;}
	void build(int MV=-1) { //MVはサイズ指定
		if(MV==-1) MV=NV2;
		int i,j,x,y;
		FOR(i,NV) FOR(x,MV) table[i+1][x]=comp(table[i][x],(x+(1<<i)<MV)?table[i][x+(1<<i)]:def);
	}
	V query(int L,int R) { //[L,R),
		L=max(0,L), R=min(R,NV2);
		if(R<=L) return def;
		int WL=LG[R-L];
		return comp(table[WL][L],table[WL][R-(1<<WL)]);
	}
	
};
RMQ<int,20> rmq_a,rmq_b;

int T,N,U,V;
vector<int> E[202020];
int inP[202020];

int D[202020],L[202020],R[202020],P[202020],id,A[202020],B[202020];
int ret[202020];
int FA[202020],FB[202020];
vector<int> add[202020],del[202020];

void dfs(int cur,int pre) {
	P[cur]=pre;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
}

int dfs2(int cur,int pre) {
	D[cur]=0;
	FORR(e,E[cur]) if(e!=pre) {
		int r=dfs2(e,cur);
		if(inP[e]==0) D[cur]=max(D[cur],r+1);
	}
	return D[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	srand(time(NULL));
	int v=0;
	cin>>T;
	FOR(l,T) {
		cin>>N;
		FOR(i,N) {
			E[i].clear();
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		id=0;
		dfs(0,0);
		
		cin>>U>>V;
		U--,V--;
		vector<int> cand={U,V};
		FORR(c,cand) {
			vector<int> G={c};
			while(G.back()) G.push_back(P[G.back()]);
			reverse(ALL(G));
			
			FOR(i,N) inP[i]=0;
			FORR(v,G) inP[v]=1;
			dfs2(0,0);
			int NV=G.size();
			FOR(i,NV) {
				A[i]=D[G[i]]+i;
				B[i]=D[G[i]]-i;
				rmq_a.set(i,A[i]);
				rmq_b.set(i,B[i]);
			}
			FOR(i,NV+2) {
				FA[i]=10101010;
				FB[i]=-10101010;
				add[i].clear();
				del[i].clear();
			}
			rmq_a.build(NV);
			rmq_b.build(NV);
			multiset<int> S={10101010};
			for(i=1;i<NV;i++) {
				int cur=i;
				int L=i+1,R=NV-1;
				while(L<=R) {
					int M=(L+R)/2;
					if(rmq_b.query(i+1,M+1)+M<A[i]-i) {
						cur=M;
						L=M+1;
					}
					else {
						R=M-1;
					}
				}
				if(cur>i) {
					add[min(NV,2*i)].push_back(i);
					del[min(NV,cur+i)].push_back(i);
				}
				FORR(a,add[i]) S.insert(a);
				FA[i]=*S.begin();
				FORR(a,del[i]) S.erase(S.find(a));
			}
			S={-10101010};
			FOR(i,NV+2) {
				add[i].clear();
				del[i].clear();
			}
			for(i=1;i<NV;i++) {
				int cur=i;
				int L=1,R=i-1;
				while(L<=R) {
					int M=(L+R)/2;
					if(rmq_a.query(M,i)-(M-1)<=B[i]+i) {
						cur=M;
						R=M-1;
					}
					else {
						L=M+1;
					}
				}
				cur--;
				if(cur>=0) {
					add[min(NV,cur+i)].push_back(i);
					del[min(NV,2*i-1)].push_back(i);
				}
				FORR(a,add[i]) S.insert(a);
				FB[i]=*S.rbegin();
				FORR(a,del[i]) S.erase(S.find(a));
			}
			
			for(i=NV-1;i>=0;i--) {
				B[i]=max((i==NV-1)?0:B[i+1]+1,D[G[i]]);
				if(B[i]>=rmq_a.query(1,i)) FB[i]=i;
				if(A[0]>max(rmq_b.query(1,i)+i,B[i])) FA[i]=0;
				ret[G[i]]=(FA[i]<=i-FB[i]);
			}
		}
		
		vector<int> Us={U},Vs={V};
		while(Us.back()) Us.push_back(P[Us.back()]);
		while(Vs.back()) Vs.push_back(P[Vs.back()]);
		while(Us.size()>=2&&Vs.size()>=2&&Us[Us.size()-2]==Vs[Vs.size()-2]) Us.pop_back(),Vs.pop_back();
		Vs.pop_back();
		reverse(ALL(Vs));
		FORR(a,Vs) Us.push_back(a);
		
		FORR(a,Us) {
			if(ret[a]==1) cout<<"Alice"<<endl;
			else cout<<"Bob"<<endl;
		}
	}
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
