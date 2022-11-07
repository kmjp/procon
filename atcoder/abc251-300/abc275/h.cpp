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
ll A[101010],B[101010];

template<class V,int NV> class SegTree_Pair {
public:
	vector<pair<V,int> > val;
	static V const def=0;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){ return max(l,r);}
	SegTree_Pair(){
		val.resize(NV*2);
		int i;
		FOR(i,NV) val[i+NV]=make_pair(def,i);
		for(i=NV-1;i>=1;i--) val[i]=comp(val[2*i],val[2*i+1]);
	};
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(def,NV);
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=make_pair(v,entry-NV);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_Pair<int,1<<20> st;

ll X[101010],Y[101010];
map<ll,ll> M[101010];

int dfs(int CL,int CR) {
	if(CL>CR) return -1;
	int cur=st.getval(CL,CR+1).second;
	int x=dfs(CL,cur-1);
	int y=dfs(cur+1,CR);
	
	if(x!=-1) Y[cur]+=Y[x], X[cur]+=X[x];
	if(y!=-1) Y[cur]+=Y[y], X[cur]+=X[y];
	if(x==-1&&y==-1) {
		;
	}
	else if(x==-1) {
		swap(M[cur],M[y]);
	}
	else if(y==-1) {
		swap(M[cur],M[x]);
	}
	else {
		if(M[x].size()<M[y].size()) swap(x,y);
		FORR2(a,b,M[y]) M[x][a]+=b;
		swap(M[cur],M[x]);
	}
	
	while(M[cur].size()) {
		auto it=M[cur].begin();
		if(it->first<=A[cur]||X[cur]-it->second>=B[cur]) {
			Y[cur]-=it->first*it->second;
			X[cur]-=it->second;
			M[cur].erase(it);
		}
		else {
			break;
		}
	}
	
	if(X[cur]>B[cur]) {
		auto it=M[cur].begin();
		Y[cur]-=it->first*(X[cur]-B[cur]);
		M[cur][it->first]-=(X[cur]-B[cur]);
		X[cur]=B[cur];
	}
	
	Y[cur]+=(B[cur]-X[cur])*A[cur];
	M[cur][A[cur]]+=B[cur]-X[cur];
	X[cur]=B[cur];
	/*
	cout<<cur<<" "<<x<<" "<<y<<" "<<X[cur]<<" "<<Y[cur]<<" ";
	FORR2(a,b,M[cur]) cout<<a<<":"<<b<<" ";
	cout<<endl;
	*/
	
	return cur;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
	}
	FOR(i,N) {
		cin>>B[i];
		st.update(i,B[i]);
	}
	
	int root=dfs(0,N-1);
	cout<<Y[root]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
