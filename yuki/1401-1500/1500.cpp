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

int N;
const ll mo=1000000007;

int D[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(x,101) FOR(y,101) D[y][x]=101010;
	D[50][50]=0;
	queue<int> Q;
	Q.push(50*200+50);
	while(Q.size()) {
		y=Q.front()/200;
		x=Q.front()%200;
		Q.pop();
		if(D[y][x]>=15) break;
		vector<pair<int,int>> V={{0,3},{-2,3},{2,3},{0,-3},{-2,-3},{2,-3},{3,0},{3,2},{3,-2},{-3,0},{-3,2},{-3,-2}};
		FORR2(dy,dx,V) {
			if(D[y+dy][x+dx]>D[y][x]+1) {
				D[y+dy][x+dx]=D[y][x]+1;
				Q.push({(y+dy)*200+(x+dx)});
			}
		}
	}
	int C[101]={};
	FOR(y,101) {
		FOR(x,101) {
			if(D[y][x]<=15) C[D[y][x]]++;
		}
	}
	/*
	FOR(i,16) {
		cout<<i<<" "<<C[i]<<" ";
		if(i) cout<<C[i]-C[i-1];
		cout<<endl;
	}
	*/
	
	ll ret=0;
	if(N<=7) {
		for(i=N%2;i<=N;i+=2) ret+=C[i];
	}
	else if(N%2==0) {
		for(i=0;i<=8;i+=2) ret+=C[i];
		ll S=(N-8)/2;
		ll D=(C[9]-C[7]);
		(ret+=(C[8]*S + S*(S+1)/2%mo*D))%=mo;
	}
	else {
		for(i=1;i<=7;i+=2) ret+=C[i];
		ll S=(N-7)/2;
		ll D=(C[9]-C[7]);
		(ret+=(C[7]*S + S*(S+1)/2%mo*D))%=mo;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
