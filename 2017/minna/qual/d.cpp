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

int Q;
ll K;
int T[101010],D[101010],A[101010];
vector<ll> V;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> X,Y;
	
	SegTree_1(){
		X=vector<V>(NV*2);
		Y=vector<V>(NV*2);
	}
	pair<ll,ll> getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {0,0};
		if(x<=l && r<=y) return {X[k],Y[k]};
		auto A=getval(x,y,l,(l+r)/2,k*2);
		auto B=getval(x,y,(l+r)/2,r,k*2+1);
		return {A.first+B.first,max(B.first+A.second,B.second)};
	}
	void diff(int entry, V v) {
		entry += NV;
		X[entry]+=v;
		while(entry>1) {
			entry>>=1;
			X[entry]=X[entry*2]+X[entry*2+1];
			Y[entry]=max(X[entry*2+1]+Y[entry*2],Y[entry*2+1]);
		}
	}
};

SegTree_1<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q>>K;
	V.push_back(0);
	FOR(i,Q) {
		cin>>T[i];
		if(T[i]==1) {
			cin>>D[i]>>A[i];
		}
		else {
			cin>>D[i];
		}
		V.push_back(D[i]);
	}
	
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	for(i=1;i<V.size();i++) {
		st.X[i+(1<<20)] += 1LL*K*(V[i]-V[i-1]);
	}
	for(i=(1<<20)-1;i>=1;i--) {
		st.X[i] = st.X[2*i]+st.X[2*i+1];
		st.Y[i] = max(st.X[2*i+1]+st.Y[2*i],st.Y[2*i+1]);
	}
	
	FOR(i,Q) {
		x = lower_bound(ALL(V),D[i])-V.begin();
		if(T[i]==1) {
			st.diff(x,-A[i]);
		}
		else {
			ll tot=1LL*K*D[i];
			auto ret=st.getval(0,x+1);
			cout<<tot-ret.second<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
