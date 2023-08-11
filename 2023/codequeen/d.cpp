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

int R,C,RS,CS,RT,CT;

int Rs[101010];
int Cs[101010];
int RpCs[201010];
int RmCs[201010];
set<pair<int,int>> S;
vector<pair<int,int>> cand(int r,int c) {
	int y,x;
	vector<pair<int,int>> cand;
	FOR(y,R) if(y!=r) cand.push_back({y,c});
	FOR(x,C) if(x!=c) cand.push_back({r,x});
	
	FOR(y,R) if(y!=r) {
		x=c+(y-r);
		if(x>=0&&x<C) cand.push_back({y,x});
		x=c-(y-r);
		if(x>=0&&x<C) cand.push_back({y,x});
	}
	return cand;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>R>>C>>RS>>CS>>RT>>CT;
	RS--,RT--,CS--,CT--;
	vector<pair<int,int>> A=cand(RS,CS);
	vector<pair<int,int>> B=cand(RT,CT);
	
	FORR2(y,x,A) {
		S.insert({y,x});
		Rs[y]++;
		Cs[x]++;
		RpCs[y+x]++;
		RmCs[y-x+100000]++;
	}
	ll ret=0;
	FORR2(y,x,B) {
		if(S.count({y,x})) ret-=4;
		ret+=Rs[y];
		ret+=Cs[x];
		ret+=RpCs[y+x];
		ret+=RmCs[y-x+100000];
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
