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

int T;
int M;

set<int> WI,WN,IW,IN,NW,NI;
vector<pair<pair<int,int>,pair<char,char>>> R;
int hoge(set<int>& A,set<int>& B,char a,char b) {
	if(A.empty()||B.empty()) return 0;
	R.push_back({{*A.begin(),*B.begin()},{a,b}});
	A.erase(A.begin());
	B.erase(B.begin());
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>M;
		WI.clear();
		WN.clear();
		IW.clear();
		IN.clear();
		NW.clear();
		NI.clear();
		FOR(i,M) {
			cin>>s;
			x=count(ALL(s),'w');
			y=count(ALL(s),'i');
			k=count(ALL(s),'n');
			if(x>1&&y==0) WI.insert(i);
			if(x>1&&k==0) WN.insert(i);
			if(y>1&&x==0) IW.insert(i);
			if(y>1&&k==0) IN.insert(i);
			if(k>1&&x==0) NW.insert(i);
			if(k>1&&y==0) NI.insert(i);
		}
		R.clear();
		
		while(1) {
			if(hoge(WI,IW,'w','i')) continue;
			if(hoge(WN,NW,'w','n')) continue;
			if(hoge(IN,NI,'i','n')) continue;
			if(WI.size()&&IN.size()&&NW.size()) {
				x=*WI.begin(); WI.erase(WI.begin());
				y=*IN.begin(); IN.erase(IN.begin());
				k=*NW.begin(); NW.erase(NW.begin());
				R.push_back({{x,y},{'w','i'}});
				R.push_back({{y,k},{'w','n'}});
				continue;
			}
			if(WN.size()&&NI.size()&&IW.size()) {
				x=*WN.begin(); WN.erase(WN.begin());
				y=*NI.begin(); NI.erase(NI.begin());
				k=*IW.begin(); IW.erase(IW.begin());
				R.push_back({{x,y},{'w','n'}});
				R.push_back({{y,k},{'w','i'}});
				continue;
			}
			
			
			break;
		}
		
		
		assert(WI.empty());
		assert(WN.empty());
		assert(IN.empty());
		assert(IW.empty());
		assert(NI.empty());
		assert(NW.empty());
		
		
		cout<<R.size()<<endl;
		FORR2(id,ch,R) {
			cout<<id.first+1<<" "<<ch.first<<" "<<id.second+1<<" "<<ch.second<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
