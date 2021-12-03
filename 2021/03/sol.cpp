#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdint>

constexpr int report_entry_width { 12 };
constexpr int report_entry_count { 1000 };
constexpr int report_size { report_entry_count * report_entry_width };

using report = std::array<bool, report_size>;

auto get_report(std::ifstream& input)
{
    report rpt { 0 };
    int rpt_pos { 0 };
    std::string line { };
    
    while (std::getline(input, line))
    {
	for (const auto c : line)
	{
	    rpt[rpt_pos++] = c == '1';
	}
    }

    return rpt;
}

auto get_power_consumption(const report& rpt)
{
    std::int16_t gamma { 0 }, epsilon { 0 };
    int one_count { 0 }, zero_count { 0 };
    
    for (int i = 0; i < rpt.size(); i++)
    {
	if (i % report_entry_width == 0)
	{
	    // assuming they're never equal
	    if (one_count > zero_count)
	    {
		// how do I populate gamma and epsilon
	    }
	    else
	    {

	    }

	    one_count = zero_count = 0;
	}
	
    }

    return 0;
}

int main()
{
    std::ifstream input { "input" };
    const auto consumption { get_power_consumption(get_report(input)) };
    std::cout << "Power consumption: " << consumption << '\n';
}
