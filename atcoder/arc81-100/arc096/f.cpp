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
ll X,D;
ll M[1010];
int P[1010];
vector<int> E[51];

int Y[1010];
ll Z[1010];
int C[51];

ll cost[51][51*51*51+100];
int from[51][51*51*51+100];

bool cmp(int L,int R) {
	return Y[L]*M[R]>Y[R]*M[L];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>D;
	FOR(i,N) {
		cin>>M[i];
		if(i) {
			cin>>P[i];
			P[i]--;
			E[P[i]].push_back(i);
			Z[i]=D;
		}
		else {
			Z[i]=1<<30;
		}
		C[i]=i;
	}
	
	for(i=N-1;i>=0;i--) {
		Y[i]=1;
		FORR(e,E[i]) {
			Y[i]+=Y[e];
			M[i]+=M[e];
		}
	}
	
	sort(C,C+N,cmp);
	
	FOR(i,N+1) FOR(x,51*51*51+1) cost[i][x]=1LL<<60;
	cost[0][0]=0;
	FOR(i,N) {
		FOR(x,50*50*50+1) {
			for(y=0;y<=min(50,(int)Z[i])&&x+y*Y[i]<=50*50*50;y++) {
				if(cost[i+1][x+y*Y[i]] > cost[i][x]+y*M[i]) {
					cost[i+1][x+y*Y[i]]=cost[i][x]+y*M[i];
					from[i+1][x+y*Y[i]]=y;
				}
			}
		}
	}
	
	ll ma=0;
	FOR(x,50*50*50+1) if(cost[N][x]<1LL<<60) {
		int cnt[51];
		int cur=N;
		y=x;
		while(cur) {
			cnt[cur-1]=Z[cur-1]-from[cur][y];
			y-=from[cur][y]*Y[cur-1];
			cur--;
		}
		
		ll ret=x;
		ll left=X-cost[N][x];
		if(left<0) continue;
		FOR(i,N) {
			ll del=min((ll)(Z[C[i]]-min(50LL,Z[C[i]])),left/M[C[i]]);
			ret+=del*Y[C[i]];
			left-=del*M[C[i]];
		}
		ma=max(ma,ret);
	}
	
	cout<<ma<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
