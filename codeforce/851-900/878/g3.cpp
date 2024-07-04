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

std::random_device rnd;
std::mt19937 mt(rnd());
std::uniform_int_distribution<int> dist(1, 2000000);
int pos[1010101];

int go(int x) {
	if(x>0) {
		cout<<"+ "<<x<<endl;
	}
	else {
		cout<<"- "<<-x<<endl;
	}
	cin>>x;
	return x;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int S,ma;
	cin>>S;
	ma=S;
	ll sum=0;
	FOR(i,400) {
		x=dist(mt);
		sum+=x;
		y=go(x);
		ma=max(ma,y);
	}
	x=go(-sum);
	assert(S==x);
	x=go(ma-1);
	sum=ma-1;
	pos[x]=ma;
	FOR(i,300) {
		sum++;
		x=go(1);
		pos[x]=sum+1;
		if(x==S) {
			cout<<"! "<<sum<<endl;
			return;
		}
	}
	go(-sum);
	sum=0;
	FOR(i,300) {
		x=go(-300);
		sum+=300;
		if(pos[x]) {
			cout<<"! "<<sum+pos[x]-1<<endl;
			return;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
