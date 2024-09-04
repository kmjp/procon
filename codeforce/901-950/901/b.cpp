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

int T;
int A,B,C,D,M;
map<pair<int,int>,int> X;
queue<pair<int,int>> Q;

int dp[1<<14];
int mi[5*5*5*5*5*5*5];

int build(int X,int Y) {
	int mask=0;
	int i;
	FOR(i,7) {
		if(X&(1<<i)) mask|=1<<(i*2);
		if(Y&(1<<i)) mask|=1<<(i*2+1);
	}
	return mask;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int mask;
	FOR(mask,1<<14) dp[mask]=1<<20;
	FOR(mask,5*5*5*5*5*5*5) mi[mask]=1<<20;
	int key=0;
	FOR(i,7) key|=((i+1)%4)<<(i*2);
	dp[key]=0;
	queue<int> Q;
	Q.push(key);
	int step=0;
	while(Q.size()) {
		key=Q.front();
		Q.pop();
		step++;
		FOR(mask,1<<7) {
			int v=0,a=1;
			FOR(i,7) {
				if(mask&(1<<i)) {
					v+=4*a;
				}
				else {
					v+=((key>>(i*2))%4)*a;
				}
				a*=5;
			}
			mi[v]=min(mi[v],dp[key]);
		}
		int X=0,Y=0;
		FOR(i,7) X|=((key>>(i*2))%2)<<i;
		FOR(i,7) Y|=((key>>(i*2+1))%2)<<i;
		vector<pair<int,int>> cand={{X&Y,Y},{X|Y,Y},{X,X^Y},{X,Y^(15<<3)}};
		FORR2(aa,bb,cand) {
			int mask=build(aa,bb);
			if(dp[mask]==1<<20) {
				dp[mask]=dp[key]+1;
				Q.push(mask);
			}
		}
	}
	cout<<step<<endl;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>C>>D>>M;
		int V[7]={4,4,4,4,4,4,4};
		FOR(i,30) {
			int a=(A>>i)%2;
			int b=(B>>i)%2;
			int c=(C>>i)%2;
			int d=(D>>i)%2;
			int m=(M>>i)%2;
			if(a==0&&b==0&&m==0) {
				if(c||d) break;
				continue;
			}
			int key=(a+b*2+m*4)-1;
			int tar=c+d*2;
			if(V[key]==4) V[key]=tar;
			if(V[key]!=tar) break;
		}
		if(i<30) {
			cout<<-1<<endl;
			continue;
		}
		key=0;
		x=1;
		FOR(i,7) {
			key+=V[i]*x;
			x*=5;
		}
		int ret=mi[key];
		if(ret==1<<20) ret=-1;
		cout<<ret<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
