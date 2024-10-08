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


template<class V,int NV> class SegTree_Pair {
public:
	vector<pair<V,int> > val;
	static V const def=0;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){
		if(l.first>r.first) return l;
		if(l.first<r.first) return r;
		return {l.first,min(l.second,r.second)};
	}
	SegTree_Pair(){
		val.resize(NV*2);
		int i;
		FOR(i,NV) val[i+NV]=make_pair(-1,i);
		for(i=NV-1;i>=1;i--) val[i]=comp(val[2*i],val[2*i+1]);
	};
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(-1,NV);
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

int H,W,N;
int R[202020],C[202020],pre[202020];
vector<vector<int>> V;
int from[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	FOR(i,N) {
		cin>>R[i]>>C[i];
		R[i]--,C[i]--;
		V.push_back({R[i],C[i],i});
	}
	R[N]=C[N]=0;
	R[N+1]=H-1,C[N+1]=W-1;
	V.push_back({R[N],C[N],N});
	V.push_back({R[N+1],C[N+1],N+1});
	sort(ALL(V));
	MINUS(from);
	FORR(v,V) {
		i=v[2];
		y=C[i];
		auto p=st.getval(0,y+1);
		k=p.second;
		pre[i]=from[k];
		from[y]=i;
		st.update(y,p.first+1);
	}
	
	int cur=N+1;
	int v=st.getval(W-1,W).first;
	cout<<v-1<<endl;
	string S;
	while(cur!=N) {
		int nex=pre[cur];
		FOR(i,C[cur]-C[nex]) S+="R";
		FOR(i,R[cur]-R[nex]) S+="D";
		cur=nex;
	}
	reverse(ALL(S));
	cout<<S<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
