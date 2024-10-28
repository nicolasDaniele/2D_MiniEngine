#include "IOManager.h"
#include <errno.h>
#include <stdlib.h>

#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>

#define IO_READ_CHUNK_SIZE 2097152
#define IO_READ_ERROR_GENERAL "Error reading file: %s. errno: %d\n"
#define IO_READ_ERROR_MEMORY "Not enough free memory to read file: %s\n"

File IOManager::ReadFile(const char* path)
{
	File file = File();

	FILE* fp;
	errno_t openResult = fopen_s(&fp, path, "r");
	if (!fp || ferror(fp)) {
		printf("Failed to open file: %s. %dz", path, openResult);
		return file;
	}

	char* data = NULL;
	char* tmp;
	size_t used = 0;
	size_t size = 0;
	size_t n;

	while (true) {
		if (used + IO_READ_CHUNK_SIZE + 1 > size) {
			size = used + IO_READ_CHUNK_SIZE + 1;

			if (size <= used) {
				free(data);
				printf("Input file too large: %s\n", path);
				return file;
			}

			tmp = (char*)realloc(data, size);
			if (!tmp) {
				free(data);
				printf(IO_READ_ERROR_MEMORY, path);
				return file;
			}
			data = tmp;
		}

		n = fread(data + used, 1, IO_READ_CHUNK_SIZE, fp);
		if (n == 0) {
			break;
		}

		used += n;
	}

	if (ferror(fp)) {
		free(data);
		printf(IO_READ_ERROR_GENERAL, path, errno);
		return file;
	}

	tmp = (char*)realloc(data, used + 1);
	if (!tmp) {
		free(data);
		printf(IO_READ_ERROR_MEMORY, path);
		return file;
	}

	data = tmp;
	data[used] = 0;

	file.data = data;
	file.lenght = used;
	file.isValid = true;

	return file;
}

int IOManager::WriteFile(void* buffer, size_t size, const char* path)
{
	FILE* fp;
	errno_t openResult = fopen_s(&fp, path, "w");
	if (!fp || ferror(fp)) {
		printf("Cannot write file: %s\n", path);
		return -1;
	}

	size_t chunks_written = fwrite(buffer, size, 1, fp);
	fclose(fp);

	if (chunks_written != 1) {
		printf("Write error: Expected 1 chunk, got %zu\n", chunks_written);
		return -1;
	}

	return 0;
}