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
ll M;
string S[201010],G;
int TL[201010];
ll LS[201010];
pair<int,int> re[201010];

ll X[202020];
int ret[202020][3];
int nex;
ll did;

template<typename ST=string>
struct SuffixArray {
	int N; vector<int> rank,lcp,sa,rsa; ST S;
 
	void build(ST S){
		this->S=S;
		int i,h=0; vector<int> tmp;
		N=S.size(); rank.resize(N+1); sa.resize(N+1); tmp.resize(N+1);
		FOR(i,N+1) sa[i]=i, rank[i]=i==N?-1:S[i];
		
		for(int k=1; k<=N; k<<=1) {
			auto pred2 = [k,this](int& a,int &b)->bool{ return (((a+k<=N)?rank[a+k]:-1)<((b+k<=N)?rank[b+k]:-1));};
			auto pred = [pred2,k,this](int& a,int &b)->bool{ return (rank[a]!=rank[b])?(rank[a]<rank[b]):pred2(a,b);};
			int x=0;
			if(k!=1) for(i=1;i<N+1;i++) if(rank[sa[i]]!=rank[sa[x]]) sort(sa.begin()+x,sa.begin()+i,pred2), x=i;
			sort(sa.begin()+x,sa.end(),pred);
			FOR(i,N+1) tmp[sa[i]]=(i==0)?0:tmp[sa[i-1]]+pred(sa[i-1],sa[i]);
			swap(rank,tmp);
		}
		lcp.resize(N+1); rsa.resize(N+1);
		FOR(i,N+1) rsa[sa[i]]=i;
		FOR(i,N) {
			int j=sa[rsa[i]-1];
			for(h=max(h-1,0);i+h<N && j+h<N; h++) if(S[j+h]!=S[i+h]) break;
			lcp[rsa[i]-1]=h;
		}
	}
};
SuffixArray sa;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll sum=0;
	FOR(i,N) {
		cin>>S[i];
		FOR(j,S[i].size()) {
			TL[G.size()+j]=S[i].size()-j;
			re[G.size()+j]={i+1,j+1};
			sum+=j+1;
		}
		G+=S[i]+"$";
	}
	
	sa.build(G);
	int Q;
	cin>>Q;
	FOR(i,Q) cin>>X[i];
	int cur=Q-1;
	
	vector<pair<int,int>> Rs={{0,0}};
	for(i=G.size();i>=0;i--) {
		while(Rs.back().first>sa.lcp[i]) {
			x=Rs.back().first;
			y=Rs.back().second;
			Rs.pop_back();
			k=max(Rs.back().first,sa.lcp[i]);
			sum-=1LL*(x-k)*(y-i);
			while(cur>=0&&X[cur]>sum) {
				ret[cur][0]=re[sa.sa[i+1]].first;
				ret[cur][1]=re[sa.sa[i+1]].second;
				ret[cur][2]=re[sa.sa[i+1]].second+k+(X[cur]-sum-1)/(y-i);
				cur--;
			}
			if(Rs.back().first<sa.lcp[i]) {
				Rs.push_back({sa.lcp[i],y});
			}
		}
		if(Rs.back().first<TL[sa.sa[i]]) Rs.push_back({TL[sa.sa[i]],i});
	}
	FOR(i,Q) cout<<ret[i][0]<<" "<<ret[i][1]<<" "<<ret[i][2]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
