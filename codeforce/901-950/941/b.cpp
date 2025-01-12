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

int T,N,K;

void verify(vector<int> a,int n,int k) {
	set<int> S;
	int mask,i;
	FOR(mask,1<<a.size()) {
		int sum=0;
		FOR(i,a.size()) if(mask&(1<<i)) sum+=a[i];
		S.insert(sum);
	}
	/*
	for(i=1;i<=n;i++) {
		cout<<S.count(i);
	}
	cout<<endl;
	*/
	for(i=1;i<=n;i++) {
		assert(S.count(i)==(i!=k));
	}
	assert(a.size()<=25);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		vector<int> ret;
		int L=0,R=0;
		int L2,R2;
		N=1000000;
		if(K==1) {
			ret.push_back(2);
			ret.push_back(3);
			L2=2,R2=3;
		}
		else if(K==2) {
			ret.push_back(1);
			ret.push_back(3);
			ret.push_back(4);
			ret.push_back(5);
			L2=3,R2=5;
		}
		else if(K==3) {
			ret.push_back(1);
			ret.push_back(1);
			ret.push_back(4);
			ret.push_back(5);
			ret.push_back(6);
			ret.push_back(7);
			L2=4,R2=7;
		}
		else if(K==4) {
			ret.push_back(1);
			ret.push_back(2);
			ret.push_back(5);
			ret.push_back(8);
			L2=5,R2=11;
		}
		else {
			while(R<K) {
				if(R+R+1<K) {
					ret.push_back(R+1);
					R=2*R+1;
				}
				else {
					ret.push_back(K-R-1);
					R=K-1;
					break;
				}
			}
			ret.push_back(K+1);
			ret.push_back(2*K+1);
			L2=K+1;
			R2=R+K+K+1;
		}
		while(R2<N) {
			ret.push_back(R2+1-L2);
			R2+=R2+1-L2;
		}
		
		cout<<ret.size()<<endl;
		FORR(r,ret) cout<<r<<" ";
		cout<<endl;
		//verify(ret,N,K);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
