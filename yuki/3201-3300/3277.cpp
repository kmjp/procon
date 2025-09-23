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
ll N;
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


int ok[10100];

int ismono(int x) {
	int cur=9;
	while(x) {
		if(x%10>cur) return 0;
		cur=x%10;
		x/=10;
	}
	return 1;
}
int reduce(int x) {
	int cur=0;
	while(x) {
		cur+=x%10;
		x/=10;
	}
	return cur;
}
int reduce(string x) {
	int cur=0;
	FORR(c,x) cur+=c-'0';
	return cur;
}
	

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=10000;i++) {
		x=i;
		while(x>=10) {
			if(!ismono(x)) break;
			x=reduce(x);
		}
		ok[i]=ok[i-1]+(x<=9);
	}
	
	
	cin>>T;
	while(T--) {
		cin>>N;
		N++;
		string s=to_string(N);
		FOR(i,s.size()-1) if(s[i+1]<s[i]) {
			for(j=i+1;j<s.size();j++) s[j]=s[i];
		}
		
		while(ok[reduce(s)]-ok[reduce(s)-1]==0) {
			int cur=reduce(s);
			int add=0;
			for(i=s.size()-1;i>=0;i--) if(s[i]!='9') {
				string s2=s,s3=s;
				for(j=i;j<s.size();j++) {
					s2[j]=s[i]+1;
					s3[j]='9';
				}
				x=reduce(s2);
				y=reduce(s3);
				
				if(ok[y]-ok[x-1]) {
					s[i]++;
					for(j=i;j<s.size();j++) s[j]=s[i];
					break;
				}
			}
			if(i==-1) {
				s=string(s.size()+1,'1');
			}
		}
		ll N2=atoll(s.c_str());
		ll ret=(modpow(10,N)+mo-1)*modpow(9)%mo;
		ll d=(N2-N)/8;
		ret+=(modpow(10,d)+mo-1)*modpow(9)%mo*8%mo;
		ret+=modpow(10,d)*((N2-N)%8);
		ret%=mo;
		cout<<ret<<endl;

		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
