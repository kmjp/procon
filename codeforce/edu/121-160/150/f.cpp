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
int A[303030],B[303030],C[303030],D[303030];
pair<double,pair<ll,ll>> P[606060];

ostream& operator<<(ostream& os, __int128 v) {
	if(v==0) {
		return (os<<'0');
	}
	if(v<0) {
		os<<'-';
		v=-v;
	}
	
	string T;
	while(v) {
		T+=(char)('0'+(v%10));
		v/=10;
	}
	reverse(ALL(T));
	return (os<<T);
}

bool cmp(pair<ll,ll> a,pair<ll,ll> b) {
	return a.first*b.second-a.second*b.first<0;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	__int128 SX=0,SY=0;
	FOR(i,N) {
		scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);
		P[i*2].second={A[i]-B[i],C[i]-D[i]};
		if(P[i*2].second.first==0&&P[i*2].second.second==0) {
			i--;
			N--;
			continue;
		}
		P[i*2+1].second={-A[i]+B[i],-C[i]+D[i]};
		P[i*2].first=atan2(P[i*2].second.second,P[i*2].second.first);
		P[i*2+1].first=atan2(P[i*2+1].second.second,P[i*2+1].second.first);
		if(P[i*2+1].first<P[i*2].first) {
			SX+=P[i*2].second.first;
			SY+=P[i*2].second.second;
		}
	}
	
	__int128 ma=SX*SX+SY*SY;
	sort(P,P+2*N);
	FOR(i,2*N) {
		SX+=P[i].second.first;
		SY+=P[i].second.second;
		ma=max(ma,SX*SX+SY*SY);
	}
	
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
