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

int N;
ll X,Y;
ll A[88];

vector<int> hoge(vector<ll> P,ll tar) {
	unordered_map<ll,int> M;
	ll mask,i;
	FOR(mask,1<<20) {
		ll cur=0;
		FOR(i,20) {
			if(mask&(1<<i)) cur+=P[i];
			else cur-=P[i];
		}
		M[cur]=mask;
	}
	FOR(mask,1<<20) {
		ll cur=0;
		FOR(i,20) {
			if(mask&(1<<i)) cur+=P[i+20];
			else cur-=P[i+20];
		}
		if(M.count(tar-cur)) {
			ll tmask=M[tar-cur] | (mask<<20);
			vector<int> ret;
			FOR(i,40) {
				if(tmask&(1LL<<i)) ret.push_back(1);
				else ret.push_back(-1);
			}
			return ret;
		}
	}
	return {0};
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
	vector<ll> P[2];
	FOR(i,80) {
		if(i<N) cin>>A[i];
		P[i%2].push_back(A[i]);
	}
	
	vector<int> LR=hoge(P[1],X);
	vector<int> UD=hoge(P[0],Y);
	if(UD[0]==0||LR[0]==0) {
		cout<<"No"<<endl;
		return;
	}
	cout<<"Yes"<<endl;
	int cur=1;
	FOR(i,N) {
		if(i%2==0) {
			x=UD[i/2];
			if(cur==1&&x==1) cout<<"L";
			if(cur==1&&x==-1) cout<<"R";
			if(cur==-1&&x==1) cout<<"R";
			if(cur==-1&&x==-1) cout<<"L";
			cur=x;
		}
		else {
			x=LR[i/2];
			if(cur==1&&x==1) cout<<"R";
			if(cur==1&&x==-1) cout<<"L";
			if(cur==-1&&x==1) cout<<"L";
			if(cur==-1&&x==-1) cout<<"R";
			cur=x;
		}
		
	}
	cout<<endl;;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
