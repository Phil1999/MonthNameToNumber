#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>


std::string makeLower(const std::string& input)
{
    std::string lowercaseStr = input;

    std::transform(lowercaseStr.begin(), lowercaseStr.end(), lowercaseStr.begin(),
        [](unsigned char c) { return std::tolower(c); });

    return lowercaseStr;
}



int main()
{
    std::string month;

    bool stop = false;
    
    std::map<std::string, std::pair<int, int>> months{
        {"january", {1, 31}},
        {"jan", {1, 31}},
        {"february", {2, 28}},  // This does not account for leap years
        {"feb", {2, 28}},  // This does not account for leap years
        {"march", {3, 31}},
        {"mar", {3, 31}},
        {"april", {4, 30}},
        {"apr", {4, 30}},
        {"may", {5, 31}},
        {"june", {6, 30}},
        {"jun", {6, 30}},
        {"july", {7, 31}},
        {"jul", {7, 31}},
        {"august", {8, 31}},
        {"aug", {8, 31}},
        {"september", {9, 30}},
        {"sept", {9, 30}},
        {"october", {10, 31}},
        {"oct", {10, 31}},
        {"november", {11, 30}},
        {"nov", {11, 30}},
        {"december", {12, 31}},
        {"dec", {12, 31}}
    };

    std::map<int, std::string> monthOrdinals{
        {1, "first"},
        {2, "second"},
        {3, "third"},
        {4, "fourth"},
        {5, "fifth"},
        {6, "sixth"},
        {7, "seventh"},
        {8, "eighth"},
        {9, "ninth"},
        {10, "tenth"},
        {11, "eleventh"},
        {12, "twelfth"}
    };


    while (!stop)
    {
        std::cout << "Please enter a month or 0 to stop: ";
        std::cin >> month;

        month = makeLower(month);

        if (month == "0")
        {
            stop = true;
            continue;
        }


        if (months.count(month) > 0)
        {
            std::cout << "The ordinal equivalent of " << month << " is: " << monthOrdinals[months[month].first] << "." << std::endl;
            std::cout << "There are " << months[month].second << " days in " << month << "." << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Sorry '" << month << "' wasn't recognized, please try something like 'january' or 'jan'." << std::endl;
            std::cout << std::endl;
        }
    }
    
    
    return 0;
}