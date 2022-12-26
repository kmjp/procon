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

int N;
ll P,mo;
ll B[1010101];
int AA[101010],BB[101010];

const int MAT=3;
ll ma[MAT][MAT],V[MAT],R[MAT];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int Gauss(int n,ll mat_[MAT][MAT],ll v_[MAT],ll r[MAT]) {
	int i,j,k;
	ll mat[MAT][MAT],v[MAT];
	memmove(mat,mat_,sizeof(mat));
	memmove(v,v_,sizeof(v));
	
	FOR(i,n) {
		if(mat[i][i]==0) {
			for(j=i+1;j<n;j++) if(mat[j][i]) break;
			if(j>=n) return i;
			FOR(k,n) swap(mat[i][k],mat[j][k]);
			swap(v[i],v[j]);
		}
		(v[i]*=modpow(mat[i][i]))%=mo;
		for(k=n-1;k>=i;k--) (mat[i][k]*=modpow(mat[i][i]))%=mo;
		for(j=i+1;j<n;j++) {
			v[j]=((v[j]-v[i]*mat[j][i]%mo)+mo)%mo;
			for(k=n-1;k>=i;k--) mat[j][k]=((mat[j][k]-mat[i][k]*mat[j][i]%mo)+mo)%mo;
		}
	}
	
	
	for(i=n-1;i>=0;i--) {
		for(j=n-1;j>i;j--) v[i]=((v[i]-mat[i][j]*v[j]%mo)+mo)%mo;
		r[i]=v[i];
	}
	return n;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(B);
	cin>>N>>P;
	mo=P;
	FOR(i,N) cin>>AA[i];
	FOR(i,N) {
		cin>>BB[i];
		x=AA[i];
		y=BB[i];
		if(B[x]==-1) {
			B[x]=y;
		}
		else if(B[x]!=y) {
			return _P("impossible\n");
		}
	}
	vector<int> C;
	FOR(i,P) if(B[i]>=0) C.push_back(i);
	
	if(C.size()==1) {
		cout<<0<<" "<<0<<" "<<B[C[0]]<<endl;
	}
	else if(C.size()==2) {
		ll b=(B[C[1]]-B[C[0]]+mo)*modpow(C[1]-C[0])%P;
		ll c=((B[C[0]]-b*C[0])%P+P)%P;
		cout<<0<<" "<<b<<" "<<c<<endl;
	}
	else {
		FOR(i,3) {
			ma[i][0]=1LL*C[i]*C[i]%P;
			ma[i][1]=C[i];
			ma[i][2]=1;
			V[i]=B[C[i]];
		}
		x=Gauss(3,ma,V,R);
		if(x<3) return _P("impossible\n");
		ll a=R[0],b=R[1],c=R[2];
		FOR(i,P) if(B[i]>=0) {
			if(B[i]!=(a*i*i+b*i+c)%P) return _P("impossible\n");
		}
		cout<<a<<" "<<b<<" "<<c<<endl;
		
		
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
