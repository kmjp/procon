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
const ll DI=450;
ll A[402020],B[402020];
const ll mo=998244353;

template<class V,int NV> class SegTree_3 {
public:
	vector<V> A,B,addA,addB,S;
	SegTree_3(){
		int i;
		A.resize(NV*2,0);
		B.resize(NV*2,0);
		addA.resize(NV*2,0);
		addB.resize(NV*2,0);
		S.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return 0;
		if(x<=l && r<=y) return S[k];
		
		if(addA[k]||addB[k]) {
			update(0,NV,addA[k],addB[k],l,(l+r)/2,k*2);
			update(0,NV,addA[k],addB[k],(l+r)/2,r,k*2+1);
		}
		addA[k]=addB[k]=0;
		A[k]=(A[2*k]+A[2*k+1])%mo;
		B[k]=(B[2*k]+B[2*k+1])%mo;
		S[k]=(S[2*k]+S[2*k+1])%mo;
		
		return (getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1))%mo;
	}
	
	void update(int x,int y, int va,int vb,int l=0,int r=NV,int k=1) {
		if(va==0&&vb==0) return;
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			if(va) {
				(addA[k]+=va)%=mo;
				(A[k]+=1LL*(r-l)*va)%=mo;
				(S[k]+=1LL*va*B[k])%=mo;
			}
			if(vb) {
				(addB[k]+=vb)%=mo;
				(B[k]+=1LL*(r-l)*vb)%=mo;
				(S[k]+=1LL*vb*A[k])%=mo;
			}
		}
		else if(l < y && x < r) {
			update(0,NV,addA[k],addB[k],l,(l+r)/2,k*2);
			update(0,NV,addA[k],addB[k],(l+r)/2,r,k*2+1);
			update(x,y,va,vb,l,(l+r)/2,k*2);
			update(x,y,va,vb,(l+r)/2,r,k*2+1);
			addA[k]=addB[k]=0;
			A[k]=(A[2*k]+A[2*k+1])%mo;
			B[k]=(B[2*k]+B[2*k+1])%mo;
			S[k]=(S[2*k]+S[2*k+1])%mo;
		}
	}
};
SegTree_3<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
		st.update(i,i+1,A[i],0);
	}
	FOR(i,N) {
		cin>>B[i];
		st.update(i,i+1,0,B[i]);
	}
	
	while(Q--) {
		int T,L,R;
		cin>>T>>L>>R;
		L--;
		if(T==1||T==2) {
			cin>>x;
			if(T==1) st.update(L,R,x,0);
			else st.update(L,R,0,x);
		}
		else {
			ll ret=st.getval(L,R);
			cout<<ret<<endl;
		}
		
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
