#include <fstream>
#include <iostream>

int main()
{
    std::ifstream input("input.txt");
    std::string content((std::istreambuf_iterator<char>(input)), (std::istreambuf_iterator<char>()));

    int floor { 0 };

    //// Part 1
    // for (const auto i : content)
    // {
    // 	if (i == '(')      ++floor;
    // 	else if (i == ')') --floor;
    // }

    // std::cout << "You are on floor " << floor << "\n";

    //// Part 2
    for (std::size_t i = 0; i < content.size(); ++i)
    {
	if (floor == -1)
	{
	    std::cout << "First entered the floor at pos " << i << "\n";
	}
	
	if (content[i] == '(')      ++floor;
	else if (content[i] == ')') --floor;
    }
}
