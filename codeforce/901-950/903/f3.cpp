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

int T,N,K;
set<int> E[202020];
int C[202020];

pair<int,int> farthest(int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(e,cur,d+1,D));
	return r;
}

int diameter(int v) { // diameter,center
	vector<int> D[2];
	D[0].resize(N);
	D[1].resize(N);
	auto v1=farthest(v,v,0,D[0]);
	auto v2=farthest(v1.second,v1.second,0,D[0]);
	return v2.first;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) {
			E[i].clear();
			C[i]=0;
		}
		FOR(i,K) {
			cin>>x;
			C[x-1]=10101010;
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].insert(y-1);
			E[y-1].insert(x-1);
			C[x-1]++;
			C[y-1]++;
		}
		queue<int> Q;
		FOR(i,N) if(C[i]==1) Q.push(i);
		while(Q.size()) {
			x=Q.front();
			C[x]--;
			Q.pop();
			FORR(e,E[x]) {
				E[e].erase(x);
				C[e]--;
				if(C[e]==1) Q.push(e);
			}
			E[x].clear();
		}
		int ma=0;
		FOR(i,N) if(C[i]) {
			ma=diameter(i);
			break;
		}
		cout<<(ma+1)/2<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
