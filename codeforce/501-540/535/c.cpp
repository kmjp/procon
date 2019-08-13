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

int N,M,K;
vector<int> E[505050];

int D[505050];
int P[505050];
vector<pair<int,int>> cand[505050];
int num;

vector<pair<int,int>> nex[505050];

void dfs(int cur,int pre,int more) {
	if(pre==-1) {
		D[cur]=P[cur]=0;
	}
	else {
		D[cur]=D[pre]+1;
		P[cur]=pre;
	}
	
	nex[cur].push_back({1,cur});
	nex[cur].push_back({1,cur});
	
	FORR(e,E[cur]) if(e!=pre) {
		if(D[e]>=0) {
			if(D[e]<D[cur] && (D[cur]-D[e])%3!=2) {
				if(D[e]>more) {
					cand[D[cur]-D[e]].push_back({cur,e});
					num++;
					more=D[cur];
				}
			}
		}
	}
	
	FORR(e,E[cur]) if(D[e]==-1) {
		dfs(e,cur,more);
		nex[cur].push_back({nex[e][0].first+1,e});
	}
	sort(ALL(nex[cur]));
	reverse(ALL(nex[cur]));
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&N,&M,&K);
	FOR(i,M) {
		scanf("%d%d",&x,&y);
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	MINUS(D);
	dfs(0,-1,-1);
	
	if(num>=K) {
		cout<<"CYCLES"<<endl;
		FOR(i,505050) if(K) {
			FORR(c,cand[i]) if(K) {
				cout<<(i+1)<<endl;
				x=c.first;
				y=c.second;
				while(x!=y) {
					cout<<x+1<<" ";
					x=P[x];
				}
				cout<<(y+1)<<endl;
				K--;
			}
		}
		return;
	}
	
	FOR(i,N) {
		if(nex[i][0].first+nex[i][1].first-1>=(N+K-1)/K) {
			deque<int> D;
			D.push_back(i);
			x=i;
			while(1) {
				if(nex[x][0].second==x) break;
				x=nex[x][0].second;
				D.push_back(x);
			}
			x=nex[i][1].second;
			if(x!=i) {
				D.push_front(x);
				while(1) {
					if(nex[x][0].second==x) break;
					x=nex[x][0].second;
					D.push_front(x);
				}
			}
			
			assert(D.size()>=(N+K-1)/K);
			cout<<"PATH"<<endl;
			cout<<D.size()<<endl;
			FORR(d,D) cout<<d+1<<" ";
			cout<<endl;
			return;
		}
	}
	cout<<-1<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
