#pragma once

#include <cstddef>
#include <cstdint>
#include <iterator>

class File
{
public:
	using SizeType = std::uintmax_t;

private:

public:
	File(const char * path);
	File(const File & other) = delete;
	File(File && other);
	~File();

	File & operator =(const & other) = delete;
	File & operator =(File && other);

	bool isOpen() const;

	SizeType size() const;
	SizeType position() const;

	std::size_t read(char * buffer, std::size_t size);
	std::size_t read(void * buffer, std::size_t size);

	std::size_t write(const char * buffer, std::size_t size);
	std::size_t write(const void * buffer, std::size_t size);

	template<typename Type>
	bool read(Type & object)
	{
		constexpr std::size_t bytes = sizeof(Type);

		return (this->read(&object, bytes) == bytes);
	}

	template<typename Type, std::size_t size>
	bool read(Type (&array)[size])
	{
		constexpr std::size_t bytes = (size * sizeof(Type));

		return (this->read(&array, bytes) == bytes);
	}

	/// `OutputIterator` must meet the requirements of LegacyOutputIterator.
	/// https://en.cppreference.com/w/cpp/named_req/OutputIterator
	template<typename OutputIterator>
	bool read(OutputIterator first, OutputIterator last)
	{
		for(auto iterator = first; iterator != last; ++iterator)
			if(!this->read(*iterator))
				return false;

		return true;
	}

	template<typename Type>
	bool write(const Type & object)
	{
		constexpr std::size_t bytes = sizeof(Type);

		return (this->write(&object, bytes) == bytes);
	}

	template<typename Type, std::size_t size>
	bool write(const Type (&array)[size])
	{
		constexpr std::size_t bytes = (size * sizeof(Type));

		return (this->write(&array, bytes) == bytes);
	}

	/// `InputIterator` must meet the requirements of LegacyInputIterator.
	/// https://en.cppreference.com/w/cpp/named_req/InputIterator
	template<typename InputIterator>
	bool write(InputIterator first, InputIterator last)
	{
		for(auto iterator = first; iterator != last; ++iterator)
			if(!this->write(*iterator))
				return false;

		return true;
	}
};