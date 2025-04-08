#pragma once

struct File
{
	char* data;
	size_t lenght;
	bool isValid;

	File()
	{
		data = nullptr;
		lenght = 0;
		isValid = false;
	}
};

class IOManager
{
public:
	static File ReadFile(const char* path);
	static int WriteFile(void* buffer, size_t size, const char* path);
};