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
int P[202020];
int rev[202020];
int nex[202020];
int nex2[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	for(i=1;i<=N;i++) {
		cin>>P[i];
		rev[P[i]]=i;
	}
	
	set<pair<int,int>> S;
	S.insert({N+1,N+1});
	for(i=N;i>=0;i--) {
		auto it=S.lower_bound({P[i],0});
		nex[i]=it->second;
		S.insert({P[i],i});
	}
	set<int> T;
	T.insert(N+1);
	for(i=0;i<=N;i++) {
		x=rev[i];
		nex2[x]=*T.lower_bound(x);
		T.insert(x);
	}
	
	vector<int> cand;
	int cur=0,lef=K;
	while(cur<=N) {
		if(nex2[cur]-cur<=lef) {
			lef-=nex2[cur]-cur;
			cur=nex2[cur];
		}
		else {
			cand.push_back(P[cur]);
			cur++;
		}
	}
	cand.erase(cand.begin());
	
	
	if(K) {
		int mi=N+1,id=N+1;
		for(i=1;i<=K;i++) {
			if(P[N+1-i]<mi) {
				mi=P[N+1-i];
				id=N+1-i;
			}
		}
		
		vector<int> A,B;
		int cur=id;
		while(cur<=N) {
			A.push_back(P[cur]);
			cur=nex[cur];
		}
		
		int lef=K-(N+1-id);
		cur=1;
		while(cur<id) {
			if(min(id,nex2[cur])-cur<=lef) {
				lef-=nex2[cur]-cur;
				cur=nex2[cur];
			}
			else {
				B.push_back(P[cur]);
				cur++;
			}
		}
		
		while(A.size()&&A.back()>B[0]) A.pop_back();
		
		FORR(b,B) A.push_back(b);
		
		
		cand=min(cand,A);
	}
	
	FORR(c,cand) cout<<c<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
