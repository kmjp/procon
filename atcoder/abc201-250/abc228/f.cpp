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

int H,W,TH[2],TW[2];
ll A[1010][1010];
ll S[1010][1010];
ll X[1010][1010];
ll Y[1010][1010];
ll Y2[1010][1010];
ll Y3[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>TH[0]>>TW[0]>>TH[1]>>TW[1];
	TH[1]=min(TH[1],TH[0]);
	TW[1]=min(TW[1],TW[0]);
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		S[y+1][x+1]=S[y+1][x]+S[y][x+1]-S[y][x]+A[y][x];
	}
	MINUS(Y);
	FOR(y,H) FOR(x,W) {
		if(y+TH[0]<=H&&x+TW[0]<=W) {
			X[y][x]=S[y+TH[0]][x+TW[0]]-S[y][x+TW[0]]-S[y+TH[0]][x]+S[y][x];
		}
		if(y+TH[1]<=H&&x+TW[1]<=W) {
			Y[y][x]=S[y+TH[1]][x+TW[1]]-S[y][x+TW[1]]-S[y+TH[1]][x]+S[y][x];
		}
	}
	int DW=TW[0]-TW[1]+1;
	FOR(y,H) {
		deque<pair<int,ll>> Q;
		FOR(x,W) {
			while(Q.size()&&Q.back().second<=Y[y][x]) Q.pop_back();
			Q.push_back({x,Y[y][x]});
			while(Q.front().first<x-DW+1) Q.pop_front();
			if(x+1-DW>=0) {
				Y2[y][x+1-DW]=Q.front().second;
			}
		}
	}
	int DH=TH[0]-TH[1]+1;
	FOR(x,W) {
		deque<pair<int,ll>> Q;
		FOR(y,H) {
			while(Q.size()&&Q.back().second<=Y2[y][x]) Q.pop_back();
			Q.push_back({y,Y2[y][x]});
			while(Q.front().first<y-DH+1) Q.pop_front();
			if(y+1-DH>=0) Y3[y+1-DH][x]=Q.front().second;
		}
	}
	
	
	ll ma=0;
	FOR(y,H) FOR(x,W) if(y+TH[0]<=H&&x+TW[0]<=W) {
		ma=max(ma,X[y][x]-Y3[y][x]);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
