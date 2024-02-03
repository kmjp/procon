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

int N;
const int DI=600;
ll A[402020];
vector<int> B[DI];
vector<ll> S[DI];
int Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,(202020/DI)+2) {
		FOR(j,DI) B[i].push_back(A[i*DI+j]);
		sort(ALL(B[i]));
		S[i]={0};
		FORR(b,B[i]) S[i].push_back(S[i].back()+b);
	}
	ll ret=0;
	
	cin>>Q;
	while(Q--) {
		ll TL,TR,TX;
		cin>>TL>>TR>>TX;
		int L=TL^ret;
		int R=TR^ret;
		int X=TX^ret;
		
		ret=0;
		L--;
		
		while(L%DI&&L<R) {
			if(A[L]<=X) ret+=A[L];
			L++;
		}
		while(R%DI&&L<R) {
			R--;
			if(A[R]<=X) ret+=A[R];
		}
		while(L<R) {
			x=L/DI;
			y=lower_bound(ALL(B[x]),(int)X+1)-B[x].begin();
			ret+=S[x][y];
			L+=DI;
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
