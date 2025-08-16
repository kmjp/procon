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

int A[8][8];
queue<int> Q[10];
bitset<100000200> dp;
int p10[9];
int B[10];
ll mask[10],NG;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,8) p10[i+1]=p10[i]*10;
	
	FOR(y,8) {
		cin>>s;
		FOR(x,8) {
			A[y][x]=s[x]-'0';
			B[y]+=A[y][x]*p10[x];
		}
		NG|=1LL<<(5*y+4);
	}
	queue<int> Q1,Q2;
	Q1.push(0);
	for(y=1;y<=7;y++) {
		while(Q1.size()) {
			int cur=Q1.front();
			Q1.pop();
			FOR(i,8) {
				int nex=cur;
				FOR(x,8) {
					if(nex/p10[x]%10+A[y][(x+i)%8]>=10) break;
					nex+=p10[x]*A[y][(x+i)%8];
				}
				if(x==8) Q2.push(nex);
			}
		}
		
		
		swap(Q1,Q2);
	}
	
	int cur=0;
	FOR(i,8) cur+=A[0][i]*p10[i];
	
	while(Q1.size()) {
		if(cur==Q1.front()) {
			cout<<"Yes"<<endl;
			return;
		}
		Q1.pop();
	}
	
	cout<<"No"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
