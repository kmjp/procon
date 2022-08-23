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

template<int NV> class SegTree_3 {
public:
	vector<array<ll,12>> val;
	vector<int> mp[3];
	SegTree_3(){
		int i,x,y;
		val.resize(NV*2);
		FOR(i,NV*2) val[i][0]=1;
		mp[0].resize(NV*2,0);
		mp[1].resize(NV*2,1);
		mp[2].resize(NV*2,2);
		for(i=NV-1;i>=1;i--) {
			val[i][0]=val[i*2][0]+val[i*2+1][0];
		}
	};
	array<ll,12> merge(int m[3],array<ll,12> A,array<ll,12> B) {
		array<ll,12> W={0,0,0,0,0,0,0,0,0,0,0,0};
		int x,y;
		FOR(x,3) {
			W[m[x]]+=A[x]+B[x];
			FOR(y,3) {
				int tx=m[x];
				int ty=m[y];
				W[3+tx*3+ty]+=A[3+x*3+y]+B[3+x*3+y];
				W[3+tx*3+ty]+=A[x]*B[y];
			}
		}
		return W;
	}
	array<ll,12> getval(int x,int y,int l=0,int r=NV,int k=1) {
		array<ll,12> W={0,0,0,0,0,0,0,0,0,0,0,0};
		if(r<=x || y<=l || y<=x) return W;
		if(x<=l && r<=y) return val[k];
		int i;
		auto A=getval(x,y,l,(l+r)/2,k*2);
		auto B=getval(x,y,(l+r)/2,r,k*2+1);
		int m[3]={mp[0][k],mp[1][k],mp[2][k]};
		return merge(m,A,B);
	}
	void prop(int a,int b) {
		int m[3]={};
		array<ll,12> W={0,0,0,0,0,0,0,0,0,0,0,0};
		int i,x,y;
		FOR(i,3) {
			m[i]=mp[mp[i][b]][a];
		}
		FOR(x,3) {
			int tx=mp[x][a];
			W[tx]+=val[b][x];
			FOR(y,3) {
				W[3+mp[x][a]*3+mp[y][a]]+=val[b][3+x*3+y];
			}
		}
		FOR(i,3) mp[i][b]=m[i];
		val[b]=W;
	}
	void update(int x,int y, int M[3],int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		int i;
		if(x<=l && r<=y) {
			int m[3];
			array<ll,12> W={0,0,0,0,0,0,0,0,0,0,0,0};
			int i,x,y;
			FOR(i,3) {
				m[i]=M[mp[i][k]];
			}
			FOR(x,3) {
				W[M[x]]+=val[k][x];
				FOR(y,3) {
					W[3+M[x]*3+M[y]]+=val[k][3+x*3+y];
				}
			}
			FOR(i,3) {
				mp[i][k]=m[i];
			}
			val[k]=W;
		}
		else if(l < y && x < r) {
			prop(k,2*k);
			prop(k,2*k+1);
			mp[0][k]=0;
			mp[1][k]=1;
			mp[2][k]=2;
			update(x,y,M,l,(l+r)/2,k*2);
			update(x,y,M,(l+r)/2,r,k*2+1);
			int m[3]={0,1,2};
			val[k]=merge(m,val[2*k],val[2*k+1]);
			
		}
	}
};
SegTree_3<1<<18> st;
int N,Q;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>x;
		int m[3]={x,x,x};
		st.update(i,i+1,m);
	}
	while(Q--) {
		int L,R;
		cin>>i>>L>>R;
		L--;
		if(i==1) {
			auto V=st.getval(L,R);
			ll ret=V[3+1*3+0]+V[3+2*3+0]+V[3+2*3+1];
			cout<<ret<<endl;
			
		}
		else {
			int m[3];
			cin>>m[0]>>m[1]>>m[2];
			st.update(L,R,m);
			
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
