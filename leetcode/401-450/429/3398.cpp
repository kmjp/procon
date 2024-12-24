#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
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


class Solution {
public:
	int step(int v,vector<int> V,string s) {
		if(v<1) return 1<<30;
		if(s.size()<=v) return 0;
		
		if(v==1) {
			int ret0=0,ret1=0;
			int i;
			FOR(i,s.size()) {
				if(s[i]==i%2) ret0++;
				if(s[i]!=i%2) ret1++;
			}
			cout<<v<<" "<<ret0<<" "<<ret1<<endl;
			return min(ret0,ret1);
		}
		else if(v==2) {
			int from[2][2]={};
			from[0][0]=(s[0]!=0)+(s[1]!=0);
			from[0][1]=(s[0]!=0)+(s[1]!=1);
			from[1][0]=(s[0]!=1)+(s[1]!=0);
			from[1][1]=(s[0]!=1)+(s[1]!=1);
			int i,x,y,k;
			for(i=2;i<s.size();i++) {
				int to[2][2]={};
				FOR(x,2) FOR(y,2) to[x][y]=1<<20;
				FOR(x,2) FOR(y,2) FOR(k,2) {
					if(x==y&&y==k) continue;
					to[y][k]=min(to[y][k],from[x][y]+(s[i]!=k));
				}
				swap(from,to);
			}
			int mi=1<<20;
			FOR(x,2) FOR(y,2) {
				mi=min(mi,from[x][y]);
				cout<<x<<y<<" "<<from[x][y]<<endl;
			}
			cout<<v<<" "<<mi<<endl;
			return mi;
		}
		else {
			int ret=0;
			FORR(a,V) {
				ret+=a/(v+1);
			}
			return ret;
		}
	}
    int minLength(string s, int numOps) {
		int pre=-1;
		vector<int> V;
		FORR(a,s) {
			a-='0';
			if(pre!=a) V.push_back(0);
			V.back()++;
			pre=a;
		}
		if(step(1,V,s)<=numOps) return 1;
		if(step(2,V,s)<=numOps) return 2;
		int ret=s.size();
		for(int i=20;i>=0;i--) if(step(ret-(1<<i),V,s)<=numOps) ret-=1<<i;
		return ret;
        
    }
};


