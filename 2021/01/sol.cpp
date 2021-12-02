#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>

auto get_next_val(std::ifstream& input)
{
    std::string next_val;
    if (std::getline(input, next_val))
    {
	return std::stoi(next_val);
    }

    return -1;    
}

auto compute_total_increases(std::ifstream& input)
{
    int previous { get_next_val(input) }, current { get_next_val(input) }, total { 0 };
    
    while (current != -1)
    {
	if (current > previous)
	{
	    total++;
	}

	previous = current;
	current = get_next_val(input);
    }

    return total;
}

auto compute_total_window_increases(std::ifstream& input)
{
    // windows are within four adjacent values in the list
    std::array<int, 4> values { 0 };
    for (int i = 0; i < 4; i++) values[i] = get_next_val(input);
    int total { 0 };
    
    while (values[3] != -1)
    {
	// compute the totals of the windows
	const auto previous { std::accumulate(values.begin(), values.begin() + 3, 0) };
	const auto current { std::accumulate(values.begin() + 1, values.end(), 0) };

	if (current > previous)
	{
	    total++;
	}

	std::shift_left(values.begin(), values.end(), 1);
	values.back() = get_next_val(input);	
    }

    return total;
}

int main()
{
    std::ifstream input { "input" };

    //const auto result { compute_total_increases(input) };
    const auto result { compute_total_window_increases(input) };
    std::cout << "result: " << result << '\n';
}
