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

const int prime_max = 101010;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	divp[1]=1;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}


class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
		cprime();
		multiset<int> P;
		int N=nums.size();
		int NP=0;
		ll ret=0;
		for(int L=0,R=0,R2=0;L<N;L++) {
			while(R<N) {
				if(divp[nums[R]]) {
					R++;
					continue;
				}
				P.insert(nums[R]);
				if(*P.rbegin()-*P.begin()>k) {
					P.erase(P.find(nums[R]));
					break;
				}
				R++;
			}
			while(R2<N&&NP<2) {
				if(divp[nums[R2]]) {
					R2++;
					continue;
				}
				NP++;
				R2++;
			}
			if(NP==2) {
				ret+=R-R2+1;
			}
			if(divp[nums[L]]==0) {
				NP--;
				P.erase(P.find(nums[L]));
			}
		}
		return ret;
		
    }
};
