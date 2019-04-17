#include "DynamicVector.h"

/*
template<class Type>
DynamicVector<Type>::DynamicVector(int capacity)
{
	this->elements = new Type[capacity];
	this->capacity = capacity;
	this->size = 0;
}

template<class Type>
void DynamicVector<Type>::resize()
{
	Type *auxiliaryElements;

	this->capacity += 100;
	auxiliaryElements = new Type[this->capacity];
	for (int i = 0; i < this->size; i++)
		auxiliaryElements[i] = this->elements[i];
	delete[] this->elements;
	this->elements = auxiliaryElements;
}

template<class Type>
void DynamicVector<Type>::removeElement(Type element)
{
	int start;

	start = -1;
	for (int i = 0; i < this->size; i++)
	{
		if (this->elements[i] == element)
		{
			start = i;
			break;
		}
	}
	if (start != -1)
	{
		for (i = start; i < this->size - 1; i++)
			this->elements[i] = this->elements[i + 1];
		this->size--;
	}
}

template<class Type>
void DynamicVector<Type>::removeElement(int position)
{
	if (position < 0 || position >= this->size)
		throw std::exception("Invalid position given for remove. Source: DynamicVector.");
	for (int index = position; index < this->size - 1; index++)
		this->elements[index] = this->elements[index + 1];
	this->size--;
}

template<class Type>
void DynamicVector<Type>::updateElement(Type element, int position)
{
	if (position < 0 || position >= this->size)
		throw std::exception("Invalid position given for update. Source: DynamicVector.");
	this->elements[position] = element;
}

template<class Type>
int DynamicVector<Type>::getPositionElement(Type element)
{
	int position;

	position = -1;
	for (int index = 0; index < this->size; index++)
		if (this->elements[index] == element)
		{
			position = index;
			break;
		}
	return position;
}

template<class Type>
Type DynamicVector<Type>::getElement(int position)
{
	if (position < 0 || position >= this->size)
		throw std::exception("Invalid position given for get element. Source: DynamicVector.");
	return this->elements[position];
}

template<class Type>
int DynamicVector<Type>::getSize() const
{
	return this->size;
}

template<class Type>
Type * DynamicVector<Type>::getAllElements() const
{
	return this->elements;
}

template<class Type>
void DynamicVector<Type>::addElement(Type element)
{
	if (this->size == this->capacity)
		this->resize();
	this->elements[this->size] = element;
	this->size++;
}

template<class Type>
DynamicVector<Type>::~DynamicVector()
{
	delete[] this->elements;
}
*/