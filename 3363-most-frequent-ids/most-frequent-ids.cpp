class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& value, vector<int>& num_of_id) {
        map<long long,long long>valuewithfreq;// too keep track of number of id
        map<long long,set<long long>>freqwithvalue;// to keep track of avail value
        vector<long long>ans;
        for(int i=0;i<value.size();i++){
            //cout<<i<<' '<<value[i]<<'\n';
            if(num_of_id[i]>=0){
                auto it1=valuewithfreq.find(value[i]);
                if(it1!=valuewithfreq.end()){
                    
                    long long curfreq=it1->second;
                    it1->second+=num_of_id[i];
                    freqwithvalue[curfreq].erase(value[i]);
                    if(freqwithvalue[curfreq].empty()){
                        freqwithvalue.erase(curfreq);
                    }
                    freqwithvalue[curfreq+num_of_id[i]].insert(value[i]);
                }else{
                    valuewithfreq[value[i]]=num_of_id[i];
                    freqwithvalue[num_of_id[i]].insert(value[i]);
                }
                auto it=freqwithvalue.end();
                it--;
                ans.push_back(it->first);
            }else{
                long long curfreq=valuewithfreq[value[i]];
                
                valuewithfreq.erase(value[i]);
                
                freqwithvalue[curfreq].erase(value[i]);
                if(freqwithvalue[curfreq].empty()){
                    freqwithvalue.erase(curfreq);
                }
                if((curfreq+num_of_id[i])>0){
                    valuewithfreq[value[i]]=curfreq+num_of_id[i];
                    freqwithvalue[curfreq+num_of_id[i]].insert(value[i]);
                }
                if(freqwithvalue.empty()){
                    ans.push_back(0);
                }else{
                    
                    auto it=freqwithvalue.end();
                    it--;
                    ans.push_back(it->first);
                }
            }
            /*for(auto it:freqwithvalue){
                cout<<it.first<<'\n';
            }*/
        }
        return ans;
    }
};