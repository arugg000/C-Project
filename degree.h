/*The dgree header contains the enumerated data types*/
#pragma once
#include <string>

/*An enumeration is a distinct type whose value is restricted to a range of values. In this case Security, Network, and Software.*/
enum DegreeType 
{
    SECURITY,
    NETWORK,
    SOFTWARE
};

static const std::string degreeTypeStrings[] = 
{
    "SECURITY",
    "NETWORK",
    "SOFTWARE"
};
