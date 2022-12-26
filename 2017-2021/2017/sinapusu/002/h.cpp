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
int mi[101010];
int A[101010];
vector<int> del[101010];
multiset<int> MS;
int cnt[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>A[i];
		mi[i]=1<<30;
	}
	
	int R=0;
	int is=0;
	ZERO(cnt);
	FOR(i,N) {
		FORR(r,del[i]) MS.erase(MS.find(r));
		del[i].clear();
		while(R<N && is<M) if(++cnt[A[R++]]==1) is++;
		if(is==M) {
			MS.insert(R-i-1);
			del[R].push_back(R-i-1);
		}
		if(MS.size()) mi[i]=min(mi[i],*MS.begin()*2);
		if(--cnt[A[i]]==0) is--;
	}
	
	R=N-1;
	MS.clear();
	for(i=N-1;i>=0;i--) {
		FORR(r,del[i]) MS.erase(MS.find(r));
		while(R>=0 && is<M) if(++cnt[A[R--]]==1) is++;
		
		if(is==M) {
			MS.insert(i-R-1);
			if(R>=0) del[R].push_back(i-R-1);
		}
		if(MS.size()) mi[i]=min(mi[i],*MS.begin()*2);
		if(--cnt[A[i]]==0) is--;
	}
	
	ll ret=0;
	FOR(i,N) ret+=mi[i];
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
