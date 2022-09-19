#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T, typename T1 = int >
class Array
{
private:
	T1 m_length;
	T* m_data;
public:
	Array() = default;

	Array(T1 length, T* arr)
	{
		m_length = length;
		if (length < 0)
		{
			throw "exception";
		}
		m_data = new T[m_length];
		for (int index = 0; index < length; ++index)
		{
			m_data[index] = arr[index];
		}
	}

	~Array()
	{
		delete[]m_data;
	};


	void Erase()
	{
		delete[]m_data;
		m_data = nullptr;
		m_length = 0;
	};

	int& operator[](T1 index)
	{
		if (index < 0 || index > m_length)
		{
			throw "exception";
		}
	};
	auto getLength() const
	{
		return m_length;
	};

	void Reallocate(T1 newLength)
	{
		if (newLength < 0)
		{
			throw "Exception";
		}
		Erase();

		m_data = new T [newLength];
		m_length = newLength;
	};

	void Resize(T1 newSize)
	{

	};

	void InsertBefore(T value, T1 index)
	{
		if (index > m_length || index < 0)
		{
			throw "Exception";
		}
		auto* data = new T [m_length + 1];
		for (auto before = 0; before < index; before++)
		{
			data[before] = m_data[before];
		}

		data[index] = value;

		for (auto after = index; after < m_length; ++after)
		{
			data[after + 1] = m_data[after];
		}

		delete[] m_data;
		m_data = data;
		++m_length;

	};

	void RemoveElement(T1 index)
	{
		if (index > m_length)
		{
			throw "Exception";
		}
		if (index < 0)
		{
			throw "Exception";
		}

		if (m_length == 1)
		{
			Erase();
			return;
		}

		auto* data = new T [m_length - 1];

		for (auto before = 0; before < index; ++before)
		{
			data[before] = m_data[before];
		}

		for (int after = index; after < m_length; ++after)
		{
			data[after - 1] = m_data[after];
		}

		delete[] m_data;
		m_data = data;
		--m_length;

	};
	void insertAtBeginning(T value)
	{
		InsertBefore(value, 0);

	};
	void insertAtEnd(T value)
	{
		InsertBefore(value, m_length);
	};



	void findElementWithIndex(T1 index)
	{
		if (index > m_length)
		{
			throw " Exception";
		}
		if (index < 0)
		{
			throw " Exception";
		}
		std::cout << m_data[index] << std::endl;
	};


	void getArray()
	{
		std::cout << "Array: " << std::endl;
		for (auto i = 0; i < getLength(); ++i)
		{
			std::cout << m_data[i] << ' ';
		}
		std::cout << std::endl;
	}

};