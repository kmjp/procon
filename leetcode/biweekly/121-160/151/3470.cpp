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


class Solution {
public:
    vector<int> permute(int n, long long k) {
        ll F[111]={};
        F[0]=F[1]=F[2]=1;
        int i,j;
        for(i=3;i<=n;i++) {
			F[i]=min(1LL<<50,F[i-1]*((i+1)/2));
		}
		if(n%2==0&&F[n]*2<k) return {};
		if(n%2&&F[n]<k) return {};
		
		vector<int> V;
		vector<int> alive[2];
		for(i=1;i<=n;i++) alive[i%2].push_back(i);
		for(i=1;i<=n;i++) {
			if(n%2==1&&i%2==0) continue;
			cout<<"#"<<i<<" "<<k<<" "<<F[n-1]<<endl;
			if(F[n-1]<k) {
				k-=F[n-1];
				continue;
			}
			V.push_back(i);
			alive[i%2].erase(remove(ALL(alive[i%2]), i), alive[i%2].end());
			if(i%2==1) {
				swap(alive[0],alive[1]);
			}
			break;
		}
		for(i=1;i<n;i++) {
			int d=i%2;
			FORR(e,alive[d]) {
				cout<<i<<" "<<e<<" "<<k<<endl;
				if(F[n-1-i]<k) {
					k-=F[n-1-i];
					continue;
				}
				V.push_back(e);
				alive[d].erase(remove(ALL(alive[d]), e), alive[d].end());
				break;
			}
		}
        return V;
        
    }
};

