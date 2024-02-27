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

int N,A;
int X[101010];


template<class V,int NV> class SegTree_2 {
public:
	vector<V> val;
	SegTree_2(){val.resize(NV*2,0);};
	
	V getval(int entry) {
		entry += NV;
		V ret=val[entry];
		while(entry>1) entry>>=1, ret=max(ret,val[entry]);
		return ret;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) val[k]=max(val[k],v);
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
		}
	}
};
SegTree_2<int,1<<20> st;
int T,L[202020],R[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A;
	vector<int> Xs={0,A};
	FOR(i,N) {
		cin>>X[i];
		Xs.push_back(X[i]);
	}
	cin>>T;
	FOR(i,T) {
		cin>>L[i]>>R[i];
		Xs.push_back(L[i]);
		Xs.push_back(R[i]);
	}
	sort(ALL(Xs));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	FOR(i,T) {
		x=lower_bound(ALL(Xs),L[i])-Xs.begin();
		y=lower_bound(ALL(Xs),R[i])-Xs.begin();
		st.update(x,y+1,i+1);
	}
	FOR(i,N) {
		x=lower_bound(ALL(Xs),X[i])-Xs.begin();
		y=st.getval(x);
		if(y==0) y=-1;
		cout<<y<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
