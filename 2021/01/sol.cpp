#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

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
	const auto previous { values[0] + values[1] + values[2] };
	const auto current { values[1] + values[2] + values[3] };

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
