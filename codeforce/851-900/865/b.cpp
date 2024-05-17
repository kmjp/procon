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


int T,N;
int P[2][1101];
void type1(int v) {
	cout<<"+ "<<v+2<<endl;
	cin>>v;
	assert(v==1);
}
int type2(int i,int j) {
	cout<<"? "<<i+1<<" "<<j+1<<endl;
	cin>>i;
	return i;
}

void ans() {
	cout<<"!";
	int i,j;
	FOR(i,2) {
		FOR(j,N) cout<<" "<<P[i][j];
	}
	cout<<endl;
	cin>>i;
	assert(i==1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		MINUS(P);
		type1(N-1);
		type1(N-2);
		int ma=1;
		int D[1010];
		for(i=1;i<N;i++) {
			D[i]=type2(0,i);
			if(D[i]>D[ma]) ma=i;
		}
		FOR(i,N) if(i!=ma) {
			D[i]=type2(ma,i);
		}
		
		vector<int> cand;
		for(int L=1,R=N;L<=R;L++,R--) {
			cand.push_back(R);
			cand.push_back(L);
		}
		
		D[ma]=0;
		FOR(i,N) {
			P[0][i]=cand[D[i]];
			P[1][i]=cand[N-1-D[i]];
		}
		ans();
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
