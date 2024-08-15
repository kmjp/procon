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

int T,N,D[1010101];

vector<pair<int,int>> V;
void out(int a,int b) {
	a%=N;
	b%=N;
	V[a].first--;
	V[b].first--;
	cout<<(V[a].second%N)+1<<" "<<(V[b].second%N)+1<<"\n";
}

void go(int C) {
	int i;
	int x=C;
	FOR(i,C) while(V[i].first) {
		out(i,x);
		x++;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		ll sum=0;
		V.clear();
		FOR(i,N) {
			scanf("%d",&D[i]);
			sum+=D[i];
			V.push_back({D[i],i});
		}
		if(sum!=2*N) {
			cout<<"NO"<<"\n";
			continue;
		}
		int C=N;
		sort(ALL(V));
		reverse(ALL(V));
		while(V[C-1].first==1) C--;
		
		if(V[0].first==2) {
			cout<<"YES"<<"\n";
			FOR(i,N) out(i,i+1);
			continue;
		}
		if(V[1].first==2) {
			cout<<"NO"<<"\n";
			continue;
		}
		if(C%2==0) {
			cout<<"YES"<<"\n";
			out(0,1);
			out(0,1);
			for(i=2;i<C;i+=2) {
				out(i-2,i);
				out(i-1,i+1);
			}
			go(C);
			continue;
		}
		if(C%2&&V[0].first>3&&C>=5) {
			cout<<"YES"<<"\n";
			out(0,1);
			out(0,1);
			out(0,2);
			out(0,3);
			out(1,4);
			for(i=5;i<C;i+=2) {
				out(i-2,i);
				out(i-1,i+1);
			}
			go(C);
			continue;
		}
		if(C%2&&V[0].first>3&&C==3) {
			if(V[2].first<=2) {
				cout<<"NO"<<"\n";
				continue;
			}
			cout<<"YES"<<"\n";
			out(0,1);
			out(1,2);
			out(2,0);
			go(3);
			continue;
		}
		if(C%2&&V[0].first==3&&V[2].first>=3&&C>=7) {
			cout<<"YES"<<"\n";
			out(0,1);
			out(0,1);
			out(0,2);
			out(1,3);
			out(2,4);
			out(2,5);
			out(3,6);
			for(i=7;i<C;i+=2) {
				out(i-2,i);
				out(i-1,i+1);
			}
			go(C);
			continue;
		}
		if(C==5&&V[0].first==3&&V[4].first==3) {
			cout<<"YES"<<"\n";
			out(0,1);
			out(1,2);
			out(2,3);
			out(3,4);
			out(4,0);
			go(5);
			continue;
		}
		if(C==3&&V[0].first==3&&V[2].first==3) {
			cout<<"YES"<<"\n";
			out(0,1);
			out(1,2);
			out(2,0);
			go(3);
			continue;
		}
		cout<<"NO"<<"\n";
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
