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

int K;
int ng(int x,int y,int r) {
	return (x*x+y*y>r*r);
}

int hoge(int r,int k,int cy,int cx) {
	while(cy>-r-k) cy-=k;
	while(cx>-r-k) cx-=k;
	int tot=0;
	int x,y;
	for(y=cy;y<=r+k;y+=k) {
		for(x=cx;x<=r+k;x+=k) {
			if(ng(x+k/2,y+k/2,r)) continue;
			if(ng(x-k/2,y+k/2,r)) continue;
			if(ng(x+k/2,y-k/2,r)) continue;
			if(ng(x-k/2,y-k/2,r)) continue;
			tot++;
		}
	}
	return tot;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	K*=2;
	int ma[2]={};
	FOR(x,2) {
		if((400/K)%2!=x) ma[0]=max(ma[0],hoge(200,K,x*K/2,x*K/2));
		if((600/K)%2!=x) ma[1]=max(ma[1],hoge(300,K,x*K/2,x*K/2));
	}
	cout<<ma[0]<<" "<<ma[1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
