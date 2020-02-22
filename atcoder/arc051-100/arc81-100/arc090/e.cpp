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
int S,T;
vector<pair<int,int>> E[101010];
ll D[2][101010];
ll pat[2][101010];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	cin>>S>>T;
	S--,T--;
	FOR(i,M) {
		cin>>x>>y>>j;
		x--,y--;
		E[x].push_back({y,j});
		E[y].push_back({x,j});
	}
	
	priority_queue<pair<ll,int>> P;
	pat[0][S]=pat[1][T]=1;
	FOR(i,N) D[0][i]=D[1][i]=1LL<<60;
	D[0][S]=D[1][T]=0;
	P.push({0,S});
	P.push({0,100000+T});
	
	while(P.size()) {
		int cur=P.top().second%100000;
		int id=P.top().second/100000;
		ll co=-P.top().first;
		P.pop();
		if(D[id][cur]!=co) continue;
		FORR(e,E[cur]) {
			if(co+e.second < D[id][e.first]) {
				pat[id][e.first]=0;
				D[id][e.first] = co+e.second;
				P.push({-D[id][e.first],id*100000+e.first});
			}
			if(co+e.second == D[id][e.first]) (pat[id][e.first]+=pat[id][cur])%=mo;
			
		}
	}
	
	
	ll tot=pat[0][T]*pat[0][T]%mo;
	FOR(i,N) if(D[0][i]+D[1][i]==D[0][T]) {
		if(D[0][i]==D[1][i]) {
			tot+=mo-pat[0][i]*pat[0][i]%mo*pat[1][i]%mo*pat[1][i]%mo;
		}
		if(D[0][i]<D[1][i]) {
			FORR(e,E[i]) if(D[0][e.first]+D[1][e.first]==D[0][T] && D[0][e.first]>D[1][e.first] && D[0][e.first]==D[0][i]+e.second) {
				tot+=mo-pat[0][i]*pat[0][i]%mo*pat[1][e.first]%mo*pat[1][e.first]%mo;
			}
		}
		tot%=mo;
		
	}
	
	cout<<tot<<endl;
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
