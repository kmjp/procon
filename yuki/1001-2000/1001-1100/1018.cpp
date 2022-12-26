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

ll N,M,Q;
string S;
int per;

template<typename ST=string>
struct SuffixArray {
	int N; vector<int> rank,lcp,sa,rsa; ST S;

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
	
	cin>>N>>M>>Q>>S;
	for(i=1;i<N;i++) if(N%i==0) {
		FOR(j,N) if(j>=i && S[j-i]!=S[j]) break;
		if(j==N) {
			S=S.substr(0,i);
			M*=N/i;
			N=i;
			
			break;
		}
	}
	
	if(M==1) {
		SuffixArray sa(S);
		FOR(i,Q) {
			cin>>x;
			cout<<1+sa.sa[x]<<" ";
		}
		cout<<endl;
		return;
	}
	
	SuffixArray sa(S+S);
	vector<vector<ll>> V;
	ll pos=0;
	FOR(i,2*N) {
		if(sa.sa[i+1]>=N) {
			V.push_back({pos,1LL*(M-1)*N+sa.sa[i+1]-N,1});
		}
		else {
			V.push_back({pos,sa.sa[i+1],M-1});
		}
		pos+=V.back()[2];
	}
	
	FOR(i,Q) {
		ll v;
		cin>>v;
		v--;
		vector<ll> C={v+1,0,0};
		x=lower_bound(ALL(V),C)-V.begin();
		x--;
		cout<<(V[x][1]+1+(V[x][2]-1-(v-V[x][0]))*N)<<" ";
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
