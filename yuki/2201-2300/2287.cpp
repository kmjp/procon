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
ll X,Y,A;

ll V[61];

ll D[61][2];
priority_queue<pair<ll,int>> Q;

void update(int tar,int add,ll v) {
	if(D[tar][add]>v) {
		D[tar][add]=v;
		Q.push({-v,tar*2+add});
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>X>>Y>>A;
		
		V[0]=Y;
		int N=0;
		while(V[N]) {
			V[N+1]=V[N]/A;
			N++;
		}
		FOR(i,N+1) D[i][0]=D[i][1]=1LL<<60;
		x=0;
		while(1) {
			FOR(i,N+1) {
				D[i][0]=min(D[i][0],x+abs(V[i]-X));
				D[i][1]=min(D[i][1],x+abs(V[i]+1-X));
			}
			if(X==0) break;
			X/=A;
			x++;
		}
		while(Q.size()) Q.pop();
		FOR(i,N+1) {
			Q.push({-D[i][0],i*2});
			Q.push({-D[i][1],i*2+1});
		}
		while(Q.size()) {
			int cur=Q.top().second/2;
			int add=Q.top().second%2;
			ll co=-Q.top().first;
			Q.pop();
			if(D[cur][add]!=co) continue;
			if(add==0) {
				if(cur) update(cur-1,0,co+1+V[cur-1]-V[cur]*A);
				update(cur,1,co+1);
			}
			else {
				if(cur) update(cur-1,1,co+1+abs(V[cur-1]+1-(V[cur]+1)*A));
				if(cur>=2) update(cur-2,0,co+1+abs(V[cur-2]-(V[cur]+1)*A));
				
				if(cur) update(cur-1,0,co+abs(V[cur-1]-(V[cur]+1)));
				update(cur,0,co+1);
			}
		}
		cout<<D[0][0]<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
