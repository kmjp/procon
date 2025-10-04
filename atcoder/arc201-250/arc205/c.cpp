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
int S[202020],T[202020];
int B[202020];
int id[404040];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> num;

static ll const def=1<<20;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+min(ma[k*2],ma[k*2+1]);
		}
	}
};
SegTree_3<int,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	vector<int> Xs;
	FOR(i,N) {
		cin>>S[i]>>T[i];
		Xs.push_back(S[i]);
		Xs.push_back(T[i]);
	}
	sort(ALL(Xs));
	FOR(i,N) {
		S[i]=lower_bound(ALL(Xs),S[i])-Xs.begin();
		T[i]=lower_bound(ALL(Xs),T[i])-Xs.begin();
		num.add(S[i],1);
	}
	MINUS(id);
	FOR(i,N) {
		if(S[i]<T[i]) {
			B[i]=num(T[i])-num(S[i]);
		}
		else {
			B[i]=num(S[i]-1)-num(T[i]);
		}
		id[T[i]]=i;
	}
	FOR(i,2*N) {
		if(id[i]==-1) {
			st.update(i,i+1,1<<20);
		}
		else {
			st.update(i,i+1,B[id[i]]);
		}
	}
	
	vector<int> ret;
	while(st.getval(0,2*N)==0) {
		int tar=2*N;
		for(i=19;i>=0;i--) if(tar-(1<<i)>=0&&st.getval(0,tar-(1<<i))==0) tar-=1<<i;
		int cur=id[tar-1];
		ret.push_back(cur);
		st.update(T[cur],T[cur]+1,1<<20);
		if(S[cur]<T[cur]) {
			st.update(S[cur],T[cur],-1);
		}
		else {
			st.update(T[cur]+1,S[cur],-1);
		}
	}
	
	if(ret.size()!=N) {
		cout<<"No"<<endl;
	}
	else {
		cout<<"Yes"<<endl;
		FORR(r,ret) cout<<r+1<<" ";
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
