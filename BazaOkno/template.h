#pragma once
#ifndef TEMPLATE_H
#define TEMPLATE_H
#include "template.h"
#include <cstddef>

template <typename T, typename V>
class table
{
public:
	T data; //поле с информацией
	V *next; // указатели
	V *prev; // на соседние элементы
	table(); // конструктор
	V *inputfile(V*, const char*); // ввод из файла
	void outputfile(V*, const char*); // вывод в файл
	V *push(V*, V*); // добавление элемента в список
	V* search_id(V *, int); // поиск по Id
	V* request_comboBox(V*, int); // поиск по форме
	V* del(V*, V*); // удаление элемента
};

template <typename T, typename V>
V *table<T, V>::inputfile(V *a, const char *filename)
{
	V *c = new V();
	std::fstream F;
	char line[255];
	F.open(filename, std:: ios::in);
	if (F)
	{
		do
		{
			F.getline(line, 255);
			c = input_(c, line);
			a = c->push(a, c);
			c = new V();
		} while (!F.eof());
		F.close();

	}
	return(a);
}

template <typename T, typename V>
void table<T, V>::outputfile(V*c, const char *filename)
{
	std::fstream F;
	char line[255];
	int i = 1;
	F.open(filename, std::ios::out);
	while (c->next != NULL)
	{
		output_(c, line, i);
		F << line;
		c = c->next;
	} 
	if (c->next == NULL)
	{
		i = 0;
		output_(c, line, i);
		F << line;
	}
	F.close();
}

template <typename T, typename V>
inline V *table<T, V>::search_id(V *a, int id)
{
	while (a->data.id != id)
	{
		a = a->next;
	}
	return(a);
}

template <typename T, typename V>
inline V *table<T, V>::request_comboBox(V *a, int i)
{
	for (int j = 0; j < i; j++)
	{
		a = a->next;
	}
	return(a);
}

template <typename T, typename V>
inline table<T, V>::table()
{
	this->next = NULL;
	this->prev = NULL;
}

template <typename T, typename V>
inline V *table<T, V>::push(V*a, V*c)
{
	V *b = a;
	if (b != NULL)
	{
		while (b->next != NULL)
			b = b->next;
	}
	if (a == NULL)
		a = c;
	else
	{
		if (b != NULL)
			b->next = c;
		c->next = NULL;
		c->prev = b;
	}
	return(a);
}

template <typename T, typename V>
inline  V *table<T, V>::del(V *c, V *d)  // udalenie elementa
{
	if (d->prev == NULL && d->next != NULL)  //esli d- perviy element
	{
		c = d->next;
		d->next->prev = NULL;
		return(c);
	}
	if (d->prev != NULL && d->next == NULL)  //esli d- posledniy element
	{
		d->prev->next = NULL;
		return(c);
	}
	if (d->prev != NULL && d->next != NULL)  //esli d- element v seredine
	{
		d->next->prev = d->prev;
		d->prev->next = d->next;
		return(c);
	}
	if (d->prev == NULL && d->next == NULL)
	{
		c = NULL;
		return(0);
	}
}

#endif 