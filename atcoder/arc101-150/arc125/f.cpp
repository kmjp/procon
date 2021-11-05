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
int C[202020];
int ma[202020];
int mi[202020];
deque<pair<int,int>> Dmi[202020],Dma[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		C[x-1]++;
		C[y-1]++;
	}
	map<int,int> M;
	FOR(i,N) M[C[i]-1]++;
	
	FOR(i,N+2) mi[i]=1<<30, ma[i]=-1<<30;
	mi[0]=0;
	ma[0]=M[0];
	
	int sum=0;
	FORR2(a,b,M) if(a) {
		sum+=a*b;
		FOR(i,sum+1) {
			x=i%a;
			int pmi=mi[i];
			int pma=ma[i];
			
			if(Dmi[x].size()&&(i-Dmi[x].front().first)/a>b) Dmi[x].pop_front();
			if(Dma[x].size()&&(i-Dma[x].front().first)/a>b) Dma[x].pop_front();
			if(Dmi[x].size()) mi[i]=min(mi[i],Dmi[x].front().second+(i-Dmi[x].front().first)/a);
			if(Dma[x].size()) ma[i]=max(ma[i],Dma[x].front().second+(i-Dma[x].front().first)/a);
			
			while(Dmi[x].size()&&Dmi[x].back().second+(i-Dmi[x].back().first)/a>=pmi) Dmi[x].pop_back();
			while(Dma[x].size()&&Dma[x].back().second+(i-Dma[x].back().first)/a<=pma) Dma[x].pop_back();
			Dmi[x].push_back({i,pmi});
			Dma[x].push_back({i,pma});
			
		}
		FOR(i,a) Dmi[i].clear(),Dma[i].clear();
	}
	ll ret=0;
	FOR(i,N) if(ma[i]>=mi[i]) {
		ret+=ma[i]-mi[i]+1;
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
