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
pair<int,int> P[5050];

int from[10101];
int to[10101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i].first>>P[i].second;
	}
	sort(P,P+N);
	FOR(i,10100) from[i]=1<<20;
	from[0]=0;
	FOR(i,N-1) {
		FOR(x,10100) to[x]=1<<20;
		FOR(x,10100) if(from[x]<1<<20) {
			// front
			int a=max(x,P[i].first)+P[i].second;
			to[a]=min(to[a],from[x]);
			// back
			a=max(from[x],P[i].first)+P[i].second;
			to[x]=min(to[x],a);
		}
		swap(from,to);
	}
	int mi=1<<20;
	FOR(x,10100) if(from[x]<1<<20) {
		int a=max(x,P[N-1].first);
		int b=max(from[x],P[N-1].first);
		
		if(abs(a-b)>=P[N-1].second) {
			mi=min(mi,max(a,b));
		}
		else {
			y=P[N-1].second-abs(a-b);
			mi=min(mi,max(a,b)+(y+1)/2);
		}
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
