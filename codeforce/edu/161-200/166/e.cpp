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

int N,Q;
int L[303030],R[303030];
int pos[303030];

int lef[303030];
int ri[303030];
ll ret;
const ll mo=998244353;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	set<int> S={N+1};
	lef[0]=1;
	ri[0]=N+1;
	lef[1]=N+1;
	ri[1]=0;
	lef[N+1]=0;
	ri[N+1]=1;
	
	FOR(i,Q) {
		cin>>L[i];
		L[i]++;
	}
	FOR(i,Q) {
		cin>>R[i];
		R[i]++;
	}
	FOR(i,Q) {
		if(L[i]>R[i]) {
			if(S.count(L[i])==0||S.count(R[i])) {
				cout<<0<<endl;
				return;
			}
			x=L[i];
			y=ri[x];
			ri[x]=lef[y]=R[i];
			lef[R[i]]=x;
			ri[R[i]]=y;
			S.insert(R[i]);
		}
		else if(L[i]<R[i]) {
			if(S.count(L[i])||S.count(R[i])==0) {
				cout<<0<<endl;
				return;
			}
			x=R[i];
			y=lef[x];
			lef[x]=ri[y]=L[i];
			ri[L[i]]=x;
			lef[L[i]]=y;
			S.insert(L[i]);
		}
		else {
			cout<<0<<endl;
			return;
		}
	}
	
	vector<int> V={0};
	while(V.back()!=1) {
		V.push_back(ri[V.back()]);
	}
	FOR(i,V.size()) {
		pos[V[i]]=i;
		st.update(i,V[i]);
	}
	FOR(i,Q) {
		x=pos[L[i]];
		y=pos[R[i]];
		if(st.getval(x+1,y)>max(L[i],R[i])) {
			cout<<0<<endl;
			return;
		}
	}
	
	ll ret=1;
	int cand=0;
	for(i=N+1;i>=2;i--) {
		if(S.count(i)) {
			if(lef[i]<i) cand++;
			if(ri[i]<i) cand++;
		}
		else {
			ret=ret*cand%mo;
			cand++;
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
