#include <iostream>
#include <string>
#include <filesystem>

using std::string;
namespace fs = std::filesystem;

int main()
{
	string dirName;
	int subDirs;

	auto path = fs::current_path();

	std::cout << "Current path:\n" << path;

	std::cout << "\n\nDirectory name: ";
	std::cin >> dirName;
	std::cout << "# of sub-directories: ";
	std::cin >> subDirs;

	if (!fs::create_directory(dirName))
	{
		std::cout << "\n\nFailed to create main directory.\n";
	}
	else
	{
		fs::current_path(dirName);

		bool test = false;
		for (int i = 1; i <= subDirs; i++)
		{
			if (i < 10)
			{
				if (!fs::create_directory("0" + std::to_string(i)))
				{
					test = true;
				}
			}
			else
			{
				if (!fs::create_directory(std::to_string(i)))
				{
					test = true;
				}
			}
		}

		if (test)
		{
			std::cout << "Failed to create sub-directories.\n";
		}
		else
		{
			std::cout << "\nProcess completed successfully.\n";
		}
	}

	std::cout << "Press enter to exit...";
	std::cin.ignore();
	std::cin.get();
	return 0;
}
