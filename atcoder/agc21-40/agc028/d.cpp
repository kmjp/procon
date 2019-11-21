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

int N,K;
int OP[1606];
ll fact2[3030];
ll mo=1000000007;
ll memo[603][603];

ll dp(int L,int R) {
	if((R-L)%2==0) return 0;
	if(memo[L][R]>=0) return memo[L][R];
	
	int i;
	int NF=0;
	for(i=L;i<=R;i++) {
		if(OP[i]!=-1 && (OP[i]<L || OP[i]>R)) return memo[L][R]=0;
		NF+=OP[i]==-1;
	}
	ll ret=fact2[NF];
	int NF2=0;
	for(i=L;i<R;i++) {
		NF2+=OP[i]==-1;
		ret+=mo-dp(L,i)*fact2[NF-NF2]%mo;
	}
	
	return memo[L][R]=ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact2[0]=1;
	for(i=2;i<=600;i+=2) fact2[i]=fact2[i-2]*(i-1)%mo;
	
	MINUS(OP);
	MINUS(memo);
	
	cin>>N>>K;
	N*=2;
	FOR(i,K) {
		cin>>x>>y;
		OP[x-1]=y-1;
		OP[y-1]=x-1;
	}
	
	int NFS=0;
	FOR(i,N) NFS+=(OP[i]==-1);
	
	ll ret=0;
	FOR(x,N) {
		int NF=0;
		for(y=x;y<N;y++) {
			NF+=OP[y]==-1;
			ret+=dp(x,y)*fact2[NFS-NF]%mo;
		}
	}
	
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
