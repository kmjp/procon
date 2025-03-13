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

int T,N,M;
vector<int> R[202020];

template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
		FOR(i,NV) val[i+NV]=0,ma[i+NV]=1;
		for(i=NV-1;i>=1;i--) ma[i]=ma[2*i]+ma[2*i+1];
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(val[k]||r<=x || y<=l || y<=x) return 0;
		if(x<=l && r<=y) return ma[k];
		return getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1);
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			if(val[k]) ma[k]=0;
			else if(l+1==r) ma[k]=1;
			else ma[k]=ma[k*2]+ma[k*2+1];
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			if(val[k]) ma[k]=0;
			else ma[k]=ma[k*2]+ma[k*2+1];
		}
	}
};
SegTree_3<int,1<<20> st;
int X[202020],Y[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) R[i].clear();
		FOR(i,M) {
			cin>>X[i]>>Y[i];
			X[i]--,Y[i]--;
			R[X[i]].push_back(Y[i]);
			R[Y[i]].push_back(X[i]);
			st.update(X[i],Y[i],1);
		}
		int ret=st.getval(0,N);
		FOR(i,N) {
			FORR(a,R[i]) {
				if(a>i) {
					st.update(i,a,-1);
					st.update(0,i,1);
					st.update(a,N,1);
				}
				else {
					st.update(a,i,1);
					st.update(0,a,-1);
					st.update(i,N,-1);
				}
			}
			ret=max(ret,st.getval(0,N));
		}
		FOR(i,M) {
			st.update(X[i],Y[i],-1);
		}
		cout<<N-ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
