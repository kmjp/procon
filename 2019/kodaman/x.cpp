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

int N;
int C[10101];
set<pair<int,int>> S;
void out(int x1,int y1,int x2,int y2) {
	C[abs(x1-x2)+abs(y2-y1)]++;
	assert(S.count({x1,y1})==0);
	assert(S.count({x2,y2})==0);
	assert(x1>=1 && x1<=N+1);
	assert(x2>=1 && x2<=N+1);
	assert(y1>=1 && y1<=N);
	assert(y2>=1 && y2<=N);
	S.insert({x1,y1});
	S.insert({x2,y2});
	cout<<y1<<" "<<x1<<" "<<y2<<" "<<x2<<endl;
}


void solve() {
	
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N%4==2) {
		cout<<"No"<<endl;
	}
	else if(N%2) {
		cout<<"Yes"<<endl;
		for(x=1;x<=N+1;x+=2) FOR(y,N) out(x,y+1,x+1,(y+(x/2))%N+1);
	}
	else {
		cout<<"Yes"<<endl;
		FOR(y,N) out(1,y+1,2,y+1);
		FOR(y,N/4) {
			out(3,y*4+1,3,y*4+3);
			out(3,y*4+2,3,y*4+4);
		}
		out(4,N,5,1);
		if(N==4) {
			out(4,1,5,3);
			out(4,2,5,4);
			out(4,3,5,2);
		}
		else {
			for(y=1;y<=N-1;y++) {
				if(y<=N/4) out(4,y,4,y+N/2+1);
				else if(y>N/2 && y-(N/2+1)<=N/4 && y-(N/2+1)>=1) continue;
				else out(4,y,5,y+1);
			}
			for(y=2;y<2+N/4;y++) out(5,y,5,y+N/2+1);
		}
		
		for(x=6;x<=N+1;x+=2) {
			FOR(y,N) out(x,y+1,x+1,(y+(x/2-1))%N+1);
		}
		
	}
	for(i=1;i<=N;i++) assert(C[i]==N+1-i);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
