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

const ll mo=1000000007;

ll comb(ll N_, ll C_) {
	if(C_==1) return N_;
	if(C_==2) {
		if(N_<=1) return 0;
		return N_*(N_-1)/2;
	}
	return 0;
}

unordered_map<int,int> L,R;
class Solution {
public:
    int subsequencesWithMiddleMode(vector<int>& nums) {
		ll ret=0;
		ll N=nums.size();
		int c,x,y;
		L.clear();
		R.clear();
		FOR(c,N) R[nums[c]]++;
		
		FOR(c,N) {
			int cur=nums[c];
			R[cur]--;
			int LC=c,RC=N-1-c;
			int LT=L[cur],RT=R[cur];
			L[cur]=R[cur]=0;
			//5
			(ret+=comb(LT,2)*comb(RT,2))%=mo;
			//131
			(ret+=1LL*LT*(LC-LT)*RT*(RC-RT))%=mo;
			int i;
			FOR(i,2) {
				//41
				(ret+=comb(LT,2)*comb(RT,1)*(RC-RT))%=mo;
				//32
				(ret+=comb(LT,2)*comb(RC-RT,2))%=mo;
				//1211
				ll s=0,tot=0;
				FORR(r,R) {
					s+=tot*r.second;
					tot+=r.second;
				}
				FORR(r,L) {
					ll a=LT*r.second;
					ll b=s-(tot-R[r.first])*R[r.first];
					(ret+=a*b)%=mo;
				}
				
				swap(LC,RC);
				swap(L,R);
				swap(LT,RT);
			}
			L[cur]+=LT;
			R[cur]+=RT;
			L[cur]++;
		}
		
		
		return ret%mo;
    }
};