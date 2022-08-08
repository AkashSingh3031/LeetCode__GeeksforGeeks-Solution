class Solution {
public:
    string solveEquation(string equation) {
        int i =0;
        int para=0, xpara=0;
        int flag = 1;
        while(i<equation.size())
        {
            int sign = 1;
            int temp = 0;
            if(equation[i] == '=') 
            {
                flag = -1;
                i++;
            }
            if(equation[i] == '-') 
            {
                sign = -1; 
                i++;
            }
            if(equation[i] == '+') 
            {
                sign = 1;
                i++;
            }
            
            if(isdigit(equation[i]))
            {
                while(i<equation.size() && isdigit(equation[i]))
                {
                    temp = temp*10 + equation[i]-'0';
                    i++;
                }
                if(i< equation.size() && equation[i] == 'x')
                {
                    xpara += flag*sign*temp;
                    i++;
                } 
                else 
                    para += flag*sign*temp;
            } 
            else //x
            {
                xpara += flag*sign;
                i++;
            }
            
        }
        string res;
        //cout<<para<<", "<<xpara<<endl;
        if(para == 0 && xpara == 0) 
            res = "Infinite solutions";
        else if(xpara == 0) 
            res = "No solution";
        else
            res = "x="+to_string(para/xpara*-1);
        return res;
    }
};