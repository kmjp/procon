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
string S[8];
int p3[9];
vector<int> EA[9*9*9*9],EB[9*9*9*9],R[9*9*9*9];
int in[9*9*9*9];
ll G[9*9*9*9];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p3[0]=1;
	FOR(i,8) p3[i+1]=p3[i]*3;
	int mask;
	queue<int> Q;
	FOR(mask,p3[8]) {
		int T[8];
		FOR(i,8) T[i]=mask/p3[i]%3;
		FOR(i,8) {
			if(T[i]==1) {
				EB[mask].push_back(mask-p3[i]);
				R[mask-p3[i]].push_back(mask);
				in[mask]++;
				if(i&&T[i-1]==0) {
					EA[mask].push_back(mask-p3[i]+p3[i-1]);
					R[mask-p3[i]+p3[i-1]].push_back(mask);
					in[mask]++;
				}
			}
			if(T[i]==2) {
				EA[mask].push_back(mask-2*p3[i]);
				R[mask-2*p3[i]].push_back(mask);
				in[mask]++;
				if(i&&T[i-1]==0) {
					EB[mask].push_back(mask-2*p3[i]+2*p3[i-1]);
					R[mask-2*p3[i]+2*p3[i-1]].push_back(mask);
					in[mask]++;
				}
			}
		}
		if(in[mask]==0) Q.push(mask);
	}
	
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		
		ll X=-1<<30,Y=1<<30;
		FORR(a,EA[cur]) X=max(X,G[a]);
		FORR(a,EB[cur]) Y=min(Y,G[a]);
		for(i=16;i>=0;i--) {
			int d=1<<i;
			ll XC=X/d*d-d;
			ll YC=Y/d*d+d;
			while(XC<=X) XC+=d;
			while(YC>=Y) YC-=d;
			
			if(XC>YC) continue;
			if(XC<=0&&YC>=0) {
				G[cur]=0;
			}
			else if(YC<=0) G[cur]=YC;
			else G[cur]=XC;
			break;
		}
		
		FORR(a,R[cur]) {
			in[a]--;
			if(in[a]==0) Q.push(a);
		}
	}
	
	
	
	cin>>N;
	ll sum=0;
	FOR(y,N) cin>>S[y];
	FOR(x,N) {
		mask=0;
		for(y=N-1;y>=0;y--) {
			mask*=3;
			if(S[y][x]=='W') mask++;
			if(S[y][x]=='B') mask+=2;
		}
		sum+=G[mask];
	}
	if(sum>0) cout<<"Takahashi"<<endl;
	else cout<<"Snuke"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
