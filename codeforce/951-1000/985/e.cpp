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

int T,N,A[101010];
int pre[404040];
vector<int> D[404040];
ll ok[404040];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,404040) pre[i]=i;
	for(i=2;i<=400000;i++) {
		for(j=i;j<=400000;j+=i) {
			D[j].push_back(j+i);
			if(j+i<=400000) pre[j+i]=min(pre[j+i],i);
		}
	}
	
	/*
	k=43;
	for(x=k;x<k+1;x++) {
		set<int> S={x},V;
		while(S.size()) {
			y=*S.begin();
			S.erase(y);
			ok[y] |= 1LL<<x;
			V.insert(y);
			FORR(a,D[y]) if(a<=400000) S.insert(a);
		}
	}
	for(i=2;i<=400000;i++) if(ok[i]==0&&D[i].size()>1&&i>2*k) cout<<i<<" "<<D[i].size()<<endl;
	*/
	
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		sort(A,A+N);
		vector<int> V;
		FOR(x,N) if(D[A[x]].size()==1) V.push_back(A[x]);
		
		if(V.empty()) {
			cout<<2<<endl;
		}
		else if(V.size()>1) {
			cout<<-1<<endl;
		}
		else {
			int ok=1;
			x=V[0];
			FOR(i,N) {
				if(A[i]==x) continue;
				if(A[i]==2*x) continue;
				if(A[i]-pre[A[i]]<2*x) ok=0;
			}
			if(ok) cout<<x<<endl;
			else cout<<-1<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
