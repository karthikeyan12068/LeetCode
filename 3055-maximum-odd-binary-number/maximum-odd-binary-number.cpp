class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int noo=count(s.begin(),s.end(),'1');
        string temp="1";
        noo--;
        int freespace=(s.length()-1)-(noo);
        while(freespace>0){
            temp='0'+temp;
            freespace--;
        }
        while(noo>0){
            temp='1'+temp;
            noo--;
        }
        return temp;
    }
};