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
int A[202020];
int T[202020],X[202020],Y[202020];
int vis[202020];
vector<int> V;
vector<int> W;
vector<ll> S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	cin>>Q;
	FOR(i,Q) {
		cin>>T[i]>>X[i];
		if(T[i]==1) cin>>Y[i];
	}
	FOR(r,202) {
		int L=r*1000,R=min(Q,(r+1)*1000);
		if(L>=R) continue;
		FOR(i,N) vis[i]=0;
		for(j=L;j<R;j++) if(T[j]==1) vis[X[j]-1]=1;
		V.clear();
		W.clear();
		S.clear();
		S.push_back(0);
		FOR(i,N) {
			if(vis[i]==0) V.push_back(A[i]);
			else W.push_back(i);
		}
		sort(ALL(V));
		FORR(v,V) S.push_back(S.back()+v);
		
		for(i=L;i<R;i++) {
			if(T[i]==1) {
				A[X[i]-1]+=Y[i];
			}
			else {
				ll ret=0;
				FORR(w,W) ret+=abs(X[i]-A[w]);
				int num=lower_bound(ALL(V),X[i])-V.begin();
				ret+=1LL*num*X[i]-S[num];
				ret+=S.back()-S[num]-1LL*(V.size()-num)*X[i];
				cout<<ret<<endl;
			}
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
