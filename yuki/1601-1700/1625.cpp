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
int L[202020],R[202020];
ll A[202020];
int T[202020];
ll ret[202020];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=-1;
	V comp(V l,V r){ return max(l,r);};
	
	void init(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<ll,1<<20> st;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<int> Xs;
	cin>>N>>Q;
	FOR(i,N) {
		ll X[3],Y[3];
		cin>>X[0]>>Y[0]>>X[1]>>Y[1]>>X[2]>>Y[2];
		L[i]=min({X[0],X[1],X[2]});
		R[i]=max({X[0],X[1],X[2]});
		X[1]-=X[0];
		X[2]-=X[0];
		Y[1]-=Y[0];
		Y[2]-=Y[0];
		A[i]=abs(X[1]*Y[2]-X[2]*Y[1]);
		Xs.push_back(L[i]);
		Xs.push_back(R[i]);
	}
	FOR(i,100000) {
		if(i<Q) {
			cin>>T[i+N];
			if(T[i+N]==1) {
				ll X[3],Y[3];
				cin>>X[0]>>Y[0]>>X[1]>>Y[1]>>X[2]>>Y[2];
				L[i+N]=min({X[0],X[1],X[2]});
				R[i+N]=max({X[0],X[1],X[2]});
				X[1]-=X[0];
				X[2]-=X[0];
				Y[1]-=Y[0];
				Y[2]-=Y[0];
				A[i+N]=abs(X[1]*Y[2]-X[2]*Y[1]);
			}
			else {
				cin>>L[i+N]>>R[i+N];
				ret[i+N]=-1;
			}
		}
		else {
			T[i+N]=0;
		}
		Xs.push_back(L[i+N]);
		Xs.push_back(R[i+N]);
	}
	Xs.push_back(0);
	Xs.push_back(1<<30);
	sort(ALL(Xs));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	FOR(i,N+Q) {
		L[i]=lower_bound(ALL(Xs),L[i])-Xs.begin();
		R[i]=lower_bound(ALL(Xs),R[i])-Xs.begin();
	}
	int pre;
	const int DI=1000;
	for(i=0;i<100000;i+=DI) {
		vector<pair<int,int>> ev;
		st.init();
		FOR(j,N+i) {
			if(j<N||T[j]==1) {
				ev.push_back({R[j],j});
			}
		}
		for(j=N+i;j<N+i+DI;j++) {
			if(T[j]==2) {
				ev.push_back({R[j],j});
				for(x=N+i;x<j;x++) if(T[x]==1 && L[j]<=L[x]&&R[x]<=R[j]) ret[j]=max(ret[j],A[x]);
			}
		}
		sort(ALL(ev));
		FORR2(r,i,ev) {
			if(i<N||T[i]==1) {
				st.update(L[i],A[i]);
			}
			else {
				ret[i]=max(ret[i],st.getval(L[i],R[i]));
			}
		}
		for(j=N+i;j<N+i+DI;j++) {
			if(T[j]==2) cout<<ret[j]<<endl;
		}
		continue;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
