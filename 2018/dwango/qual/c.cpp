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

int N,M;
int AS,BS;
map<int,int> A,B;

ll mo=1000000007;

ll memo[1010][1010];
ll pat(int T,int N) {
	if(T<0) return 0;
	if(N==0) return T==0;
	if(T==0) return 1;
	if(memo[T][N]>=0) return memo[T][N];
	
	ll ret=0;
	ret += pat(T-N,N) + pat(T,N-1);
	return memo[T][N]=ret%mo;
}

ll from[1010];
ll to[1010];

ll hoge(map<int,int> M,int T) {
	ZERO(from);
	from[T]=1;
	
	FORR(m,M) {
		int x=m.second;
		ZERO(to);
		
		for(int a=0;a<=T;a++) if(from[a]) {
			for(int b=0;b<=a;b++) {
				(to[a-b]+=from[a]*pat(b,x))%=mo;
			}
		}
		swap(from,to);
		
	}
	return from[0];
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>x, BS+=x, A[x]++;
	FOR(i,M) cin>>x, AS+=x, B[x]++;
	MINUS(memo);
	cout<<hoge(A,AS)*hoge(B,BS)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
