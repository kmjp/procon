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
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
		vector<int> R(persons.size());
		vector<pair<int,int>> ev;
		FORR(f,flowers) {
			ev.push_back({f[0],-1});
			ev.push_back({f[1],100000});
		}
		int i;
		FOR(i,persons.size()) ev.push_back({persons[i],i});
		int num=0;
		sort(ALL(ev));
		FORR(e,ev) {
			if(e.second==-1) num++;
			else if(e.second==100000) num--;
			else R[e.second]=num;
		}
        return R;
    }
};
