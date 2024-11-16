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

int T,N,K;
int A[202020],B[202020];
pair<int,int> C[202020];
ll S[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) cin>>A[i];
		FOR(i,N) cin>>B[i];
		FOR(i,N) C[i]={B[i],A[i]};
		sort(C,C+N);
		
		FOR(i,N) {
			S[i+1]=S[i]+max(0,C[i].first-C[i].second);
		}
		ll ret=0;
		ll suma=0;
		multiset<int> As;
		if(K==0) ret=S[N];
		for(i=N-1;i>=0;i--) {
			suma+=C[i].second;
			As.insert(C[i].second);
			if(As.size()>K) {
				suma-=*As.rbegin();
				As.erase(As.find(*As.rbegin()));
			}
			if(As.size()==K) {
				ret=max(ret,S[i]-suma);
			}
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
