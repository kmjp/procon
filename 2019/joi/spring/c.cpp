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

int N,L;
ll V[2020][2020];
ll S[2020];
pair<ll,ll> P[2020][2020];

pair<ll,ll> ret[2020];
int RP[2020];
int did[2020];


bool le(pair<ll,ll> a,pair<ll,ll> b) {
	// a1/a2<b1/b2
	return (__int128_t)a.first*b.second<(__int128_t)b.first*a.second;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	FOR(i,N) {
		FOR(x,L) {
			cin>>V[i][x];
			V[i][x]*=N;
			S[x+1]=S[x]+V[i][x];
		}
		ll step=S[L]/N;
		
		for(x=1;x<=N;x++) {
			ll v=step*x;
			y=lower_bound(S,S+L+1,v)-S;
			if(S[y]==step*x) {
				P[i][x]={y,1};
			}
			else {
				y--;
				ll a=y*V[i][y]+v-S[y];
				ll b=V[i][y];
				ll g=__gcd(a,b);
				P[i][x]={a/g,b/g};
				assert(b/g<=1000000000);
				
			}
		}
	}
	FOR(x,N) {
		int id=-1;
		FOR(y,N) if(did[y]==0){
			if(id==-1) {
				id=y;
			}
			else if(le(P[y][x+1],P[id][x+1])) {
				id=y;
			}
		}
		if(x<N-1) cout<<P[id][x+1].first<<" "<<P[id][x+1].second<<endl;
		RP[x+1]=id+1;
		did[id]=1;
	}
	FOR(x,N) cout<<RP[x+1]<<" ";
	cout<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
