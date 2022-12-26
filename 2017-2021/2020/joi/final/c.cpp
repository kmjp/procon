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
ll M;
ll X[202],T[202];

ll dp[202][202][2][202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>X[i+1];
	}
	X[N+1]=M;
	FOR(i,N) cin>>T[i+1];
	FOR(x,N+2) FOR(y,N+2) FOR(r,N+2) dp[x][y][0][r]=dp[x][y][1][r]=1LL<<60;
	priority_queue<pair<ll,int>> Q;
	dp[N+1][0][0][0]=0;
	Q.push({0,(N+1)*300*300*2});
	int ma=0;
	while(Q.size()) {
		ll co=-Q.top().first;
		int L=Q.top().second/(300*300*2);
		int R=Q.top().second/(300*2)%300;
		int now=Q.top().second/300%2;
		int num=Q.top().second%300;
		ma=max(ma,num);
		Q.pop();
		if(dp[L][R][now][num]!=co) continue;
		if(R+1==L) continue;
		// go left
		ll tim=co+((now==0)?(X[L]-X[L-1]):(X[R]+(M-X[L-1])));
		int num2=num+(tim<=T[L-1]);
		if(dp[L-1][R][0][num2]>tim) {
			dp[L-1][R][0][num2]=tim;
			Q.push({-tim,(L-1)*300*300*2+R*300*2+0*300+num2});
		}
		tim=co+((now==0)?(X[R+1]+M-X[L]):(X[R+1]-X[R]));
		num2=num+(tim<=T[R+1]);
		if(dp[L][R+1][1][num2]>tim) {
			dp[L][R+1][1][num2]=tim;
			Q.push({-tim,L*300*300*2+(R+1)*300*2+1*300+num2});
		}
		
		
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
