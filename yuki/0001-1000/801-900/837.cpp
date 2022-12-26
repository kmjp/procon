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
ll Y[101010];
ll S[101010];

ll hoge(int L,int R) {
	int M=(L+R)/2;
	R--;
	ll sum=S[R+1]-S[M+1]-Y[M]*(R-M);
	sum+=Y[M]*(M-L)-(S[M]-S[L]);
	return sum;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>Y[i];
	sort(Y,Y+N);
	if(Y[0]==Y[N-1]) return _P("1\n");
	FOR(i,N) S[i+1]=S[i]+Y[i];
	
	ll mi=1LL<<60;
	FOR(i,N-1) {
		x=i/2;
		y=(i+1)+(N-(i+1))/2;
		if(Y[x]==Y[y]) continue;
		mi=min(mi,hoge(0,i+1)+hoge(i+1,N));
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
