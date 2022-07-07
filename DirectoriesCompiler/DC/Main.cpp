#include <iostream>
#include <conio.h>
#include <filesystem>

int main(int argc, char* argv[])
{
	namespace fs = std::filesystem;

	if (argc != 3)
	{
		std::cout << "Wrong Program arguments!" << std::endl;
		return 0;
	}

	fs::path inputPath(argv[1]);
	fs::path outputPath(argv[2]);

	std::cout << "SOURCE FOLDER = " << inputPath.string() << std::endl;
	std::cout << "DESTINATION FOLDER = " << outputPath.string() << std::endl;
	std::cout << std::endl;

	for (auto const& dir : fs::recursive_directory_iterator(inputPath))
	{
		if (dir.is_regular_file())
			std::cout << dir.path().filename() << std::endl;

	}

	_getch();
	return 0;
}
