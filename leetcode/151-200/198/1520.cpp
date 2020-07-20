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

vector<pair<int,int>> V[101010];

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
		int N=s.size();
		int C[26]={};
		int L[26],R[26];
		int i;
		FOR(i,26) {
			C[i]=0;
			L[i]=1<<20;
			R[i]=-1;
		}
		FOR(i,s.size()) {
			int x=s[i]-'a';
			C[x]++;
			L[x]=min(L[x],i);
			R[x]=i;
		}
		
		FOR(i,N+1) V[i].clear();
		FOR(i,N) {
			if(V[i].size()>V[i+1].size()) V[i+1]=V[i];
			else if(V[i].size()==V[i+1].size()) {
				int a=0;
				FORR(v,V[i]) a+=v.second;
				FORR(v,V[i+1]) a-=v.second;
				if(a<0) V[i+1]=V[i];
			}
			int x=s[i]-'a';
			if(L[x]==i) {
				int TL=N+1,TR=-1,TC=0;
				int mask=0,j;
				for(j=i;j<N;j++) {
					if(L[s[j]-'a']<i) break;
					if((mask&(1<<(s[j]-'a')))==0) {
						TL=min(TL,L[s[j]-'a']);
						TR=max(TR,R[s[j]-'a']);
						TC+=C[s[j]-'a'];
						mask|=1<<(s[j]-'a');
					}
					if(TL==i&&TR-TL==TC-1) {
						if(V[TR+1].size()<=V[i].size()) {
							V[TR+1]=V[i];
							V[TR+1].push_back({TL,TR-TL+1});
						}
						else if(V[i].size()+1==V[TR+1].size()) {
							int a=TR-TL+1;
							FORR(v,V[i]) a+=v.second;
							FORR(v,V[TR+1]) a-=v.second;
							if(a<0) {
								V[TR+1]=V[i];
								V[TR+1].push_back({TL,TR-TL+1});
							}
						}
					}
				}
				
			}
		}
		
		vector<string> ret;
		FORR(v,V[N]) ret.push_back(s.substr(v.first,v.second));
		return ret;
		
        
    }
};


