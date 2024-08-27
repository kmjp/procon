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

int M[]={31,29,31,30,31,30,31,31,30,31,30,31};
vector<string> bcand,cand;
int T;


map<pair<string,string>,pair<int,int>> memo;
pair<int,int> hit(string a,string b) {
	if(memo.count({a,b})==0) {
		int hit=0,blow=0;
		int x,y;
		FOR(x,4) FOR(y,4) if(a[x]==b[y]) {
			if(x==y) hit++;
			else blow++;
		}
		memo[{a,b}]={hit,blow};
	}
	return memo[{a,b}];
}

string best() {
	int a,b,c,d;
	int num=101010;
	string be;
	int step=0;
	string X="0000";
	map<pair<int,int>,int> M;
	for(X[0]='0';X[0]<'9';X[0]++)
	for(X[1]='0';X[1]<'9';X[1]++)
	for(X[2]='0';X[2]<'9';X[2]++)
	for(X[3]='0';X[3]<'9';X[3]++) {
		if(X[0]==X[1]) continue;
		if(X[0]==X[2]) continue;
		if(X[0]==X[3]) continue;
		if(X[1]==X[2]) continue;
		if(X[1]==X[3]) continue;
		if(X[2]==X[3]) continue;
		step++;
		if(step>=100) break;
		M.clear();
		int ma=0;
		FORR(c,cand) {
			auto p=hit(c,X);
			M[p]++;
			ma=max(ma,M[p]);
			if(ma>=num) break;
		}
		if(ma<num) {
			num=ma;
			be=X;
		}
		
	}
	return be;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,12) {
		FOR(j,M[i]) {
			string S="0000";
			S[0]+=(i+1)/10;
			S[1]+=(i+1)%10;
			S[2]+=(j+1)/10;
			S[3]+=(j+1)%10;
			
			if(S[0]==S[1]) continue;
			if(S[0]==S[2]) continue;
			if(S[0]==S[3]) continue;
			if(S[1]==S[2]) continue;
			if(S[1]==S[3]) continue;
			if(S[2]==S[3]) continue;
			bcand.push_back(S);
		}
	}
	cin>>T;
	while(T--) {
		cand=bcand;
		//cin>>s;
		k=0;
		while(cand.size()>1) {
			k++;
			string X=best();
			
			cout<<"? "<<X<<endl;
			cin>>x>>y;
			/*
			auto p=hit(s,X);
			x=p.first;
			y=p.second;
			*/
			assert(x!=-1);
			vector<string> nex;
			FORR(c,cand) if(hit(X,c)==make_pair(x,y)) nex.push_back(c);
			cand=nex;
		}
		assert(k<=6);
		cout<<"! "<<cand[0]<<endl;
		cin>>x;
		//assert(x==0);
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
