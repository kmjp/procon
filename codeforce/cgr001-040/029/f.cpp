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

int T;
int N,Q;
int A[101010],B[101010];

ll C2(int a) {
	return 1LL*a*(a-1)/2;
}

static ll const def=-1<<20;
template<class V,int NV> class SegTree_3 {
public:
	vector<int> add;
	vector<V> ma;
	SegTree_3(){
		add.resize(NV*2); ma.resize(NV*2);
	};
	
	V merge(V l,V r) {
		if(l[0]==0) return r;
		if(r[0]==0) return l;
		V m;
		m[0]=l[0]+r[0];
		if(l[0]==l[2]&&r[0]==r[2]) {
			m[1]=m[2]=m[0];
			m[3]=C2(m[0]);
		}
		else if(l[0]==l[2]) {
			m[1]=l[0]+r[1];
			m[2]=r[2];
			m[3]=l[3]+r[3]-C2(l[0])-C2(r[1])+C2(m[1]);
		}
		else if(r[0]==r[2]) {
			m[1]=l[1];
			m[2]=l[2]+r[0];
			m[3]=l[3]+r[3]-C2(l[2])-C2(r[0])+C2(m[2]);
		}
		else {
			m[1]=l[1];
			m[2]=r[2];
			m[3]=l[3]+r[3]-C2(l[2])-C2(r[1])+C2(l[2]+r[1]);
		}
		
		return m;
	}
	
	void update(int x,int y, int v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			add[k]+=v;
			if(r-l==1) {
				if(add[k]==0) ma[k]={1,1,0,0};
				else ma[k]={1,1,1,0};
			}
			else {
				if(add[k]==0) {
					ma[k]=merge(ma[k*2],ma[k*2+1]);
				}
				else {
					ma[k][0]=ma[k*2][0]+ma[k*2+1][0];
					ma[k][1]=ma[k][2]=ma[k][0];
					ma[k][3]=C2(ma[k][0]);
				}
			}
			
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=merge(ma[k*2],ma[k*2+1]);
			if(add[k]) {
				ma[k][0]=ma[k*2][0]+ma[k*2+1][0];
				ma[k][1]=ma[k][2]=ma[k][0];
				ma[k][3]=C2(ma[k][0]);
			}
		}
	}
	void reset(int x,int v) {
		int e=x+NV;
		if(v==0) {
			ma[e]={0,0,0,0};
		}
		else {
			ma[e]={1,1,0,0};
		}
		while(e>=1) {
			add[e]=0;
			e/=2;
			if(e) ma[e]=merge(ma[2*e],ma[2*e+1]);
		}
		
	}
};
SegTree_3<array<ll,4>,1<<20> st;
// len, left, right, num

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	FOR(k,T) {
		
		cin>>N>>Q;
		FOR(i,N) cin>>A[i];
		FOR(i,N) cin>>B[i];
		FOR(i,N) {
			st.reset(i,1);
		}
		FOR(i,N) {
			A[i]--,B[i]--;
			st.update(min(A[i],B[i]),max(A[i],B[i]),1);
		}
		
		
		while(Q--) {
			cin>>i>>x>>y;
			x--,y--;
			st.update(min(A[x],B[x]),max(A[x],B[x]),-1);
			st.update(min(A[y],B[y]),max(A[y],B[y]),-1);
			if(i==1) swap(A[x],A[y]);
			else swap(B[x],B[y]);
			st.update(min(A[x],B[x]),max(A[x],B[x]),1);
			st.update(min(A[y],B[y]),max(A[y],B[y]),1);
			ll ret=1LL*N*(N+1)/2+st.ma[1][3];
			cout<<ret<<endl;
		}
		FOR(i,N) {
			st.reset(i,0);
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
