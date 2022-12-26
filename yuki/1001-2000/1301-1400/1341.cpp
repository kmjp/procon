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
ll M;
int B[3030];
pair<int,int> P[3030];
int vis[3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x>>B[i]>>y;
		if(x>y) swap(x,y);
		if(x==y) return _P("NO\n");
		P[i]={y,x};
	}
	ll ma=-1;
	sort(B,B+N);
	sort(P,P+N);
	
	FOR(k,N+1) {
		ZERO(vis);
		ll ok=0;
		x=N-1;
		multiset<int> S;
		FOR(i,k) S.insert(B[i]);
		for(i=N-1;i>=0;i--) if(S.size()) {
			auto it=S.lower_bound(P[i].second);
			if(it!=S.begin()) {
				it--;
				vis[i]=1;
				ok+=P[i].first;
				S.erase(it);
			}
		}
		if(S.size()) continue;
		x=0;
		for(i=k;i<N;i++) {
			while(x<N&&vis[x]) x++;
			if(x==N||P[x].first>=B[i]) break;
			x++;
			ok+=B[i];
		}
		if(i<N) continue;
		ma=max(ma,ok);
	}
	
	if(ma==-1) {
		cout<<"NO"<<endl;
	}
	else {
		cout<<"YES"<<endl;
		if(ma<M) cout<<"NO"<<endl;
		else cout<<"KADOMATSU!"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
