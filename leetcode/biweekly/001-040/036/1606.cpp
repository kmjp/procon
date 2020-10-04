typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))

//-------------------------------------------------------


class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
		set<int> avail;
		set<pair<int,int>> F;
		map<int,int> num;
		int i;
		FOR(i,k) avail.insert(i);
		vector<int> ret;
		int ma=0;
		FOR(i,arrival.size()) {
			int tim=arrival[i];
			while(F.size()&&F.begin()->first<=tim) {
				avail.insert(F.begin()->second);
				F.erase(F.begin());
			}
			auto it=avail.lower_bound(i%k);
			if(it==avail.end()) {
				it=avail.begin();
			}
			if(it==avail.end()) {
				continue;
			}
			else {
				int tar=*it;
				avail.erase(it);
				F.insert({tim+load[i],tar});
				num[tar]++;
				ma=max(ma,num[tar]);
			}
		}
		FOR(i,k) if(num[i]==ma) ret.push_back(i);
        return ret;
    }
};

