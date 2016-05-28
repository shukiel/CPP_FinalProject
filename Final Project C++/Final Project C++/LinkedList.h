#ifndef __LINKEDLIST__H
#define __LINKEDLIST__H

#define MAX_SIZE 50

template <class T>
class LinkedList
{
private:
	T* m_arr;
	int m_size;

public:
	LinkedList(const T* arr, int size);
	LinkedList(const LinkedList& other);
	LinkedList();
	~LinkedList() { delete[] m_arr; }

	int getSize() const { return m_size; }

	T& operator[](int index) const { return m_arr[index]; }

	const LinkedList& operator=(const LinkedList& other);
	const LinkedList& operator+=(const T& newVal);

	void toOs(ostream& os) const;

	void deleteItem(int index);
};

template <class T>
LinkedList<T>::LinkedList(const T* arr, int size)
{
	m_size = 0;

	m_arr = new T[MAX_SIZE];
	for (int i = 0; i < size; i++)
		m_arr += arr[i];
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
	*this = other;
}

template <class T>
LinkedList<T>::LinkedList()
{
	m_size = 0;
	m_arr = new T[MAX_SIZE];
}

template <class T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
	if (this != &other)
	{
		m_size = 0;
		delete[] m_arr;
		m_arr = new T[MAX_SIZE];
		for (int i = 0; i < other.getSize(); i++)
			*this += other.m_arr[i];
	}
	return *this;
}

template <class T>
const LinkedList<T>& LinkedList<T>::operator+=(const T& newVal)
{
	if (m_size < MAX_SIZE)
	{
		m_arr[m_size] = newVal;
		m_size++;
	}
	return *this;
}

template <class T>
void LinkedList<T>::toOs(ostream& os) const
{
	for (int i = 0; i < getSize(); i++)
		os << "# " << i+1 << "	" << m_arr[i] << endl;
}

template <class T>
void LinkedList<T>::deleteItem(int index)
{
	for (int i = index; i < getSize() - 1; i++)
		m_arr[i] = m_arr[i + 1];
	m_size--;
}

#endif