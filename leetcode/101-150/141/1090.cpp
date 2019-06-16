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
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
		vector<pair<int,int>> V;
        int i;
        FOR(i,values.size()) V.push_back({values[i],labels[i]});
        sort(ALL(V));
        reverse(ALL(V));
        map<int,int> M;
        int num=0;
        ll S=0;
        FORR(v,V) if(num<num_wanted) {
			if(M[v.second]>=use_limit) continue;
			S+=v.first;
			M[v.second]++;
			num++;
		}
		return S;
    }
};

