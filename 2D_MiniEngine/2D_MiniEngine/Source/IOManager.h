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
	File ReadFile(const char* path);
	int WriteFile(void* buffer, size_t size, const char* path);
};