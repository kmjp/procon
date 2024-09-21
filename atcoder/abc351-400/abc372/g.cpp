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

int T;
int N;
ll A[202020],B[202020],C[202020];
int E[202020];

ll floor_sum(ll N,ll M,ll A,ll B) {
	// sum(i=0...N-1) floor((A*i+B)/M)
	if(N<=0) return 0;
	if(A<0) return floor_sum(N,M,-A,B+(N-1)*A); //Aが負の場合傾きを逆にする
	ll ret=0;
	if(B>=M) ret+=N*(B/M), B%=M;
	if(A>=M) ret+=N*(N-1)/2*(A/M), A%=M;
	
	ll Y=(A*N+B)/M;
	if(Y==0) return ret;
	//floor(Y/M)に達するX
	ll X=Y*M-B;
	//Xの右側はY個ずつ
	ret+=(N-(X+A-1)/A)*Y;
	// 90度回転、Y=Nのラインは無視する
	ret+=floor_sum(Y,A,M,(A-X%A)%A);
	return ret;
}


// C/Bでソート
bool cmp(int s,int t) {
	//return C[s]/B[s]<C[t]/B[t];
	if(C[s]*B[t]==C[t]*B[s]) {
		//同じなら傾きが大きい方が先
		return A[s]*B[t]>A[t]*B[s];
	}
	else {
		return C[s]*B[t]<C[t]*B[s];
	}
}

int hoge(int s,int t,int u) {
	// s-uの交点がs-tの交点よりx座標が小さい
	__int128 sux=A[s]*B[u]-A[u]*B[s];
	__int128 suy=C[s]*B[u]-C[u]*B[s];
	__int128 stx=A[s]*B[t]-A[t]*B[s];
	__int128 sty=C[s]*B[t]-C[t]*B[s];
	
	// suy/sux<sty/stx
	return suy*stx<=sty*sux;
}
ll hoge(int s,int t) {
	// tが初めて優位になるx座標
	ll x=A[s]*B[t]-A[t]*B[s];
	ll y=C[s]*B[t]-C[t]*B[s];
	return y/x+1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[i]>>B[i]>>C[i];
			C[i]--;
			E[i]=i;
		}
		sort(E,E+N,cmp);
		vector<int> D;
		FOR(i,N) {
			j=E[i];
			
			if(D.size()) {
				x=D.back();
				if(A[j]*B[x]<=A[x]*B[j]) continue;
			}
			
			while(D.size()>=2&&hoge(D[D.size()-2],D[D.size()-1],j)) D.pop_back();
			D.push_back(j);
		}
		vector<ll> V={-1LL<<60};
		FOR(i,D.size()-1) V.push_back(hoge(D[i],D[i+1]));
		V.push_back(1LL<<60);
		
		FOR(i,V.size()-1) assert(V[i]<=V[i+1]);
		
		ll ret=0;
		FOR(i,D.size()) {
			j=D[i];
			ll x=max(1LL,V[i]);
			ll y=min(V[i+1]-1,C[j]/A[j]);
			if(x>y) continue;
			ret+=floor_sum(y+1,B[j],-A[j],C[j]);
			ret-=floor_sum(x,B[j],-A[j],C[j]);
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
