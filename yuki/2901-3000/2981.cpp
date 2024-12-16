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

int Q;
int N;
vector<int> E[600];
int H,W;
string S[20];
ll memo[603];
int ret[303];

ll tree_normalize(vector<ll> T) {
	static ll momo[2]={1000000007,1000000021};
	static ll sa=0,sb=0;
	
	if(sa==0) {
		srand(time(NULL));sa=rand()%(123456789);sb=rand()%(123456789);
	}
	
	sort(ALL(T));
	ll a=sa,b=sb;
	int add=1;
	FORR(r,T) {
		ll h=r>>32, l=r-(h<<32);
		(a*=h+add++)%=momo[0];
		(b*=l+add++)%=momo[1];
	}
	return (a<<32)+b;
}

ll dfs(int cur,int pre) {
	if(memo[cur]>=0) return memo[cur];
	
	vector<ll> V;
	V.push_back((1LL)+(1LL<<32));
	
	FORR(e,E[cur]) if(e!=pre) V.push_back(dfs(e,cur));
	
	return memo[cur]=tree_normalize(V);
}

void dfs2(int cur1,int pre1,int cur2,int pre2) {
	ret[cur1]=cur2-300;
	vector<pair<ll,pair<int,int>>> V,W;
	FORR(e,E[cur1]) if(e!=pre1) V.push_back({dfs(e,cur1),{E[e].size(),e}});
	FORR(e,E[cur2]) if(e!=pre2) W.push_back({dfs(e,cur2),{E[e].size(),e}});
	sort(ALL(V));
	sort(ALL(W));
	int i;
	FOR(i,V.size()) dfs2(V[i].second.second,cur1,W[i].second.second,cur2);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N;
		FOR(i,600) E[i].clear();
		int nex=N;
		FOR(i,N-1) {
			cin>>x>>y>>k;
			x--,y--;
			FOR(j,k-1) {
				if(nex>300) break;
				E[x].push_back(nex);
				E[nex].push_back(x);
				x=nex++;
			}
			E[x].push_back(y);
			E[y].push_back(x);
		}
		
		MINUS(memo);
		cin>>H>>W;
		FOR(y,H) {
			cin>>S[y];
			FOR(x,W) if(S[y][x]=='#') {
				if(y&&S[y-1][x]=='#') {
					E[300+y*W+x].push_back(300+(y-1)*W+x);
					E[300+(y-1)*W+x].push_back(300+y*W+x);
				}
				if(x&&S[y][x-1]=='#') {
					E[300+y*W+x].push_back(300+y*W+x-1);
					E[300+y*W+x-1].push_back(300+y*W+x);
				}
			}
		}
		if(nex>300) {
			cout<<"No"<<endl;
			continue;
		}
		auto H1=dfs(0,0);
		int ok=0;
		FOR(y,H) FOR(x,W) if(S[y][x]=='#'&&ok==0) {
			k++;
			MINUS(memo);
			auto H2=dfs(300+y*W+x,300+y*W+x);
			if(H1==H2) {
				ok=1;
				dfs2(0,0,300+y*W+x,300+y*W+x);
			}
		}
		if(ok) {
			cout<<"Yes"<<endl;
			FOR(i,N) cout<<ret[i]/W+1<<" "<<ret[i]%W+1<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
