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
ll D[101010];
pair<ll,int> P[101010];
int num[101010],par[101010];
ll DS[101010];
vector<pair<int,int>> E;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>D[i];
		P[i]={D[i],i+1};
	}
	sort(P,P+N);
	sort(D,D+N);
	
	for(i=N-1;i>=1;i--) {
		num[i]++;
		ll sj=D[i]+2*num[i]-N;
		x=lower_bound(D,D+N,sj)-D;
		if(x>=i || D[x]!=sj) return _P("-1\n");
		E.push_back({x,i});
		num[x]+=num[i];
		DS[x]+=DS[i]+num[i];
		par[i]=x;
	}
	if(DS[0]!=D[0]) return _P("-1\n");
	
	FORR(e,E) cout<<P[e.first].second<<" "<<P[e.second].second<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
