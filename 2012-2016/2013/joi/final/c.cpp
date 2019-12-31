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

int W,H,K;
int X[202020],Y[202020],RS[202020],CS[202020];
vector<pair<int,int>> R[101010];
vector<pair<int,int>> C[101010];
int isroot=0;

ll dist[202020][2];

priority_queue<pair<ll,int>> P;

void add(ll co,int tar,int way) {
	if(dist[tar][way] > co) {
		dist[tar][way] = co;
		P.push({-co,tar*2+way});
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H>>K;
	FOR(i,K) {
		cin>>X[i]>>Y[i];
		if(X[i]==W&&Y[i]==H) {
			K--;
			i--;
			continue;
		}
		if(X[i]==1&&Y[i]==1) {
			isroot++;
			K--;
			i--;
			continue;
		}
		R[Y[i]].push_back({X[i],i});
		C[X[i]].push_back({Y[i],i});
	}
	X[K]=Y[K]=1;
	R[1].push_back({1,K});
	C[1].push_back({1,K});
	K++;
	X[K]=W, Y[K]=H;
	R[H].push_back({W,K});
	C[W].push_back({H,K});
	K++;
	
	FOR(i,100001) {
		sort(ALL(R[i]));
		sort(ALL(C[i]));
		FOR(j,R[i].size()) RS[R[i][j].second]=j;
		FOR(j,C[i].size()) CS[C[i][j].second]=j;
	}
	
	FOR(i,K) dist[i][0]=dist[i][1]=1LL<<60;
	add(0,K-2,0);
	
	while(P.size()) {
		int cur=P.top().second/2;
		int way=P.top().second%2;
		ll co=-P.top().first;
		P.pop();
		if(co!=dist[cur][way]) continue;
		if(cur==K-1) {
			cout<<co<<endl;
			return;
		}
		
		if(cur!=K-2 || isroot) {
			add(co+1,cur,way^1);
		}
		
		if(way==0) {
			if(CS[cur]>0) {
				int tar=C[X[cur]][CS[cur]-1].second;
				add(co+Y[cur]-Y[tar],tar,0);
			}
			if(CS[cur]<C[X[cur]].size()-1) {
				int tar=C[X[cur]][CS[cur]+1].second;
				add(co+Y[tar]-Y[cur],tar,0);
			}
		}
		else {
			if(RS[cur]>0) {
				int tar=R[Y[cur]][RS[cur]-1].second;
				add(co+X[cur]-X[tar],tar,1);
			}
			if(RS[cur]<R[Y[cur]].size()-1) {
				int tar=R[Y[cur]][RS[cur]+1].second;
				add(co+X[tar]-X[cur],tar,1);
			}
		}
	}
	
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
