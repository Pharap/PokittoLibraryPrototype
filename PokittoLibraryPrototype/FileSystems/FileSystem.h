#pragma once

#include "ErrorCode.h"

namespace Pokitto
{
	namespace FileSystem
	{
		using SizeType = std::uintmax_t;

		bool create(const char * path);
		bool create(const char * path, ErrorCode & errorCode);

		bool exists(const char * path);
		bool exists(const char * path, ErrorCode & errorCode);

		bool delete(const char * path);
		bool delete(const char * path, ErrorCode & errorCode);

		bool deleteDirectoryUnlessEmpty(const char * path);
		bool deleteDirectoryUnlessEmpty(const char * path, ErrorCode & errorCode);

		SizeType getFileSize(const char * path);
		SizeType getFileSize(const char * path, ErrorCode & errorCode);

		bool copy(const char * sourcePath, const char * destinationPath);
		void copy(const char * sourcePath, const char * destinationPath, ErrorCode & errorCode);

		bool move(const char * sourcePath, const char * destinationPath);
		void move(const char * sourcePath, const char * destinationPath, ErrorCode & errorCode);

		bool copyUnlessExists(const char * sourcePath, const char * destinationPath);
		void copyUnlessExists(const char * sourcePath, const char * destinationPath, ErrorCode & errorCode);

		bool moveUnlessExists(const char * sourcePath, const char * destinationPath);
		void moveUnlessExists(const char * sourcePath, const char * destinationPath, ErrorCode & errorCode);

		bool copyIfNewer(const char * sourcePath, const char * destinationPath);
		void copyIfNewer(const char * sourcePath, const char * destinationPath, ErrorCode & errorCode);

		bool moveIfNewer(const char * sourcePath, const char * destinationPath);
		void moveIfNewer(const char * sourcePath, const char * destinationPath, ErrorCode & errorCode);


	}
}