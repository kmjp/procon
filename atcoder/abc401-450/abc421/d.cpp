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

ll X[2],Y[2];
ll N,M,L;
deque<pair<char,ll>> D[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,2) {
		cin>>Y[i]>>X[i];
	}
	ll DX=X[0]-X[1];
	ll DY=Y[0]-Y[1];
	
	if((abs(DX)+abs(DY))%2) {
		cout<<0<<endl;
		return;
	}
	
	cin>>N>>M>>L;
	FOR(i,M) {
		ll a;
		cin>>s>>a;
		D[0].push_back({s[0],a});
	}
	FOR(i,L) {
		ll a;
		cin>>s>>a;
		D[1].push_back({s[0],a});
	}
	ll ret=0;
	while(D[0].size()) {
		if(D[0][0].second==0) {
			D[0].pop_front();
			continue;
		}
		if(D[1][0].second==0) {
			D[1].pop_front();
			continue;
		}
		ll mi=min(D[0][0].second,D[1][0].second);
		D[0][0].second-=mi;
		D[1][0].second-=mi;
		char a=D[0][0].first;
		char b=D[1][0].first;
		if(a==b) {
			if(DX==0&&DY==0) ret+=mi;
		}
		else {
			if(a=='L') {
				if(b=='R') {
					if(DY==0&&DX>0&&DX-mi*2<=0) ret++;
					DX-=mi*2;
				}
				if(b=='D') {
					if(DX==DY&&DX>0&&DX-mi<=0) ret++;
					DX-=mi;
					DY-=mi;
				}
				if(b=='U') {
					if(DX==-DY&&DX>0&&DX-mi<=0) ret++;
					DX-=mi;
					DY+=mi;
				}
			}
			if(a=='R') {
				if(b=='L') {
					if(DY==0&&DX<0&&DX+mi*2>=0) ret++;
					DX+=mi*2;
				}
				if(b=='D') {
					if(DX==-DY&&DX<0&&DX+mi>=0) ret++;
					DX+=mi;
					DY-=mi;
				}
				if(b=='U') {
					if(DX==DY&&DX<0&&DX+mi>=0) ret++;
					DX+=mi;
					DY+=mi;
				}
			}
			if(a=='D') {
				if(b=='U') {
					if(DX==0&&DY<0&&DY+mi*2>=0) ret++;
					DY+=mi*2;
				}
				if(b=='L') {
					if(DX==DY&&DY<0&&DY+mi>=0) ret++;
					DX+=mi;
					DY+=mi;
				}
				if(b=='R') {
					if(-DX==DY&&DY<0&&DY+mi>=0) ret++;
					DX-=mi;
					DY+=mi;
				}
			}
			if(a=='U') {
				if(b=='D') {
					if(DX==0&&DY>0&&DY-mi*2<=0) ret++;
					DY-=mi*2;
				}
				if(b=='L') {
					if(DX==-DY&&DY>0&&DY-mi<=0) ret++;
					DX+=mi;
					DY-=mi;
				}
				if(b=='R') {
					if(DX==DY&&DY>0&&DY-mi<=0) ret++;
					DX-=mi;
					DY-=mi;
				}
			}
			
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
