class Solution {
public:
    int dayOfYear(string date) {
        std::string dayno = "", month = "", year = "";
        int iyear = 0, imonth = 0, idayno = 0, res = 0;
        year = date.substr(0, 4); 
        month = date.substr(5, 2); 
        dayno = date.substr(8, 2);
        iyear = std::stoi(year);
        imonth = std::stoi(month);
        idayno = std::stoi(dayno);
        for(int i=1; i<imonth; i++){
            if(i==2) 
                res += (LY(iyear) ? 29 : 28);
            else if(i==4 || i==6 || i==9 || i==11) 
                res += 30;
            else
                res += 31;
        }
        res += idayno;
        return res;
    }

    bool LY(int num){
        return ((num%100==0)&&(num%400==0)||(num%4==0)&&(num%100!=0));
    }
};