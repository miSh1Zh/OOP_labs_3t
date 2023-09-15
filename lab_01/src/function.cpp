#include "function.h"


string num_2_string(int val){
    string res = "";
    char tmp = '\0';

    // zero exception traced in main function below (*)

    while(val != 0){
        tmp = val%10 + '0';
        res = tmp + res;
        val /= 10;
    }
    
    return res;
}



string trace_string(const string& s){
    
    int tmp = 0;
    bool changed = false;

    string res = "";

    int i = 0, n = s.size();

    do{
        
        if(s[i] >= '0' and s[i] <= '9'){
            if(!changed and s[i] == '0') res += "0\n"; // here (*)
            else{
                tmp = 10 * tmp + s[i] - '0';
                changed = true;
            }
        }

        else{
            if(changed){
                res += num_2_string(tmp) + '\n';
                tmp = 0;
                changed = false;
            }
        }

    }while(i++ < n);

    return res;
}
