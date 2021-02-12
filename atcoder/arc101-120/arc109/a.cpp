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

int A,B,X,Y;

int D[2][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>X>>Y;
	
	FOR(i,101) D[0][i]=D[1][i]=1<<30;
	D[0][A]=0;
	priority_queue<pair<int,int>> Q;
	Q.push({0,A});
	while(Q.size()) {
		int co=-Q.top().first;
		int id=Q.top().second/1000;
		int cur=Q.top().second%1000;
		Q.pop();
		if(D[id][cur]!=co) continue;
		
		if(id==1&&cur==B) {
			cout<<co<<endl;
			return;
		}
		if(cur>1 && D[id][cur-1]>co+Y) {
			D[id][cur-1]=co+Y;
			Q.push({-D[id][cur-1],id*1000+cur-1});
		}
		if(cur<100 && D[id][cur+1]>co+Y) {
			D[id][cur+1]=co+Y;
			Q.push({-D[id][cur+1],id*1000+cur+1});
		}
		if(D[id^1][cur]>co+X) {
			D[id^1][cur]=co+X;
			Q.push({-D[id^1][cur],(id^1)*1000+cur});
		}
		if(id==0&&cur>1&&D[1][cur-1]>co+X) {
			D[1][cur-1]=co+X;
			Q.push({-D[1][cur-1],1000+cur-1});
		}
		if(id==1&&cur<100&&D[0][cur+1]>co+X) {
			D[0][cur+1]=co+X;
			Q.push({-D[0][cur+1],cur+1});
		}
		
		
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
