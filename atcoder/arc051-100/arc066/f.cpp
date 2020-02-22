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

template<typename V> struct ConvexHull {
	deque<pair<V,V>> Q;
	int cmptype=1; // 0-min 1-max
	V calc(pair<V,V> p, V x) {
		return p.first*x+p.second;
	}
	int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) { // max or min
		return cmptype^((B.second-C.second)*(B.first-A.first)<=(A.second-B.second)*(C.first-B.first));
	}
	void add(V a, V b) { // add ax+b
		Q.push_front({a,b});
		while(Q.size()>=3 && !dodo(Q[0],Q[1],Q[2]))
			Q[1]=Q[0], Q.pop_front();
	}
	V query(V x) {
		int L=-1,R=Q.size()-1;
		while(R-L>1) {
			int M=(L+R)/2;
			((cmptype^((calc(Q[M],x)>=calc(Q[M+1],x))))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};


int N;
ll T[303030],LS[303030],RS[303030];
int M;
ConvexHull<ll> LC, RC;
ll LD[303030],RD[303030],inc[303030],ninc[303030];
ll tmemo[303030];

void dfs(int LL,int RR) {
	if(RR-LL<=2) return;
	int MM=(LL+RR)/2;
	
	ConvexHull<ll> TLC, TRC;
	TLC.add(0,0);
	TRC.add(0,0);
	int i,j;
	for(i=LL;i<RR;i++) {
		if(i<MM) TLC.add(-(i+1), 1LL*i*(i+1)/2 + LD[i+1] + LS[i+1]);
		else tmemo[i]=TLC.query(i+1) + 1LL*(i+1)*(i+2)/2 - LS[i+1]+RD[N-1-i];
	}
	for(j=RR-1;j>=LL;j--) {
		i=N-1-j;
		if(j>=MM) TRC.add(-(i+1), 1LL*i*(i+1)/2 + RD[i+1] + RS[i+1]);
		else tmemo[j]=TRC.query(i+1) + 1LL*(i+1)*(i+2)/2 - RS[i+1]+LD[j];
	}
	
	ll ma=-1LL<<60;
	for(i=RR-1;i>=MM;i--){
		ma=max(ma,tmemo[i]);
		inc[i]=max(inc[i],ma);
	}
	ma=-1LL<<60;
	for(i=LL;i<MM;i++){
		ma=max(ma,tmemo[i]);
		inc[i]=max(inc[i],ma);
	}
	
	dfs(LL,MM);
	dfs(MM,RR);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>T[i];
	
	LC.add(0,0);
	RC.add(0,0);
	FOR(i,N) {
		LS[i+1]=LS[i]+T[i];
		LD[i+1]=max(LD[i], LC.query(i+1) + 1LL*(i+1)*(i+2)/2 - LS[i+1]);
		LC.add(-(i+1), 1LL*i*(i+1)/2 + LD[i+1] + LS[i+1]);
		
		RS[i+1]=RS[i]+T[N-1-i];
		RD[i+1]=max(RD[i], RC.query(i+1) + 1LL*(i+1)*(i+2)/2 - RS[i+1]);
		RC.add(-(i+1), 1LL*i*(i+1)/2 + RD[i+1] + RS[i+1]);
	}
	FOR(i,N) {
		ninc[i]=LD[i]+RD[N-1-i];
		inc[i]=1-T[i];
	}
	dfs(0,N);
	
	
	cin>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--;
		cout<<max(ninc[x], inc[x] + T[x] - y)<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
