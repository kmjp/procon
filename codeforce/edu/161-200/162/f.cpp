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

int N,K;
string S,A,B;
set<int> C;
const ll mo=1000000007;

int len[505050];

template<typename ST=string>
struct SuffixArray {
	int N; vector<int> rank,lcp,sa,rsa; ST S;

	void build(ST S){
		this->S=S;
	}
	
	SuffixArray(ST S) : S(S){
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


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	int cnt=0;
	FOR(i,N) {
		S[i]-='0';
		if(S[i]) cnt++,C.insert(i);
	}
	if(C.size()<=K) {
		ll ret=0;
		FOR(i,C.size()) ret=(ret*2+1)%mo;
		cout<<ret<<endl;
		return;
	}
	A=S;
	int lef=K;
	for(i=N-1;i>=0;i--) if(lef&&A[i]==0) {
		if(C.size()&&*C.begin()<i) {
			A[i]=1;
			A[*C.begin()]=0;
			C.erase(C.begin());
			lef--;
		}
	}
	reverse(ALL(A));
	while(A.back()==0) A.pop_back();
	reverse(ALL(A));
	
	reverse(ALL(S));
	int n1=0;
	int mi=N+1;
	for(int L=0,R=0;L<N;L++) {
		while(R<N&&n1+(K-1)<cnt) n1+=S[R++];
		if(n1+(K-1)<cnt) len[L]=N+1;
		else len[L]=R-L;
		if(S[L]==1) n1--;
		mi=min(mi,len[L]);
	}
	SuffixArray sa(S);
	B=S;
	FOR(i,N+1) if(len[sa.sa[i]]==mi) {
		B=S.substr(sa.sa[i],mi);
		int lef=K-1;
		for(i=B.size()-1;i>=0;i--) if(lef&&B[i]==0) lef--,B[i]=1;
		while(lef--) B+=(char)1;
		break;
	}
	
	if(A.size()>B.size()) A=B;
	else if(A.size()==B.size()&&A>B) A=B;
	
	ll ret=0;
	FORR(a,A) ret=(ret*2+a)%mo;
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
