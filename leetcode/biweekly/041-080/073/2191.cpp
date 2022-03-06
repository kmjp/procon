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
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<ll,int>> V;
        int x=0;
        FORR(a,nums) {
			string s=to_string(a);
			FORR(c,s) c=mapping[c-'0']+'0';
			V.push_back({atoll(s.c_str())*100000+x,a});
			x++;
		}
		sort(ALL(V));
		vector<int> R;
		FORR(a,V) R.push_back(a.second);
		return R;
    }
};
