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

int K;

int vis[100001][70];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	
	vis[0][0]=1;
	queue<int> Q;
	Q.push(0);
	while(Q.size()) {
		int rem=Q.front()/100;
		int sum=Q.front()%100;
		Q.pop();
		
		FOR(i,10) {
			int nrem=(rem*10+i)%K;
			int nsum=sum+i;
			if(nsum<65&&vis[nrem][nsum]==0) {
				vis[nrem][nsum]=1;
				Q.push(nrem*100+nsum);
			}
		}
	}
	
	for(i=1;i<=60;i++) if(vis[0][i]) {
		cout<<i<<endl;
		break;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
