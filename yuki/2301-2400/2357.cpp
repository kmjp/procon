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

int NA=1,NB=2;

int ask(int v) {
	//if(NB) return (NA+v)%NB;
	cout<<"? "<<v<<endl;
	cin>>v;
	return v;
}

int A,B;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	x=ask(100);
	
	int ok=0;
	for(y=1;y<=100;y++) {
		map<int,pair<int,int>> S;
		int k=0;
		for(int NA=0;NA<=99;NA++) {
			for(int NB=NA+1;NB<=100;NB++) {
				if((100+NA)%NB==x) {
					k++;
					S[(y+NA)%NB]={NA,NB};
				}
			}
		}
		if(k==S.size()) {
			y=ask(y);
			cout<<"! "<<S[y].first<<" "<<S[y].second<<endl;
			return;
		}
	}
	assert(0);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
