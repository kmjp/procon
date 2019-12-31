#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int K,N,L;
string S;

struct SuffixArray {
	int N; vector<int> rank,lcp,sa,rsa; string S;
	
	void init(string S_){
		S=S_;
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

int ok(int v) {
	int take=N%(K+1);
	int cur=0;
	
	while(cur<N && take) {
		if(cur+L+1>N) return 0;
		
		if(sa.rsa[cur]<=sa.rsa[v]) {
			cur+=L+1;
			take--;
		}
		else {
			cur+=L;
		}
	}
	
	return take==0;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>S;
	N=S.size();
	sa.init(S);
	
	L=N/(K+1);
	if(N%(K+1)==0) {
		string R="";
		FOR(i,K+1) R=max(R,S.substr(i*L,L));
		cout<<R<<endl;
		return;
	}
	vector<int> cand;
	FOR(i,N+1) if(sa.sa[i]+L+1<=N) cand.push_back(sa.sa[i]);
	
	int L2=-1,R2=cand.size()-1;
	
	while(R2-L2>=2) {
		int M=(L2+R2)/2;
		if(ok(cand[M])) R2=M;
		else L2=M;
	}
	cout<<S.substr(cand[R2],L+1)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
