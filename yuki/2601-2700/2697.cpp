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


template<class V,int NV> class SegTree_3 {
public:
	vector<V> ma;
	vector<int> S;
	V comp(V l,V r){ 
		V z;
		int a,b,c,d;
		FOR(a,4) FOR(b,4) z[a][b]=0;
		for(a=0;a<=3;a++) for(b=a;b<=3;b++) for(c=b;c<=3;c++) for(d=c;d<=3;d++) {
			z[a][d]=max(z[a][d],l[a][b]+r[c][d]);
		}
		return z;
	};
	SegTree_3(){
		V z;
		int i,j;
		FOR(i,4) FOR(j,4) z[i][j]=0;
		ma.resize(NV*2,z);
		S.resize(NV*2,-1);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		V z;
		int a,b;
		FOR(a,4) FOR(b,4) z[a][b]=0;
		if(r<=x || y<=l || y<=x) {
			return z;
		}
		if(S[k]>=0) {
			x=max(x,l);
			y=min(y,r);
			z[S[k]][S[k]]=y-x;
			return z;
		}
		if(x<=l && r<=y) return ma[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	V update(int x,int y, int v,int l=0,int r=NV,int k=1) {
		V z;
		int i,j;
		FOR(i,4) FOR(j,4) z[i][j]=0;
		if(y<=l||x>=r) {
			return getval(l,r,l,r,k);
		}
		if(x<=l && r<=y) {
			x=max(x,l);
			y=min(y,r);
			S[k]=v;
			z[v][v]=y-x;
		}
		else if(l < y && x < r) {
			if(S[k]>=0) {
				S[2*k]=S[2*k+1]=S[k];
				S[k]=-1;
			}
			
			
			z=ma[k]=comp(update(x,y,v,l,(l+r)/2,k*2),update(x,y,v,(l+r)/2,r,k*2+1));
		}
		return z;
	}
};

SegTree_3<array<array<int,4>,4>,1<<18> st;

int N,Q;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		auto v=st.update(i+1,i+2,x-1);
	}
	cin>>Q;
	while(Q--) {
		int L,R;
		cin>>i>>L>>R;
		if(i==1) {
			auto v=st.getval(L,R+1);
			cout<<v[0][3]<<endl;
		}
		else {
			cin>>x;
			st.update(L,R+1,x-1);
		}
	}
			
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
