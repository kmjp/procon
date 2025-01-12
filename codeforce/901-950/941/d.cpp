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
int N;
ll S[1010101];
ll A[1010];
vector<ll> hoge(vector<ll> V,int num) {
	deque<int> D;
	if(num%2==0) {
		D.push_back(V[0]/2);
		D.push_back(V[0]/2);
	}
	else {
		D.push_back(V[0]);
	}
	int i;
	for(i=1;i<V.size();i++) {
		D.push_back((V[i]-V[i-1])/2);
		D.push_front((V[i]-V[i-1])/2);
	}
	V.resize(num);
	FOR(i,num) V[i]=D[i];
	return V;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	FOR(k,T) {
		cin>>N;
		int M=N*(N+1)/2;
		map<int,int> U;
		FOR(i,M-1) {
			cin>>S[i];
			U[S[i]]++;
		}
		sort(S,S+M-1);
		
		int NO=(N+1)/2;
		vector<ll> Os;
		FOR(i,M-1) {
			if(Os.size()&&Os.back()==S[i]) Os.pop_back();
			else Os.push_back(S[i]);
		}
		
		vector<ll> V;
		if(Os.size()==NO-1) {
			//äÔêîÇçÌÇ¡ÇΩ
			V=hoge(Os,N-2);
			
			ll ma=0;
			FOR(x,V.size()) {
				ll s=0;
				for(y=x;y<V.size();y++) {
					s+=V[y];
					U[s]--;
					if(U[s]==0) U.erase(s);
				}
				ma=max(ma,s);
			}
			ll u=U.rbegin()->first;
			if(u>ma) {
				V.push_back(u-ma);
				V.insert(V.begin(),V.back());
			}
			else {
				u=S[M-2]-u;
				ll s=0;
				
				FOR(x,V.size()) {
					
					if(s+V[x]>u) {
						ll y=V[x];
						if(N%2&&x==N/2-1) {
							V.insert(V.begin()+x,0);
							V[x+1]=(y-2*(u-s));
							V[x]=(u-s);
							V.insert(V.begin()+N-1-x,0);
							V[N-1-x]=V[x];
							V[N-2-x]=V[x+1];
						}
						else {
							V.insert(V.begin()+x,0);
							V[x+1]=y-(u-s);
							V[x]=u-s;
							V.insert(V.begin()+N-1-x,0);
							V[N-1-x]=V[x];
							V[N-2-x]=V[x+1];
						}
						
						break;
					}
					s+=V[x];
				}
			}
			
			
			
		}
		else {
			//äÔêîà»äOÇçÌÇ¡ÇΩ
			int ok=0;
			FOR(i,Os.size()) if((Os.back()-Os[i])%2) {
				Os.erase(Os.begin()+i);
				ok=1;
				break;
			}
			if(ok==0) {
				V=hoge(Os,N+2);
				FOR(x,V.size()) {
					int s=0;
					for(y=x;y<V.size();y++) {
						s+=V[y];
						U[s]--;
					}
				}
				int rem=0;
				FORR2(a,b,U) if(b) rem=a;
				rem=2*rem-S[M-2];
				FOR(i,Os.size()) if(Os[i]==rem) {
					Os.erase(Os.begin()+i);
					break;
				}
			}
			V=hoge(Os,N);
		}
		
		
		FOR(i,N) cout<<V[i]<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
