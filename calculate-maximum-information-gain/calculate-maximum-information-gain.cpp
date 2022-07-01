static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
typedef double rl;

struct EntropyCalculator
{
    static inline rl Pxlog2P(int num, int denum) // calculate (num/denum)*log2(num/denum)
    {
        if(num == 0) return 0.0;
        assert(denum!=0);
        rl P=num/((rl)denum);
        return P*log2(P);
    }

    int N;
    vector<int> id_to_cnt;
    rl sum_Pxlog2P;
public:
    EntropyCalculator(const int cntID, const vector<int>& labels):
        N(labels.size()),
        id_to_cnt(cntID, 0),
        sum_Pxlog2P(0.0)
    {
        for(const int id: labels)
        {
            assert(0<=id && id<cntID);
            id_to_cnt[id]++;
        }
        for(int cnt: id_to_cnt) sum_Pxlog2P += Pxlog2P(cnt, N);
    }

    void update(const int id, const int delta)
    {
        assert(0<= id && id < id_to_cnt.size());
        assert(delta == +1 || delta == -1);
        
        const int prev_cnt=id_to_cnt[id];
        const int  new_cnt=id_to_cnt[id]+delta;
        
        const int prev_N=N;
        const int  new_N=N+delta;
        
        rl alpha = prev_N / ((rl)new_N);
        // 1st step of entropy recalculation: multiply all pi by alpha = N/(N+1) ( or alpha=N/(N-1) )
        // note that at this point sum(pi) != 1
        rl new_sum_Pxlog2P = alpha * sum_Pxlog2P + Pxlog2P(prev_N, new_N);
        
        rl prev_addend=Pxlog2P(prev_cnt, new_N);
        rl new_addend =Pxlog2P( new_cnt, new_N);
        
        N=new_N;
        id_to_cnt[id]=new_cnt;
        sum_Pxlog2P = new_sum_Pxlog2P - prev_addend + new_addend; // 2nd step
    }

    inline rl get_entropy() const
    {
        return -sum_Pxlog2P;
    }
};

class Solution {
public:
    double calculateMaxInfoGain(const vector<double>& petal_length, const vector<string>& species) {
        int N=petal_length.size();
        assert(N==species.size());
        if(N==0) return 0.0;

        typedef pair<double, int> val_id;
        vector<val_id> V(N); // V[i] = {petal_length[i], id[i]};
        
        unordered_map<string, int> name_TO_id;
        vector<int> ids(N);
        for(int i=0; i<N; i++)
        {
            const string& name=species[i];
            int new_id=name_TO_id.size();
            auto [it, not_found_ignore]=name_TO_id.insert({name, new_id});
            int real_id=it->second;
            
            V[i]={petal_length[i], real_id};
            ids[i]=real_id;
        }
        sort(V.begin(), V.end()); // sort by petal_length
        
        int cntID=name_TO_id.size();
        EntropyCalculator EC_L1(cntID,  {}), EC_L2(cntID, ids);
        
        rl H_L=EC_L2.get_entropy(), max_infoGain = 0.0, sz_L=N;
        
        // explore all possible splits of L into L1, L2: L=L1 U L2, L1 intersect L2 == {} (empty set), all values in L1 < all values in L2,
        // [i, j) is a (maximum) interval with all equal petal_lengths
        for(int i=0; i<N; )
        {
            int j=i+1;
            while(j<N && V[j].first==V[i].first) j++;
            if(j>=N) break;
            
            for(int k=i; k<j; k++)
            {
                EC_L1.update(V[k].second, +1);
                EC_L2.update(V[k].second, -1);
            }
                    
            rl H_L1=EC_L1.get_entropy(), H_L2=EC_L2.get_entropy();
            rl sz_L1=j, sz_L2=N-j;
            
            rl currSplit_infoGain = H_L - (H_L1*sz_L1)/sz_L - (H_L2*sz_L2)/sz_L;
            max_infoGain=max(max_infoGain, currSplit_infoGain);
            
            i=j; // proceed with next interval
        }

        return max_infoGain;
    }
};