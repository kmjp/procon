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

int H,W,K;
string S[10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) cin>>S[y];
	
	int ma=0;
	int mask;
	FOR(mask,1<<H) {
		int lef=K-__builtin_popcount(mask);
		if(lef<0) continue;
		vector<int> V;
		int sum=0;
		FOR(x,W) {
			int num=0;
			FOR(y,H) if(((mask>>y)&1)||(S[y][x]=='#')) num++;
			sum+=num;
			V.push_back(H-num);
		}
		sort(ALL(V));
		reverse(ALL(V));
		FOR(i,min(lef,(int)V.size())) sum+=max(0,V[i]);
		ma=max(ma,sum);
		
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
