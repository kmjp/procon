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
int A[202020];
int P,Q;
int X[202020],Y[202020];

template<typename ST=vector<int>>
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


vector<int> Zalgo(vector<int> s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}

int cand1[202020];
int cand2[202020];
vector<int> E[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	cin>>P;
	FOR(i,P) cin>>X[i];
	cin>>Q;
	FOR(i,Q) cin>>Y[i];
	
	vector<int> B;
	FOR(i,P) B.push_back(X[i]);
	B.push_back(1<<30);
	FOR(i,Q) B.push_back(Y[i]);
	
	int ret=1<<30;
	SuffixArray sa(B);
	
	FOR(i,B.size()-1) {
		if(sa.sa[i]<P&&sa.sa[i+1]>=P+1&&sa.lcp[i]) {
			ret=min(ret,P+Q-2*sa.lcp[i]);
		}
		if(sa.sa[i+1]<P&&sa.sa[i]>=P+1&&sa.lcp[i]) {
			ret=min(ret,P+Q-2*sa.lcp[i]);
		}
	}
	if(ret==1<<30) {
		FOR(i,N+1) cand1[i]=cand2[i]=1<<25;
		
		vector<int> B;
		FOR(i,P) B.push_back(X[i]);
		B.push_back(-1);
		FOR(i,N) B.push_back(A[i]);
		
		vector<int> Z=Zalgo(B);
		vector<int> Xc,Yc;
		FOR(i,N) if(Z[P+1+i]==P) Xc.push_back(i);
		
		B.clear();
		FOR(i,Q) B.push_back(Y[i]);
		B.push_back(-1);
		FOR(i,N) B.push_back(A[i]);
		Z=Zalgo(B);
		FOR(i,N) if(Z[Q+1+i]==Q) Yc.push_back(i);
		
		FOR(i,N) {
			x=lower_bound(ALL(Xc),i)-Xc.begin();
			if(x<Xc.size()) {
				cand1[A[i]]=min(cand1[A[i]],abs(Xc[x]-i)+abs(Xc[x]+P-(i+1)));
			}
			if(x) {
				x--;
				cand1[A[i]]=min(cand1[A[i]],abs(Xc[x]-i)+abs(Xc[x]+P-(i+1)));
			}
			
			y=lower_bound(ALL(Yc),i)-Yc.begin();
			if(y<Yc.size()) {
				cand2[A[i]]=min(cand2[A[i]],abs(Yc[y]-i)+abs(Yc[y]+Q-(i+1)));
			}
			if(y) {
				y--;
				cand2[A[i]]=min(cand2[A[i]],abs(Yc[y]-i)+abs(Yc[y]+Q-(i+1)));
			}
		}
		FOR(i,N-1) {
			E[A[i]].push_back(A[i+1]);
			E[A[i+1]].push_back(A[i]);
		}
		priority_queue<pair<int,int>> QQ;
		FOR(i,N+1) QQ.push({-cand1[i],i});
		while(QQ.size()) {
			int co=-QQ.top().first;
			int cur=QQ.top().second;
			QQ.pop();
			if(cand1[cur]!=co) continue;
			FORR(e,E[cur]) if(cand1[e]>cand1[cur]+2) {
				cand1[e]=cand1[cur]+2;
				QQ.push({-cand1[e],e});
			}
		}
		
		FOR(i,N+1) {
			ret=min(ret,cand1[i]+cand2[i]);
		}
	}
	
	
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
