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

const int K=20;
string S="ABC";
int num[3];

int ask(int x) {
	map<int,int> M;
	int i,y;
	FOR(i,K) {
		cout<<"? "<<S[x]<<endl;
		cin>>y;
		assert(y>=0);
		M[y]++;
		if(M[y]>=10) return y;
	}
	assert(0);
	return -1;
}

void add(int a,int b,int c) {
	int exp=num[a]+num[b];
	assert(a!=c);
	assert(b!=c);
	int x;
	while(1) {
		cout<<"+ "<<S[a]<<" "<<S[b]<<" "<<S[c]<<endl;
		cin>>x;
		assert(x==0);
		if(ask(c)==exp) {
			num[c]=exp;
			break;
		}
	}
	
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	num[0]=ask(0);
	num[1]=ask(1);
	int B=num[1];
	int C=num[0]*num[1];
	
	int cur=0,ret=2,tmp=1;
	FOR(i,10) {
		if(B&(1<<i)) {
			B^=1<<i;
			add(cur,ret,tmp);
			swap(ret,tmp);
		}
		if(B==0) break;
		add(cur,cur,tmp);
		swap(cur,tmp);
	}
	assert(num[ret]==C);
	cout<<"! "<<S[ret]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
