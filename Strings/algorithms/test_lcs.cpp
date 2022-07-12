#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "lcs.h"

SCENARIO( "longest common substring", "[string]" )
{
    GIVEN ( "two strings s and t" )
    {
        string s, t;

        WHEN ( "s or t is the empty string" )
        {
            s = "";
            t = "banana";

            THEN( "then the LCS has size zero" )
            {
                REQUIRE( lcs(s, t) == 0 );
                REQUIRE( lcs(t, s) == 0 );
                REQUIRE( lcs2(s, t) == 0 );
                REQUIRE( lcs2(t, s) == 0 );

                t = "";
                s = "bananada";

                REQUIRE( lcs(s, t) == 0 );
                REQUIRE( lcs(t, s) == 0 );
                REQUIRE( lcs2(s, t) == 0 );
                REQUIRE( lcs2(t, s) == 0 );
            }
        }

        WHEN ( "s and t are equals" )
        {
            s = "bacanas";
            t = s;

            THEN( "then the LCS size equals the size of s" )
            {
                REQUIRE( lcs(s, t) == s.size() );
                REQUIRE( lcs2(s, t) == s.size() );
            }
        }

        WHEN ( "s and t has no common characteres" )
        {
            s = "abcedfghijk";
            t = "123456";

            THEN( "then the LCS has size zero" )
            {
                REQUIRE( lcs(s, t) == 0 );
                REQUIRE( lcs2(s, t) == 0 );
            }
        }

        WHEN ( "t is a substring of s" )
        {
            s = "paralelepipedo";
            t = "lelepipe";

            THEN( "then LCS has size equals to the size of t" )
            {
                REQUIRE( lcs(s, t) == t.size() );
                REQUIRE( lcs2(s, t) == t.size() );
            }
        }

        WHEN ( "s = \"aspectos\" and t = \"seco\" " )
        {
            s = "aspectos";
            t = "seco";

            THEN( "then the LCS has size 4 (is equals to t)" )
            {
                REQUIRE( lcs(s, t) == 4 );
                REQUIRE( lcs2(s, t) == 4 );
            }
        }

        WHEN ( "s = \"zczazvxzvczbnbcvmczvdezxcvx\" and t = \"qewqaqbgfgdfgcdtwqertepioiqwetr\"" )
        {
            s = "zczazvxzvczbnbcvmczvdezxcvx";
            t = "qewqaqbgfgdfgcdtwqertepioiqwetr";

            THEN( "then the LCS has size 5 (LCS = \"abcde\" " )
            {
                REQUIRE( lcs(s, t) == 5 );
                REQUIRE( lcs2(s, t) == 5 );
            }
        }
    } 
}

SCENARIO( "LCS strings", "[string]" )
{
    GIVEN ( "two strings s and t" )
    {
        string s, t;

        WHEN ( "s is the empty string and t = \"banana\"" )
        {
            s = "";
            t = "banana";

            THEN( "then LCS equals \"\"" )
            {
                REQUIRE( lcs_str(s, t) == "" );
            }
        }

        WHEN ( "s and t are equals" )
        {
            s = "banana";
            t = s;

            THEN( "then LCS equals s" )
            {
                REQUIRE( lcs_str(s, t) == s );
            }
        }
 
        WHEN ( "s = \"banana\", t = \"bacana\"" )
        {
            s = "banana";
            t = "bacana";

            THEN( "then the LCS equals \"baana\"" )
            {
                REQUIRE( lcs_str(s, t) == "baana" );
            }
        }
 
        WHEN ( "s = \"aspectos\", t = \"seco\"" )
        {
            s = "aspectos";
            t = "seco";

            THEN( "then the LCS equals t" )
            {
                REQUIRE( lcs_str(s, t) == t );
            }
        }
 
        WHEN ( "s = \"fga\", t = \"formigas\"" )
        {
            s = "fga";
            t = "formigas";


            THEN( "then the LCS equals s" )
            {
                REQUIRE( lcs_str(s, t) == s );
            }
        }
 
        WHEN ( "s = \"zczazvxzvczbnbcvmczvdezxcvx\" and t = \"qewqaqbgfgdfgcdtwqertepioiqwetr\"" )
        {
            s = "zczazvxzvczbnbcvmczvdezxcvx";
            t = "qewqaqbgfgdfgcdtwqertepioiqwetr";

            THEN( "then the LCS equals \"abcde\" " )
            {
                REQUIRE( lcs_str(s, t) == "abcde" );
            }
        }
    } 
} 
