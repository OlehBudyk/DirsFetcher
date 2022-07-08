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

	std::cout << std::endl;
	std::cout << "SOURCE FOLDER = " << inputPath.string() << std::endl;
	std::cout << "DESTINATION FOLDER = " << outputPath.string() << std::endl;
	std::cout << std::endl;

	int filesCount = 0;
	bool success = true;
	for (auto& dir : fs::recursive_directory_iterator(inputPath))
	{
		if (dir.is_regular_file())
		{
			try
			{
				fs::copy(dir, outputPath);
			}
			catch (...)
			{
				success = false;
				break;
			}

			std::cout << "#" << ++filesCount << " copied: " << dir.path().filename() << std::endl;
		}
	}


	std::cout << std::endl;

	if (success)
	{
		std::cout << "ALL FILES COPIED SUCCESSFULLY!" << std::endl;
		std::cout << "FILES COUNT : " << filesCount << std::endl;
	}
	else
		std::cout << "SOMETHING WENT WRONG!" << std::endl;

	return 0;
}
