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
int L[2020200],R[2020202];

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {par=rank=vector<int>(um,0); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<4020202> uf;

int HL[2020202],HR[2020202],con[2020202],avail[2020202];
int ev[2020202];
int nex[2020202],pre[2020202];
set<int> S;
deque<pair<int,int>> V;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	FOR(k,T) {
		cin>>N;
		uf.reinit(2*N);
		S.clear();
		V.clear();
		FOR(i,N) {
			cin>>L[i]>>R[i];
			HL[i]=HR[i]=con[i]=0;
			ev[i]=-1;
		}
		FOR(i,N) {
			int SL=max(0,i-R[i]);
			int SR=i-L[i];
			if(SL<=SR) {
				HL[SL]++;
				HL[SR+1]--;
				chmax(ev[SL],SR);
			}
			SL=i+L[i];
			SR=min(N-1,i+R[i]);
			if(SL<=SR) {
				HR[SL]++;
				HR[SR+1]--;
				chmax(ev[SL],SR);
			}
		}
		FOR(i,N) {
			if(i) HL[i]+=HL[i-1],HR[i]+=HR[i-1];
			avail[i]=(HL[i]>0)&&(HR[i]>0);
			if(avail[i]) {
				pre[i]=i;
			}
			else if(i==0) {
				pre[i]=-1;
			}
			else {
				pre[i]=pre[i-1];
			}
		}
		for(i=N-1;i>=0;i--) {
			if(avail[i]) {
				nex[i]=i;
			}
			else if(i==N-1) {
				nex[i]=N;
			}
			else {
				nex[i]=nex[i+1];
			}
		}
		FOR(i,N) {
			if(ev[i]>=0) V.push_back({i,ev[i]});
			while(V.size()&&V.front().second<i) V.pop_front();
			if(avail[i]&&V.size()) uf(N+i,N+nex[V[0].first]);
		}
		FOR(i,N) {
			int SL=nex[max(0,i-R[i])];
			int SR=(i-L[i]<0)?-1:pre[i-L[i]];
			if(SL<=SR) uf(i,N+SL);
			
			SL=(i+L[i]<N)?nex[i+L[i]]:N;
			SR=pre[min(N-1,i+R[i])];
			if(SL<=SR) uf(i,N+SL);
		}
		int ret=0;
		FOR(i,N) {
			if(uf[i]==i) ret++;
			if(avail[i]&&uf[N+i]==N+i) ret++;
		}
		
			cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
