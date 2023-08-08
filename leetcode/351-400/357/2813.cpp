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

multiset<ll> C[101010];

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
		int N=items.size();
		int i;
		FOR(i,N) C[i].clear();
		vector<pair<int,int>> cand;
		FORR(a,items) cand.push_back({a[0],a[1]-1});
		ll ma=0;
		int cat=0;
		sort(ALL(cand));
		reverse(ALL(cand));
		multiset<pair<ll,int>> rem;
		int num=0;
		ll tp=0;
		FORR(c,cand) {
			int p=c.first;
			int ca=c.second;
			if(C[ca].size()) {
				if(C[ca].size()>1) {
					rem.erase({*C[ca].begin(),ca});
				}
				C[ca].insert(p);
				rem.insert({*C[ca].begin(),ca});
			}
			else {
				C[ca].insert(p);
				cat++;
			}
			tp+=p;
			num++;
			if(num>k) {
				if(rem.size()==0) {
					cat--;
					tp-=p;
					C[ca].clear();
				}
				else {
					auto p=*rem.begin();
					rem.erase(p);
					tp-=p.first;
					C[p.second].erase(C[p.second].find(p.first));
					if(C[p.second].size()>1) {
						rem.insert({*C[p.second].begin(),p.second});
					}
				}
				
				num--;
			}
			ma=max(ma,tp+1LL*cat*cat);
			
		}
		cout<<"#"<<endl;
		return ma;
        
    }
};
