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
int H,W;
int X[202020],Y[202020];

vector<vector<int>> R;
vector<pair<int,int>> add[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {

		cin>>H>>W;
		map<int,int> Xs,Ys;
		FOR(i,H) {
			cin>>Y[i];
			Ys[Y[i]]=i;
		}
		FOR(i,W) {
			cin>>X[i];
			Xs[X[i]]=i;
		}
		if(Ys.size()!=H||Xs.size()!=W) {
			cout<<"No"<<endl;
			continue;
		}
		FOR(i,H*W) add[i+1].clear();
		R.resize(H);
		FOR(i,H) {
			R[i].resize(W);
		}
		FOR(y,H) FOR(x,W) add[min(Y[y],X[x])].push_back({y,x});
		set<pair<int,int>> XC,YC;
		for(i=H*W;i>=1;i--) {
			FORR2(y,x,add[i]) {
				XC.insert({x,y});
				YC.insert({y,x});
			}
			if(XC.empty()) break;
			if(Xs.count(i)&&Ys.count(i)) {
				y=Ys[i];
				x=Xs[i];
			}
			else if(Xs.count(i)) {
				auto it=XC.lower_bound({Xs[i],0});
				y=it->second;
				x=it->first;
			}
			else if(Ys.count(i)) {
				auto it=YC.lower_bound({Ys[i],0});
				x=it->second;
				y=it->first;
			}
			else {
				auto it=YC.begin();
				x=it->second;
				y=it->first;
			}
			R[y][x]=i;
			XC.erase({x,y});
			YC.erase({y,x});
		}
		
		if(i>=1) {
			cout<<"No"<<endl;
			continue;
		}
		FOR(y,H) {
			int ma=0;
			FOR(x,W) ma=max(ma,R[y][x]);
			if(ma!=Y[y]) break;
		}
		if(y!=H) {
			cout<<"No"<<endl;
			continue;
		}
		FOR(x,W) {
			int ma=0;
			FOR(y,H) ma=max(ma,R[y][x]);
			if(ma!=X[x]) break;
		}
		if(x!=W) {
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
		FOR(y,H) {
			FOR(x,W) cout<<R[y][x]<<" ";
			cout<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
