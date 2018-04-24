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
int S[2020],T[2020];
int rev[8040];
short memo[8080][8080];

int hoge(int L,int R) {
	if(R<=L) return 0;
	if(memo[L][R]>=0) return memo[L][R];
	
	int cur=rev[L];
	int op=-1;
	if(L<S[cur] && S[cur]<=R) op=S[cur];
	if(L<T[cur] && T[cur]<=R) op=T[cur];
	if(L<2*N+S[cur] && 2*N+S[cur]<=R) op=2*N+S[cur];
	if(L<2*N+T[cur] && 2*N+T[cur]<=R) op=2*N+T[cur];
	
	
	memo[L][R]=hoge(L+1,R);
	if(op!=-1) memo[L][R]=(short)max((int)memo[L][R],1+hoge(L+1,op-1)+hoge(op+1,R));
	return memo[L][R];
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	map<int,int> M;
	FOR(i,N) {
		cin>>S[i]>>T[i];
		if(S[i]>T[i]) swap(S[i],T[i]);
		M[S[i]]=M[T[i]]=0;
	}
	x=0;
	FORR(r,M) r.second=x++;
	FOR(i,N) {
		S[i]=M[S[i]];
		T[i]=M[T[i]];
		rev[S[i]]=rev[2*N+S[i]]=i;
		rev[T[i]]=rev[2*N+T[i]]=i;
	}
	
	MINUS(memo);
	
	int ma=0;
	FOR(i,N) {
		ma=max(ma,1+hoge(S[i]+1,T[i]-1)+hoge(T[i]+1,2*N+S[i]-1));
	}
	cout<<ma<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
