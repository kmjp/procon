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
    int totalSteps(vector<int>& nums) {
		set<int> alive,check;
		int N=nums.size(),i;
		FOR(i,N) alive.insert(i);
		FOR(i,N) check.insert(i);
		int step=0;
		while(1) {
			/*
			FORR(v,alive) cout<<v<<":"<<nums[v]<<" ";
			cout<<" ";
			FORR(v,check) cout<<v;
			cout<<endl;
			*/
			set<int> del,nex;
			FORR(c,check) {
				if(alive.count(c)==0) continue;
				if(c==*alive.rbegin()) continue;
				auto it=next(alive.find(c));
				if(nums[c]>nums[*it]) {
					del.insert(*it);
					nex.insert(c);
				}
				
			}
			
			if(del.empty()) break;
			FORR(d,del) alive.erase(d);
			check=nex;
			
			
			
			step++;
			
			
		}
        return step;
    }
};
