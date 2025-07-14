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

int N,M;
const int DI=17;
const int DI2=DI+1;
ll X[1<<DI];
ll L1[202020],R1[202020],L2[202020],R2[202020],C[202020];
int LV[19][4];

vector<pair<int,ll>> E[1<<22];
ll dp[1<<22];

void dfs(int tid,int lv,int L,int R,int x,int y,int id,int order,ll TX) {
	if(x>=R) return ;
	if(y<=L) return;
	int cur=LV[lv][tid]+(L>>lv);
	if(x<=L&&R<=y) {
		ll d=min(abs(TX-X[R-1]),abs(TX-X[L]));
		if(order==0) E[cur].push_back({id,d});
		else E[id].push_back({cur,d});
		return;
	}
	int M=(L+R)/2;
	dfs(tid,lv-1,L,M,x,y,id,order,TX);
	dfs(tid,lv-1,M,R,x,y,id,order,TX);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,1<<DI) X[i]=1LL<<60;
	FOR(i,N) cin>>X[i];
	//‰º‘¤2’Ê‚è
	FOR(j,1<<DI) {
		E[j].push_back({j+(1<<DI2),0LL});
		E[j].push_back({j+(2<<DI2),0LL});
		E[j+(3<<DI2)].push_back({j,0LL});
		E[j+(4<<DI2)].push_back({j,0LL});
	}
	
	int len=1<<DI;
	int cur=0;
	FOR(i,DI+1) {
		FOR(j,4) {
			LV[i][j]=cur+((j+1)<<DI2);
		}
		FOR(j,len/2) {
			E[(1<<DI2)+cur+j*2+0].push_back({(1<<DI2)+cur+len+j,X[((j*2+2)<<i)-1]-X[((j*2+1)<<i)-1]});
			E[(1<<DI2)+cur+j*2+1].push_back({(1<<DI2)+cur+len+j,0});
			E[(2<<DI2)+cur+j*2+0].push_back({(2<<DI2)+cur+len+j,0});
			E[(2<<DI2)+cur+j*2+1].push_back({(2<<DI2)+cur+len+j,X[(j*2+1)<<i]-X[(j*2)<<i]});
			E[(3<<DI2)+cur+len+j].push_back({(3<<DI2)+cur+j*2+0,0});
			E[(3<<DI2)+cur+len+j].push_back({(3<<DI2)+cur+j*2+1,X[(j*2+1)<<i]-X[(j*2)<<i]});
			E[(4<<DI2)+cur+len+j].push_back({(4<<DI2)+cur+j*2+0,X[((j*2+2)<<i)-1]-X[((j*2+1)<<i)-1]});
			E[(4<<DI2)+cur+len+j].push_back({(4<<DI2)+cur+j*2+1,0});
		}
		cur+=len;
		len/=2;
	}
	
	int id=5<<(DI2);
	FOR(i,M) {
		cin>>L1[i]>>R1[i]>>L2[i]>>R2[i]>>C[i];
		L1[i]--,L2[i]--,R1[i]--,R2[i]--;
		if(R1[i]<=L2[i]) {
			dfs(0,DI,0,1<<DI,L1[i],R1[i]+1,id,0,X[L2[i]]);
			dfs(2,DI,0,1<<DI,L2[i],R2[i]+1,id+1,1,X[L2[i]]);
		}
		else {
			dfs(1,DI,0,1<<DI,L1[i],R1[i]+1,id,0,X[R2[i]]);
			dfs(3,DI,0,1<<DI,L2[i],R2[i]+1,id+1,1,X[R2[i]]);
		}
		E[id].push_back({id+1,C[i]});
		id+=2;
	}
	priority_queue<pair<ll,int>> Q;
	FOR(i,id) dp[i]=1LL<<60;
	dp[0]=0;
	Q.push({-dp[0],0});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(dp[cur]!=co) continue;
		FORR2(e,c,E[cur]) if(chmin(dp[e],co+c)) Q.push({-dp[e],e});
	}
	FOR(i,N-1) {
		if(dp[i+1]>=1LL<<60) dp[i+1]=-1;
		cout<<dp[i+1]<<" ";
	}
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
