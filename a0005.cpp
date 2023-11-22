#include "a0005.h"

void passwordCalc(string pp, int &ppEntropy, string &ppStrength)
{
 
    ppEntropy = getEntropy(pp);

    ppStrength = getStrength(ppEntropy);
}

int getEntropy(string pp)
{
    int lowerPool = 0, upperPool = 0, digitPool = 0, blankPool = 0, punctPool = 0;
    int n = int(pp.size());
    int i;
    int charPool = 0;
    double entropyBits = 0;

    //Ha101061875
    for(i = 0; i < n; ++i)
    {          
    //lower case set 26

        if(islower(pp[i]))
        {
            lowerPool = 26;
        }
    
    //upper case set 26

        if(isupper(pp[i]))
        {
            upperPool = 26;
        }
    
    //digit set 10
 
        if(isdigit(pp[i]))
        {
            digitPool = 10;
        }
    

        if(isblank(pp[i]))
        {
            blankPool = 2;
        }
  
   
        if(ispunct(pp[i]))
        {
            punctPool = 32;
        }
        
    }

    charPool = lowerPool + upperPool + digitPool + blankPool + punctPool;
    
    entropyBits = log2(charPool);

    
    return int (round(entropyBits * n));
    
}

string getStrength(int strength)
{
    
    if(strength <= 28)
    {
        return "Very Weak";
    }
    if(strength <= 35)
    {
        return "Weak";
    }
    if(strength <= 59)
    {
        return "Reasonable";
    }
    if(strength <= 127)
    {
        return "Strong";
    }
    else
    {
        return "Very Strong";
    }
}