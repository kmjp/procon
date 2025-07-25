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

int N,M;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	set<int> V;
	cin>>N>>M;
	FOR(i,N) V.insert(i);
	map<int,int> mp;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		if(x>y) swap(x,y);
		mp[y]=x;
	}
	vector<int> cand;
	FORR2(b,a,mp) {
		int num=-2;
		while(1) {
			auto it=V.lower_bound(a);
			if(it==V.end()||*it>b) break;
			num++;
			V.erase(it);
		}
		if(num) cand.push_back(num);
	}
	if(V.size()) cand.push_back(V.size());
	
	FORR(a,cand) {
		if(a%4==2) {
			cout<<"Akane"<<endl;
			return;
		}
	}
	cout<<"Aoi"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
