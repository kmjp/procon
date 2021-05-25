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


const int mo=1000000007;
string S,U;
int N;
string T[1010];
int from[10101];
int to[10101];

int did[10101];
int uid[201010];
short ma[1010][10110];


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
SuffixArray SA,SA2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>N;
	U=S+"#";
	FOR(i,S.size()+1) uid[i]=N;
	FOR(i,N) {
		cin>>T[i];
		FOR(j,T[i].size()) uid[U.size()+j]=i;
		uid[U.size()+T[i].size()]=-1;
		U+=T[i]+"$";
	}
	uid[U.size()]=N;
	
	S+="#";
	SA.build(S);
	S.pop_back();
	
	SA2.build(U);
	
	int same,take=0;
	FOR(i,U.size()) {
		x=SA2.sa[i];
		y=uid[x];
		if(y==N) {
			take++;
			same=S.size()-x;
		}
		else if(y>=0) {
			if(i) same=min(same,SA2.lcp[i-1]);
			short csame=same;
			for(j=take-1;j>=did[y];j--) {
				if(j!=take-1) csame=min(csame,(short)SA.lcp[j]);
				chmax(ma[y][SA.sa[j]],csame);
			}
			did[y]=take-1;
		}
	}
	FOR(i,N) did[i]=S.size()+2;
	take=S.size()+2;
	for(i=U.size();i>=0;i--) {
		x=SA2.sa[i];
		y=uid[x];
		if(y==N) {
			take--;
			same=S.size()-x;
		}
		else if(y>=0) {
			same=min(same,SA2.lcp[i]);
			short csame=same;
			for(j=take;j<did[y];j++) {
				chmax(ma[y][SA.sa[j]],csame);
				csame=min(csame,(short)SA.lcp[j]);
			}
			did[y]=take;
		}
	}
	
	
	from[0]=1;
	FOR(i,N) {
		ZERO(to);
		FOR(j,S.size()) if(from[j]) {
			(to[j+1]+=from[j])%=mo;
			(to[j+ma[i][j]+1]+=mo-from[j])%=mo;
		}
		for(j=1;j<=S.size();j++) (to[j]+=to[j-1])%=mo;
		swap(from,to);
	}
	cout<<from[S.size()]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
