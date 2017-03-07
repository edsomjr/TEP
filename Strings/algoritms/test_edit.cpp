#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "edit.h"

SCENARIO( "edit distance computation", "[string]" )
{
    GIVEN ( "two strings s and t" )
    {
        string s, t = "banana";

        WHEN ( "s is the empty string" )
        {
            s = "";

            THEN( "then the edit cost equals size of t insertions" )
            {
                c_i = 2;

                REQUIRE( edit(s, t) == c_i * t.size() );
                REQUIRE( edit2(s, t) == c_i * t.size() );

                t = "";

                REQUIRE( edit(s, t) == c_i * t.size() );
                REQUIRE( edit2(s, t) == c_i * t.size() );
            }
        }

        WHEN ( "t is the empty string" )
        {
            s = "bacanas";
            t = "";

            THEN( "then the edit cost equals size of s deletions" )
            {
                c_r = 3;

                REQUIRE( edit(s, t) == c_r * s.size() );
                REQUIRE( edit2(s, t) == c_r * s.size() );

                s = "";

                REQUIRE( edit(s, t) == c_r * s.size() );
                REQUIRE( edit2(s, t) == c_r * s.size() );
            }
        }

        WHEN ( "s and t are equals" )
        {
            s = "bacanas";
            t = s;

            THEN( "then the edit cost is zero" )
            {
                REQUIRE( edit(s, t) == 0 );
                REQUIRE( edit2(s, t) == 0 );
            }
        }

        WHEN ( "the costs are all equals" )
        {
            c_i = c_r = c_s = 7;

            s = "bacanas";
            t = "banana";

            THEN( "then the edit() is symmetrical" )
            {
                REQUIRE( edit(s, t) == edit(t, s) );
                REQUIRE( edit2(s, t) == edit2(t, s) );

                c_i = 1;
                c_r = 2;
                c_s = 3;

                REQUIRE( edit(s, t) != edit(t, s) );
                REQUIRE( edit2(s, t) != edit2(t, s) );
            }
        }

        WHEN ( "s and t have the same size and differs by only one character" )
        {
            s = "bacana";
            t = "banana";

            THEN( "then the edit cost equals one substitution" )
            {
                REQUIRE( edit(s, t) == c_s );
                REQUIRE( edit2(s, t) == c_s );
            }
        }

        WHEN ( "s has more characteres then t and all chars of t are in s" )
        {
            s = "aspectos";
            t = "seco";

            THEN( "then the edit cost equals to the neeed deletions" )
            {
                REQUIRE( edit(s, t) == c_r * (s.size() - t.size()) );
                REQUIRE( edit2(s, t) == c_r * (s.size() - t.size()) );
            }
        }

        WHEN ( "s has less characteres then t and all chars of s are in t" )
        {
            s = "fga";
            t = "formigas";

            THEN( "then the edit cost equals to the neeed insertions" )
            {
                REQUIRE( edit(s, t) == c_i * (t.size() - s.size()) );
                REQUIRE( edit2(s, t) == c_i * (t.size() - s.size()) );
            }
        }


    }
}

SCENARIO( "edit distance operations", "[string]" )
{
    GIVEN ( "two strings s and t" )
    {
        string s, t;

        WHEN ( "s is the empty string and t = \"banana\"" )
        {
            s = "";
            t = "banana";

            THEN( "then the edit operations equals \"banana\"" )
            {
                REQUIRE( edit_operations(s, t) == "banana" );
            }
        }

        WHEN ( "t is the empty string and s = \"banana\"" )
        {
            s = "banana";
            t = "";

            THEN( "then the edit operations equals \"xxxxxx\"" )
            {
                REQUIRE( edit_operations(s, t) == "xxxxxx" );
            }
        }
 
        WHEN ( "s and t are equals" )
        {
            s = "banana";
            t = s;

            THEN( "then the edit operations equals \"------\"" )
            {
                REQUIRE( edit_operations(s, t) == "------" );
            }
        }
 
        WHEN ( "s = \"banana\", t = \"bacana\" and costs are equals" )
        {
            s = "banana";
            t = "bacana";

            c_i = c_r = c_s = 1;

            THEN( "then the edit operations equals \"--[n->c]---\"" )
            {
                REQUIRE( edit_operations(s, t) == "--[n->c]---" );
            }
        }
 
        WHEN ( "s = \"aspectos\", t = \"seco\" and costs are equals" )
        {
            s = "aspectos";
            t = "seco";

            c_i = c_r = c_s = 1;

            THEN( "then the edit operations equals \"x-x--x-x\"" )
            {
                REQUIRE( edit_operations(s, t) == "x-x--x-x" );
            }
        }
 
        WHEN ( "s = \"fga\", t = \"formigas\" and costs are equals" )
        {
            s = "fga";
            t = "formigas";

            c_i = c_r = c_s = 1;

            THEN( "then the edit operations equals \"-ormi--s\"" )
            {
                REQUIRE( edit_operations(s, t) == "-ormi--s" );
            }
        }
 
        WHEN ( "s = \"fga\", t = \"formigas\" and costs are equals" )
        {
            s = "fga";
            t = "formigas";

            THEN( "then the edit operations are not symmetrical" )
            {
                REQUIRE( edit_operations(s, t) != edit_operations(t, s) );
            }
        }
    }
} 
