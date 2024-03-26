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
int A[202020];
vector<int> P[202020];

template<class V,int NV> class SegTree_Cover {
public:
	vector<V> val,cover;
	SegTree_Cover(){val.resize(NV*2); cover.resize(NV*2);};

	int getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) {
			if(cover[k]) return r-l;
			return val[k];
		}
		return getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1);
	}

	int update(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(x<=l && r<=y) {
			cover[k]+=v;
		}
		else if(max(x,l)<min(r,y)) {
			val[k]=update(x,y,v,l,(l+r)/2,k*2)+update(x,y,v,(l+r)/2,r,k*2+1);
		}
		if(cover[k]>0) return r-l;
		return val[k];
	}
};
SegTree_Cover<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		P[A[i]].push_back(i);
	}
	FOR(i,N) {
		P[i].push_back(N);
		P[i].push_back(N);
		st.update(P[i][0],P[i][1],1);
	}
	
	ll ret=0;
	FOR(i,N) {
		ret+=st.getval(0,N);
		x=A[i];
		y=lower_bound(ALL(P[x]),i)-P[x].begin();
		st.update(P[x][y],P[x][y+1],-1);
		st.update(P[x][y+1],P[x][y+2],1);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
