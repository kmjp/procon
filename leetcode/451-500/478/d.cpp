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

int ng[1<<20];
ll sum[1<<20];
vector<pair<int,int>> ev[201];

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int N=nums.size(),Q=queries.size();
        int i;
        FOR(i,N-1) {
			int dif=nums[i+1]-nums[i];
			ng[i+1]=ng[i];
			sum[i+1]=sum[i];
			if(dif%k) {
				ng[i+1]++;
			}
			else {
				sum[i+1]+=(nums[i+1]-nums[i])/k;
			}
		}
		vector<ll> ret;
		FOR(i,201) ev[i].clear();
		FOR(i,Q) {
			if(ng[queries[i][1]]!=ng[queries[i][0]]) {
				ret.push_back(-1);
			}
			else {
				ret.push_back(0);
				ev[queries[i][0]/200].push_back({queries[i][1],i});
			}
		}
		FOR(i,200) if(ev[i].size()) {
			sort(ALL(ev[i]));
			int CL=i*200,CR=i*200;
			ll sum1=0,sum2=0;
			multiset<int> A,B;
			FORR2(R,cur,ev[i]) {
				int L=queries[cur][0];
				while(CR<=R) {
					int v=nums[CR++];
					sum2+=v;
					B.insert(v);
					if(A.size()+2==B.size()) {
						v=*B.begin();
						sum2-=v;
						sum1+=v;
						A.insert(v);
						B.erase(B.begin());
					}
					else if(A.size()&&*A.rbegin()>*B.begin()) {
						int a=*A.rbegin();
						int b=*B.begin();
						B.erase(B.begin());
						A.erase(A.find(a));
						sum1-=a-b;
						sum2+=a-b;
						A.insert(b);
						B.insert(a);
					}
				}
				while(L<CL) {
					int v=nums[--CL];
					sum2+=v;
					B.insert(v);
					if(A.size()+2==B.size()) {
						v=*B.begin();
						sum2-=v;
						sum1+=v;
						A.insert(v);
						B.erase(B.begin());
					}
					else if(A.size()&&*A.rbegin()>*B.begin()) {
						int a=*A.rbegin();
						int b=*B.begin();
						B.erase(B.begin());
						A.erase(A.find(a));
						sum1-=a-b;
						sum2+=a-b;
						A.insert(b);
						B.insert(a);
					}
					
				}
				while(CL<L) {
					int v=nums[CL++];
					if(A.count(v)) {
						A.erase(A.find(v));
						sum1-=v;
						if(A.size()+2==B.size()) {
							A.insert(*B.begin());
							sum1+=*B.begin();
							sum2-=*B.begin();
							B.erase(B.begin());
						}
					}
					else {
						B.erase(B.find(v));
						sum2-=v;
						if(B.size()<A.size()) {
							B.insert(*A.rbegin());
							sum1-=*A.rbegin();
							sum2+=*A.rbegin();
							A.erase(A.find(*A.rbegin()));
						}
					}
					
				}
				ll m=*B.begin();
				//cout<<cur<<" "<<sum2<<" "<<sum1<<" "<<m<<endl;
				//cout<<" "<<(sum2-m*B.size())<<" "<<(m*A.size()-sum1)<<" "<<B.size()<<" "<<A.size()<<endl;
				ret[cur]=((sum2-m*B.size())+(m*A.size()-sum1))/k;
			}
		}
		
		return ret;
		
    }
};

