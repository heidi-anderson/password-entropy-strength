#define CATCH_CONFIG_MAIN
#include "..//catch.hpp"
#include "a0005.h"

//test cases
TEST_CASE("passwordCalc - all lowercase")
{
    int ppEntropy;
    string ppStrength;
    string pp = "heidi";
    
    passwordCalc( pp, ppEntropy, ppStrength );
    
    CHECK( ppEntropy == 24 );
    CHECK( ppStrength == "Very Weak");
}


TEST_CASE("passwordCalc - all uppercase")
{
    int ppEntropy;
    string ppStrength;
    string pp = "HEIDI";
    
    passwordCalc( pp, ppEntropy, ppStrength );
    
    CHECK( ppEntropy == 24 );
    CHECK( ppStrength == "Very Weak");
}

TEST_CASE("passwordCalc - all digits")
{
    int ppEntropy;
    string ppStrength;
    string pp = "12345";
    
    passwordCalc( pp, ppEntropy, ppStrength );
    
    CHECK( ppEntropy == 17);
    CHECK( ppStrength == "Very Weak");
}

TEST_CASE("passwordCalc - all blanks")
{
    int ppEntropy;
    string ppStrength;
    string pp = "\t";
    
    passwordCalc( pp, ppEntropy, ppStrength );
    
    CHECK( ppEntropy == 1 );
    CHECK( ppStrength == "Very Weak");
}

TEST_CASE("passwordCalc - all punct")
{
    int ppEntropy;
    string ppStrength;
    string pp = ":]";
    
    passwordCalc( pp, ppEntropy, ppStrength );
    
    CHECK( ppEntropy == 10 );
    CHECK( ppStrength == "Very Weak");
}

TEST_CASE("passwordCalc - Weak")
{
    int ppEntropy;
    string ppStrength;
    string pp = "Hello";
    
    passwordCalc( pp, ppEntropy, ppStrength );
    
    CHECK( ppEntropy == 29 );
    CHECK( ppStrength == "Weak");
}


TEST_CASE("passwordCalc - Reasonable")
{
    int ppEntropy;
    string ppStrength;
    string pp = "Ab123456";
    
    passwordCalc( pp, ppEntropy, ppStrength );
    
    CHECK( ppEntropy == 48 );
    CHECK( ppStrength == "Reasonable");
}

TEST_CASE("passwordCalc - Strong")
{
    int ppEntropy;
    string ppStrength;
    string pp = "AbAb1!2!34";
    
    passwordCalc( pp, ppEntropy, ppStrength );
    
    CHECK( ppEntropy == 66 );
    CHECK( ppStrength == "Strong");
}

TEST_CASE("passwordCalc - Very Strong")
{
    int ppEntropy;
    string ppStrength;
    string pp = "My teacher is wonderful!";
    
    passwordCalc( pp, ppEntropy, ppStrength );
    
    CHECK( ppEntropy == 154 );
    CHECK( ppStrength == "Very Strong");
}
