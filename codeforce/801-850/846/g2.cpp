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
string S;

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

vector<int> D[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=1000000;i++) for(j=i;j<=1000000;j+=i) D[j].push_back(i);
	
	cin>>N>>S;
	sa.build(S);
	
	vector<pair<int,int>> V={{0,N+1}};
	ll sum=0;
	for(i=N;i>=0;i--) {
		x=sa.lcp[i];
		y=N-sa.sa[i];
		/*
		cout<<"%% "<<i<<" ";
		FORR2(a,b,V) cout<<a<<":"<<b<<" ";
		cout<<endl;
		*/
		while(V.back().first>x) {
			int b=V.back().first;
			int a=max(x,V[V.size()-2].first)+1;
			int l=V.back().second-i;
			//aà»è„bà»â∫
			sum+=(lower_bound(ALL(D[l]),b+1)-lower_bound(ALL(D[l]),a))*l;
			//cout<<"#"<<a<<" "<<b<<" "<<l<<" "<<(lower_bound(ALL(D[l]),b+1)-lower_bound(ALL(D[l]),a))<<endl;
			if(x>=V[V.size()-2].first) {
				V.back().first=x;
			}
			else {
				V.pop_back();
			}
		}
		while(V.size()>=2&&V.back().first<=V[V.size()-2].first) V.pop_back();
		if(V.back().first!=y) V.push_back({y,i});
		while(V.size()>=2&&V.back().first<=V[V.size()-2].first) V.pop_back();
		//cout<<x<<" "<<y<<" "<<sum<<" "<<S.substr(sa.sa[i])<<endl;
	}
	cout<<sum<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
