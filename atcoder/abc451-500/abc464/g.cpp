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
string S;

int L[1<<20],R[1<<20],alive[1<<20];
int ret[1202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		int pre=0;
		vector<int> V,D;
		int sum=0;
		FORR(c,S) {
			x=c=='R';
			V.push_back(pre^x);
			sum+=pre^x;
			pre=x;
		}
		if(sum%2)  V.push_back(0);
		pre=-1;
		D.push_back(1<<26);
		D.push_back(1<<26);
		FOR(i,V.size()) if(V[i]==0) {
			if(pre!=-1) {
				D.push_back(i-pre);
			}
			pre=i;
		}
		D.push_back(1<<26);
		D.push_back(1<<26);
		
		
		int DS=D.size();
		priority_queue<pair<int,int>> Q;
		FOR(i,DS) {
			L[i]=i-1;
			R[i]=i+1;
			alive[i]=1;
			if(D[i]<=N+2) Q.push({-D[i],i});
		}
		map<int,int> M;
		int cost=0;
		M[sum/2]=0;
		while(sum<N/2*2) {
			auto p=Q.top();
			Q.pop();
			x=p.second;
			if(alive[x]==0) continue;
			if(D[x]>N+2) break;
			cost+=D[x];
			sum+=2;
			M[sum/2]=cost;
			int LL=L[x];
			int RR=R[x];
			D[x]=D[LL]-D[x]+D[RR];
			alive[LL]=0;
			alive[RR]=0;
			R[x]=R[RR];
			L[x]=L[LL];
			R[L[x]]=x;
			L[R[x]]=x;
			Q.push({-D[x],x});
		}
		FOR(i,N+1) ret[i]=0;
		FORR2(a,b,M) ret[b]=max(ret[b],a);
		FOR(i,N+1) {
			cout<<ret[i]<<" ";
			ret[i+1]=max(ret[i],ret[i+1]);
		}
		cout<<endl;
		
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
