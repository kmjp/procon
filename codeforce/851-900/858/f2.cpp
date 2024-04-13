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
int N,K;
ll M, A[1010101];
vector<ll> X,Y,G;
vector<__int128> Xs,Ys;
__int128 ma[1010101];
void solve() {
	int i,j,k,l,r,x,y,t; string s;
	
	cin>>T;
	FOR(t,T) {
		cin>>N>>M>>K;
		FOR(i,N) {
			cin>>A[i];
			ma[i]=-1;
			ma[i]<<=120;
		}
		
		sort(A,A+N);
		X.clear();
		Y.clear();
		Xs={0};
		Ys={0};
		G={0};
		
		__int128 ret=0;
		FOR(i,N) {
			if(i&&A[i]==A[i-1]) {
				Y.push_back(A[i]);
				Ys.push_back(Ys.back()+A[i]);
			}
			else {
				X.push_back(A[i]);
				Xs.push_back(Xs.back()+A[i]);
				G.push_back(__gcd(G.back(),A[i]));
			}
		}
		
		ll g=0;
		for(int L=0,R=0;L<min(K,(int)X.size());L=R+1) {
			R=L;
			while(R<X.size()&&G[L+1]==G[R+1]) R++;
			R--;
			__int128 cma=-1;
			cma<<=120;
			for(i=R+1;i<X.size();i++) {
				cma=max(cma,__gcd(G[L+1],X[i])-(__int128)X[i]);
			}
			for(i=R;i>=L;i--) {
				ma[i]=Xs[X.size()]-Xs[i+1]+cma;
				cma=max(cma,__gcd(G[L+1],X[i])-(__int128)X[i]);
			}
		}
		if(Y.size()>=K) {
			ret=max(ret,Xs.back()+Ys.back()-Ys[K]);
		}
		for(x=1;x<=X.size()&&x<=K;x++) {
			y=K-x;
			if(y<0||y>Y.size()) continue;
			ret=max(ret,Ys.back()-Ys[y]+ma[x-1]);
		}
		
		
		string s;
		while(ret) {
			s+='0'+ret%10;
			ret/=10;
		}
		reverse(ALL(s));
		cout<<s<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
