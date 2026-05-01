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
vector<int> E[202020];
set<int> SE[202020];
int alive[202020];

ll ret[1202020];

void dfs(int cur,int pre,int d,vector<__int128>& V) {
	if(V.size()<d+1) V.resize(d+1);
	V[d]++;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d+1,V);
}

const ll mo=6597069766657LL;
const int gg=5;
__int128 modpow(__int128 a, __int128 n = mo-2) {
	__int128 r=1; a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

template <class T> using vec=vector<T>; //using vec=valarray<T>;

template<class T> vec<T> fft(vec<T> v, bool rev=false) {
	int n=v.size(),i,j,m;
	for(int m=n; m>=2; m/=2) {
		T wn=modpow(gg,(mo-1)/m);
		if(rev) wn=modpow(wn);
		for(i=0;i<n;i+=m) {
			T w=1;
			for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				T t1=v[j1],t2=v[j2];
				v[j1]=(t1+t2+mo)%mo;
				v[j2]=(T)(t1+mo-t2)*w%mo;
				while(v[j1]>=mo) v[j1]-=mo;
				w=w*wn%mo;
			}
		}
	}
	for(i=0,j=1;j<n-1;j++) {
		for(int k=n>>1;k>(i^=k);k>>=1);
		if(i>j) swap(v[i],v[j]);
	}
	if(rev) {
		T rv = modpow(n);
		FOR(i,n) v[i]=v[i]*rv%mo;
	}
	return v;
}

template<class T> vec<T> MultPoly(vec<T> P,vec<T> Q,bool resize=false,bool recover=false) {
	int len=0;
	if(resize) {
		int maxind=0,pi=-1,qi=-1,i;
		int s=2;
		len=P.size()+Q.size()-1;
		FOR(i,P.size()) if(P[i]) pi=i;
		FOR(i,Q.size()) if(Q[i]) qi=i;
		if(pi==-1||qi==-1) return {};
		maxind=pi+qi+1;
		while(s*2<maxind) s*=2;
		
		if(s<=64) { //fastpath
			vec<T> R(s*2);
			for(int x=0;x<=pi;x++) for(int y=0;y<=qi;y++) (R[x+y]+=P[x]*Q[y])%=mo;
			if(recover) R.resize(len);
			return R;
		}
		vec<T> P2(s*2),Q2(s*2);
		FOR(i,pi+1) P2[i]=P[i];
		FOR(i,qi+1) Q2[i]=Q[i];
		swap(P,P2),swap(Q,Q2);
	}
	P=fft(P), Q=fft(Q);
	for(int i=0;i<P.size();i++) P[i]=(T)P[i]*Q[i]%mo;
	P=fft(P,true);
	if(resize&&recover) P.resize(len);
	return P;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
		SE[x-1].insert(y-1);
		SE[y-1].insert(x-1);
	}
	
	set<int> NG;
	queue<int> Q;
	FOR(i,N) {
		if(E[i].size()>=3) NG.insert(i);
		if(E[i].size()==1) Q.push(i);
		alive[i]=1;
	}
	
	int step=0;
	while(NG.size()) {
		step++;
		queue<int> NQ;
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			alive[cur]=0;
			FORR(e,SE[cur]) {
				SE[e].erase(cur);
				if(SE[e].size()==2) NG.erase(e);
				if(SE[e].size()==1) NQ.push(e);
			}
		}
		swap(NQ,Q);
	}
	
	vector<int> C;
	int al=0;
	FOR(i,N) {
		al+=alive[i];
		if(alive[i]&&SE[i].size()<=1) C.push_back(i);
	}
	if(C.size()==1) {
		vector<__int128> A,B;
		ret[al]++;
		FORR(e,E[C[0]]) {
			B.clear();
			dfs(e,C[0],1,B);
			if(A.size()<B.size()) A.resize(B.size());
			FOR(i,B.size()) {
				ret[al+i]+=B[i];
				A[i]+=B[i];
			}
			
		}
		A=MultPoly(A,A,1);
		FORR(e,E[C[0]]) {
			B.clear();
			dfs(e,C[0],1,B);
			B=MultPoly(B,B,1);
			FOR(i,min(A.size(),B.size())) A[i]-=B[i];
		}
		FOR(i,A.size()) ret[al+i]+=A[i]/2;
	}
	else {
		int u=C[0];
		int ue=*SE[u].begin();
		int v=C[1];
		int ve=*SE[v].begin();
		vector<__int128> U,V;
		dfs(u,ue,0,U);
		dfs(v,ve,0,V);
		auto W=MultPoly(U,V,1);
		FOR(i,W.size()) ret[al+i]+=W[i];
	}
	for(i=1;i<=N;i++) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
