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
int nex[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int turn=0;
	priority_queue<pair<ll,int>> P;
	vector<ll> V;
	for(i=1;i<=N-2;i++) {
		P.push({-1LL*i*(i+1),i});
		nex[i]=i+2;
	}
	ll sum=0;
	while(P.size()) {
		ll sc=-P.top().first;
		int cur=P.top().second;
		P.pop();
		if(nex[cur]<N) {
			P.push({-1LL*cur*nex[cur],cur});
			nex[cur]++;
		}
		
		if(turn==0) {
			if(sum<=-N) return _P("First\n");
			sum+=sc;
		}
		else {
			if(sum>N) return _P("Second\n");
			sum-=sc;
		}
		turn^=1;
		//cout<<turn<<" "<<cur<<" "<<sc<<" "<<sum<<endl;
	}
	if(turn==0) sum+=N;
	else sum-=N;
	
	if(sum>0) {
		cout<<"Second"<<endl;
	}
	else {
		cout<<"First"<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
