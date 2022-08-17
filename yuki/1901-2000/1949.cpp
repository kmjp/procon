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

int H,W,Y,X;
ll A[555][555];

priority_queue<pair<int,int>> Q;
void add(int y,int x) {
	int dd[4]={0,1,0,-1};
	int i;
	FOR(i,4) {
		int ty=y+dd[i];
		int tx=x+dd[i^1];
		if(ty<0||ty>=H||tx<0||tx>=W) continue;
		if(A[ty][tx]==0) continue;
		Q.push({-A[ty][tx],ty*1000+tx});
		A[ty][tx]=0;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Y>>X;
	Y--,X--;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	
	ll cur=A[Y][X];
	A[Y][X]=0;
	add(Y,X);
	int sum=1;
	while(Q.size()) {
		if(-Q.top().first>=cur) break;
		sum++;
		y=Q.top().second/1000;
		x=Q.top().second%1000;
		cur+=-Q.top().first;
		Q.pop();
		add(y,x);
	}
	if(sum<H*W) {
		cout<<"No"<<endl;
	}
	else {
		cout<<"Yes"<<endl;
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
