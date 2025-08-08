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

int T,H,W,L,N,M,R,C;
vector<pair<int,int>> vert,hori;

void prot(int y,int x) {
	int i;
	if(N) {
		N-=L;
		FOR(i,L) hori.push_back({y+i,x});
	}
	else {
		M-=L;
		FOR(i,L) vert.push_back({y,x+i});
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>L>>N>>M>>R>>C;
		R--,C--;
		vert.clear();
		hori.clear();
		if(H%L==1&&W%L==1&&R%L==0&&C%L==0) {
			FOR(y,H/L) vert.push_back({y*L+(y>=R/L),C}),M--;
			FOR(x,W/L) hori.push_back({R,x*L+(x>=C/L)}),N--;
			FOR(y,H/L) FOR(x,W/L) prot(y*L+(y>=R/L),x*L+(x>=C/L));
		}
		else if(H%L==L-1&&W%L==L-1&&R%L==L-1&&C%L==L-1) {
			FOR(i,L-1) {
				vert.push_back({R/L*L,C+1+i});
				vert.push_back({R,C/L*L+i});
				hori.push_back({R/L*L+i,C/L*L});
				hori.push_back({R+1+i,C});
				N-=2;
				M-=2;
			}
			for(y=R/L*L+L;y<R/L*L+2*L-1;y++) for(x=0;x<C-L;x+=L) hori.push_back({y,x}),N--;
			for(y=R/L*L+L;y<R/L*L+2*L-1;y++) for(x=C+L;x<W;x+=L) hori.push_back({y,x}),N--;
			for(y=0;y<R-L;y+=L) for(x=C/L*L+L;x<C/L*L+2*L-1;x++) vert.push_back({y,x}),M--;
			for(y=R+L;y<H;y+=L) for(x=C/L*L+L;x<C/L*L+2*L-1;x++) vert.push_back({y,x}),M--;
			for(y=0;y<R;y+=L) for(x=0;x<C;x+=L) if(y!=R/L*L||x!=C/L*L) prot(y,x);
			for(y=R+L;y<H;y+=L) for(x=0;x<C;x+=L) prot(y,x);
			for(y=0;y<R;y+=L) for(x=C+L;x<W;x+=L) prot(y,x);
			for(y=R+L;y<H;y+=L) for(x=C+L;x<W;x+=L) prot(y,x);
		}
		
		if(N==0&&M==0) {
			cout<<"Yes"<<endl;
			FORR2(r,c,hori) cout<<r+1<<" "<<c+1<<endl;
			FORR2(r,c,vert) cout<<r+1<<" "<<c+1<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
			
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
