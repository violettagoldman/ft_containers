#include "Utils.hpp"

# define BOLD "\033[1m"
# define NONE "\033[00m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define UNDERLINE "\033[4m"


void	print_title(int type)
{
	switch (type)
	{
	case 0:
		std::cout << BOLD << UNDERLINE << PURPLE << "Vector" << NONE << std::endl;
		break;
	case 1:
		std::cout << BOLD << UNDERLINE << PURPLE << "Stack" << NONE << std::endl;
		break;
	case 2:
		std::cout << BOLD << UNDERLINE << PURPLE << "Map" << NONE << std::endl;
		break;
	default:
		break;
	}
}

void	check(std::string name, bool result)
{
	if (result == true)
		std::cout << name << " succeeded ✅" << NONE << std::endl;
	else
		std::cout << name << " failed ❌" << NONE << std::endl;
}