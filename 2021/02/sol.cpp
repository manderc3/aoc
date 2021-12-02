#include <fstream>
#include <string>
#include <utility>
#include <unordered_map>
#include <functional>
#include <iostream>

auto get_next_instruction(std::ifstream& input)
{
    std::string line { "" }; 
    
    if (std::getline(input, line))
    {
	const auto delimiter_pos = line.find(" ");

	return std::make_pair<std::string, int>
	(
	    line.substr(0, delimiter_pos),
	    std::stoi(line.substr(delimiter_pos + 1))
	);
    }

    return std::make_pair<std::string, int>("",  -1);
}

auto compute_travel_distance(std::ifstream& input)
{
    int horizontal { 0 }, depth { 0 };

    std::unordered_map<std::string, std::function<void(const int)>> actions
    {
	{ "up", [&depth] (const int steps) { depth -= steps; } },
	{ "down", [&depth] (const int steps) { depth += steps; } },
	{ "forward", [&horizontal] (const int steps) { horizontal += steps; } },
    };
     
    for (;;)
    {
	auto [direction, steps] = get_next_instruction(input);

	if (direction.empty())
	{
	    break;
	}

	actions[direction](steps);
    }

    return horizontal * depth;
}

int main()
{
    std::ifstream input { "input" };

    const auto result = compute_travel_distance(input);

    std::cout << "result: " << result << '\n';

    if (true)
    {
	int foo { 1 };
    }
}
