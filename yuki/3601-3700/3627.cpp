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

string P;
int Q,N,M;
pair<int,int> X[1010];

int share(int pos) {
	cout<<"share "<<X[pos].second<<endl;
	return X[pos].first;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P>>Q>>N>>M;
	int DA=0,DB=0;
	int K=(N+M+1)/2;
	if(P=="Alice") {
		FOR(i,N) {
			cin>>X[i].first;
			X[i].second=i+1;
		}
		sort(X,X+N);
	}
	else {
		FOR(i,M) {
			cin>>X[i].first;
			X[i].second=i+1;
		}
		sort(X,X+M);
	}
	while(K>1&&DA<N&&DB<M) {
		int p=min(K/2,N-DA);
		int q=min(K/2,M-DB);
		if(P=="Alice") {
			x=share(DA+p-1);
			cin>>y;
		}
		else {
			y=share(DB+q-1);
			cin>>x;
		}
		if(x<=y) {
			DA+=p;
			K-=p;
		}
		else {
			DB+=q;
			K-=q;
		}
	}
	if(DA==N) {
		//DB‚Ì+KŒÂ–Ú
		if(P=="Alice") {
			x=share(0);
			cin>>y;
		}
		else {
			y=share(DB+K-1);
			cin>>x;
		}
		cout<<"answer "<<y<<endl;
		return;
	}
	if(DB==M) {
		//DB‚Ì+KŒÂ–Ú
		if(P=="Alice") {
			x=share(DA+K-1);
			cin>>y;
		}
		else {
			y=share(0);
			cin>>x;
		}
		cout<<"answer "<<x<<endl;
		return;
	}
	
	
	if(P=="Alice") {
		x=share(DA);
		cin>>y;
	}
	else {
		x=share(DB);
		cin>>y;
	}
	cout<<"answer "<<min(x,y)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
