#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <string>

struct rec { int l, w, h; };

int main()
{    
    std::ifstream input("input.txt");
    std::string line;

    int paper_total { 0 };
    int ribbon_total { 0 };
    
    while(std::getline(input, line))
    {
	auto r = rec();
	
	for (std::int8_t i = 0; i < 3; i++)
	{
	    auto pos = line.find('x');
	    
	    switch(i)
	    {
	    case 0: r.l =  std::atoi(line.substr(0, pos).c_str()); break;
	    case 1: r.w =  std::atoi(line.substr(0, pos).c_str()); break;
	    default: r.h = std::atoi(line.substr(0, pos).c_str()); break;
	    }

	    line.erase(0, pos + 1);	    
	}

	const std::array<int, 3> foo
	{
	    r.l * r.w,
	    r.w * r.h,
	    r.h * r.l
	};
	
	paper_total += 2 * foo[0] + 2 * foo[1] + 2 * foo[2] + *(std::min_element(foo.begin(), foo.end()));

	ribbon_total += r.l * 2 + r.w * 2 + r.l * r.w * r.h; 
    }

    std::cout << "Total of wrapping paper: " << paper_total << '\n';
    std::cout << "Total length of ribbon: " << ribbon_total << '\n';
}
