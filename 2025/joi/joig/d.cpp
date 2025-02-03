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
int id[505050];
int nex1[505050],nex2[505050];

int vis[505050];

vector<vector<int>> ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		if(nex1[x]==y||nex2[x]==y) {
			hoge:
			int px=nex1[x]+nex2[x]-y;
			int py=nex1[y]+nex2[y]-x;
			if(nex1[x]==y) nex2[x]=py;
			else nex1[x]=py;
			if(nex1[y]==x) nex2[y]=px;
			else nex1[y]=px;
			if(nex1[py]==y) nex1[py]=x;
			else nex2[py]=x;
			if(nex1[px]==x) nex1[px]=y;
			else nex2[px]=y;
		}
		else if((nex1[x]==0||nex2[x]==0)&&(nex1[y]==0||nex2[y]==0)) {
			if(nex1[x]==0) nex1[x]=y;
			else nex2[x]=y;
			if(nex1[y]==0) nex1[y]=x;
			else nex2[y]=x;
			goto hoge;
		}
		else {
			cout<<"No"<<endl;
			return;
		}
	}

	for(i=1;i<=N;i++) if(vis[i]==0&&(nex1[i]==0||nex2[i]==0)) {
		vector<int> p={i};
		vis[i]=1;
		if(nex1[i]==0&&nex2[i]==0) {
			ret.push_back(p);
		}
		else {
			p.push_back(nex1[i]+nex2[i]);
			vis[p.back()]=1;
			while(1) {
				x=nex1[p.back()];
				if(x==p[p.size()-2]) x=nex2[p.back()];
				if(x==0) break;
				vis[x]=1;
				p.push_back(x);
			}
			
			if(p[0]>p.back()) reverse(ALL(p));
			ret.push_back(p);
		}
	}
	for(i=1;i<=N;i++) if(vis[i]==0) {
		cout<<"No"<<endl;
		return;
	}
	sort(ALL(ret));
	cout<<"Yes"<<endl;
	FORR(a,ret) FORR(p,a) cout<<p<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
