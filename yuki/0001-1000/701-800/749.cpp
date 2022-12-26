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

ll mo=1000000007;
ll F[1<<21],FS[1<<21];

template<class V,int NV> class SegTree_MulAdd {
public:
	vector<V> S,MF,M,A; // sum stores val after muladd
	SegTree_MulAdd(){
		S.resize(NV*2,0);
		MF.resize(NV*2,0);
		M.resize(NV*2,0);
		A.resize(NV*2,0);
	};

	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return S[k];
		x=max(x,l);
		y=min(y,r);
		V ret=getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1);
		return (ret*M[k]+A[k]*(y-x)+MF[k]*(FS[y]-FS[x]+mo))%mo;
	}
	void propagate(int k,int l,int r) {
		int m=(l+r)/2;
		
		for(int i=2*k;i<=2*k+1;i++) {
			(M[i]*=M[k])%=mo;
			(A[i]*=M[k])%=mo;
			(MF[i]*=M[k])%=mo;
			(S[i]*=M[k])%=mo;
			(A[i]+=A[k])%=mo;
			(MF[i]+=MF[k])%=mo;
		}
		(S[k*2]+=A[k]*(m-l)+(FS[m]-FS[l]+mo)*MF[k])%=mo;
		(S[k*2+1]+=A[k]*(r-m)+(FS[r]-FS[m]+mo)*MF[k])%=mo;
		
		M[k]=1;
		A[k]=MF[k]=0;
	}

	void doM(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			(M[k]*=v)%=mo;
			(A[k]*=v)%=mo;
			(S[k]*=v)%=mo;
			(MF[k]*=v)%=mo;
		}
		else if(l < y && x < r) {
			propagate(k,l,r);
			doM(x,y,v,l,(l+r)/2,k*2);
			doM(x,y,v,(l+r)/2,r,k*2+1);
			S[k]=(S[k*2]+S[k*2+1])%mo;
		}
	}
	void doMF(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			(MF[k]+=v)%=mo;
			(S[k]+=(FS[r]-FS[l]+mo)*v)%=mo;
		}
		else if(l < y && x < r) {
			propagate(k,l,r);
			doMF(x,y,v,l,(l+r)/2,k*2);
			doMF(x,y,v,(l+r)/2,r,k*2+1);
			S[k]=(S[k*2]+S[k*2+1])%mo;
		}
	}
	void doA(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			(A[k]+=v)%=mo;
			(S[k]+=(r-l)*v)%=mo;
		}
		else if(l < y && x < r) {
			propagate(k,l,r);
			doA(x,y,v,l,(l+r)/2,k*2);
			doA(x,y,v,(l+r)/2,r,k*2+1);
			S[k]=(S[k*2]+S[k*2+1])%mo;
		}
	}
};

SegTree_MulAdd<ll, 1<<21> st;

int N,Q;
int T,L,R,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	F[1]=FS[2]=1;
	for(i=2;i<=1<<20;i++) {
		F[i]=(F[i-1]+F[i-2])%mo;
		FS[i+1]=(FS[i]+F[i])%mo;
	}
	
	scanf("%d%d",&N,&Q);
	while(Q--) {
		scanf("%d%d%d%d",&T,&L,&R,&K);
		R++;
		if(T==0) {
			ll v=st.getval(L,R);
			cout<<v*K%mo<<endl;
		}
		else if(T==1) {
			st.doM(L,R,0);
			st.doA(L,R,K);
		}
		else if(T==2) {
			st.doA(L,R,K);
		}
		else if(T==3) {
			st.doM(L,R,K);
		}
		else if(T==4) {
			st.doMF(L,R,K);
		}
		/*
		FOR(i,5) cout<<st.getval(i,i+1)<<" ";
		cout<<endl;
		*/
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
