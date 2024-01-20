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

int N,M,K;
int C[402020];
int cnt[202020],cur[202020];
int box[202020];

int sum,nbox;

void add(int c,int a) {
	sum-=min(box[c]*K,cnt[c]);
	nbox-=box[c];
	box[c]-=(cur[c]+K-1)/K;
	cur[c]+=a;
	box[c]+=(cur[c]+K-1)/K;
	nbox+=box[c];
	sum+=min(box[c]*K,cnt[c]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) {
		cin>>C[i];
		C[N+i]=C[i]=C[i]-1;
		cnt[C[i]]++;
	}
	
	for(int l=0,r=0;l<N;l++) {
		while(r<l+N&&nbox<M) add(C[r++],1);
		cout<<sum<<endl;
		add(C[l],-1);
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
