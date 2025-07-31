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

int T,N;
int L[202020],R[202020];
int TL[202020],TR[202020];
ll A[402020];

int ok(int dy) {
	int i,y;
	
	ll cur=0;
	for(i=0;i<=N;i+=dy) {
		if(cur>A[i+dy]-A[i]) return 0;
		cur=A[i+dy]-A[i]-cur;
	}
	if(cur) return 0;
	
	FOR(i,N) TL[i]=L[i],TR[i]=R[i];
	int dx=TL[dy]-TL[0];
	
	int preL=-1,preR=-1;
	for(y=0;y+dy<N;y++) {
		if(y) {
			if(TL[y]>=preR) return 0;
			if(TR[y]<=preL) return 0;
		}
		
		if(TR[y]-TL[y]<=0) return 0;
		if(TR[y]-TL[y]>TR[y+dy]-TL[y+dy]) return 0;
		if(TL[y]+dx==TL[y+dy]) {
			TL[y+dy]+=TR[y]-TL[y];
		}
		else if(TR[y]+dx==TR[y+dy]) {
			TR[y+dy]-=TR[y]-TL[y];
		}
		else {
			return 0;
		}
		preR=TR[y];
		preL=TL[y];
	}
	for(y=N-dy;y<N;y++) if(TR[y]!=TL[y]) return 0;
	return 1;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	FOR(r,T) {
		cin>>N;
		FOR(i,N) {
			cin>>L[i]>>R[i];
			L[i]--;
		}
		
		
		//‰¡‚É•ªŠ„
		if((R[0]-L[0])%2==0) {
			FOR(y,N-1) {
				if(R[y+1]-L[y+1]!=R[0]-L[0]) break;
				if(abs(R[y]-R[y+1])>=(R[0]-L[0])/2) break;
			}
			if(y==N-1) {
				cout<<"YES"<<endl;
				continue;
			}
		}

		FOR(k,2) {
			
			FOR(i,N) A[i+1]=A[i]+R[i]-L[i];
			FOR(i,N) A[N+i+1]=A[N+i];
			for(i=1;i<=N/2;i++) if(ok(i)) break;
			if(i<=N/2) break;
			
			
			reverse(L,L+N);
			reverse(R,R+N);
			
		}
		
		if(k==2) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
