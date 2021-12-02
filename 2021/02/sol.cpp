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

template<typename params>
using action_map = std::unordered_map<std::string, std::function<void(params&, const int)>>;

template<typename params>
auto compute_travel_distance(std::ifstream& input, const action_map<params>& a_map, params& p)
{
    for (;;)
    {
	const auto [direction, steps] = get_next_instruction(input);

	if (direction.empty())
	{
	    break;
	}

	a_map.at(direction)(p, steps);
    }

    return p.horizontal * p.depth;
}

int main()
{
    std::ifstream input { "input" };

    // struct params_a { int depth { 0 }, horizontal { 0 }; } p_a;
    // const action_map<params_a> actions_a
    // {
    // 	{ "up", [] (params_a& p, const int steps) { p.depth -= steps; } },
    // 	{ "down", [] (params_a& p, const int steps) { p.depth += steps; } },
    // 	{ "forward", [] (params_a& p, const int steps) { p.horizontal += steps; } },
    // };

    // const auto result_a = compute_travel_distance(input, actions_a, p_a);
    // std::cout << "result_a: " << result_a << '\n';

    struct params_b { int depth { 0 }, horizontal { 0 }, aim { 0 }; } p_b;
    const action_map<params_b> actions_b
    {
	{ "up", [] (params_b& p, const int units) { p.aim -= units; } },
	{ "down", [] (params_b& p, const int units) { p.aim += units; } },
	{ "forward", [] (params_b& p, const int units) { p.horizontal += units; p.depth += p.aim * units; } },
    };

    const auto result_b = compute_travel_distance(input, actions_b, p_b);
    std::cout << "result_b: " << result_b << '\n';
}
