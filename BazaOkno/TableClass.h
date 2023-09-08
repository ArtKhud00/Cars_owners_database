#pragma once
#ifndef TABLECLASS_H
#define TABLECLASS_H
#define _CRT_SECURE_NO_WARNINGS
#include "template.h"
#include <fstream>


typedef struct Models_
{
	int id;
	char Model[20];//название марки
}MODELS;
class Models :public table<MODELS,Models>
{
public:
	Models()
	{
		this->next = NULL;
		this->prev = NULL;
	};
	~Models()
	{};
};

typedef struct Type_of_fine_
{
	int id;
	char typeoffine[65];
}TYPESFINE;
class Typesfine :public table <TYPESFINE, Typesfine>
{
public:
	Typesfine()
	{
		this->next = NULL;
		this->prev = NULL;
	}
	~Typesfine()
	{};
};

typedef struct Owner_
{
	int id;
	char surname[20];//фамили€
	char name1[20];//им€ 
	char patronymic[30];//отчество
	char gender[20];//пол
	int day;//день
	int month;//мес€ц
	int year;//год
	char address[100];//адрес
}OWNER;
class Owner1:public table<OWNER,Owner1>
{
public:
	Owner1()
	{
		this->next = NULL;
		this->prev = NULL;
	};
	~Owner1()
	{};
};

typedef struct Car_
{
	int id;
	Models* idmodel; // id марки
	char currentmodel[50];// конкретна€ модель
	int year_of_issue;//год выпуска
	char platecar[10];// гос.номер
	Owner1 *id_current_owner;// id текущего владельца
	char color[20];//цвет
	int enginepower;// мощность двигател€
}CAR;
class Car :public table <CAR, Car>
{
public:
	Car()
	{
		this->next = NULL;
		this->prev = NULL;
	};
	Car* Carreadf(const char*, Models*, Owner1*);
};

typedef struct Fines_
{
	int id;
	Car *idcar;//id авто
	Owner1 *idowner;// id владельца
	Typesfine *idtype; // id вида штрафа
	int day;//день
	int month;//мес€ц
	int year;//год
	char status[11];//статус штрафа
}FINE;
class Fine :public table<FINE, Fine>
{
public:
	Fine()
	{
		this->next = NULL;
		this->prev = NULL;
	};
	~Fine()
	{};
	Fine* Finereadf(const char*, Car*, Owner1*, Typesfine*);
	Fine* carfine(Fine*, int);
};

typedef struct Changeow_
{
	int id;
	Owner1 *idow;//id владельца
	int day;//день
	int month;//мес€ц 
	int year;//год
	Car *idcar;// id авто
}CHANGEOW;
class Changeow : public table<CHANGEOW, Changeow>
{
public:
	Changeow()
	{
		this->next = NULL;
		this->prev = NULL;
	};
	~Changeow()
	{};
	Changeow* changeowr(const char*, Owner1*, Car*);
	Changeow* humancars(Changeow*, int);
	Changeow* carowners(Changeow*, int);
	void lastcarowner(Changeow*, Car*, const char*, Owner1*);
};




Models* input_(Models *mod, char *line)
{
	sscanf(line, "%d" "%s", &mod->data.id, mod->data.Model);
	return(mod);
}
void output_(Models *mod, char *fg, int i)
{
	if (i != 0)
		sprintf(fg, "%d " "%s\n", mod->data.id, mod->data.Model);
	else
		sprintf(fg, "%d " "%s", mod->data.id, mod->data.Model);
}


Owner1* input_(Owner1 *ow, char *line)
{
	sscanf(line,"%d" "%s" "%s" "%s" "%s" "%d" "%d" "%d" "%s", &ow->data.id, ow->data.surname, ow->data.name1, ow->data.patronymic, ow->data.gender, &ow->data.day, &ow->data.month, &ow->data.year, ow->data.address);
	return(ow);
}
void output_(Owner1 *c, char *line, int i)
{
	if (i != 0)
		sprintf(line, "%d " "%s " "%s " "%s " "%s " "%d " "%d " "%d " "%s\n", c->data.id, c->data.surname, c->data.name1, c->data.patronymic, c->data.gender, c->data.day, c->data.month, c->data.year, c->data.address);
	else
		sprintf(line, "%d " "%s " "%s " "%s " "%s " "%d " "%d " "%d " "%s", c->data.id, c->data.surname, c->data.name1, c->data.patronymic, c->data.gender, c->data.day, c->data.month, c->data.year, c->data.address);

}


Car* Car::Carreadf(const char* Filename, Models* m, Owner1* o)
{
	Car *spisok,*c;
	int idc,ido;
	spisok = NULL;
	std::fstream F;
	F.open(Filename);
	while (!F.eof())
	{
		c = new Car();
		if (!F.eof())
			F >> c->data.id >> idc >> c->data.currentmodel >> c->data.year_of_issue >> c->data.platecar >> ido >> c->data.color >> c->data.enginepower;
		c->data.idmodel = m->search_id(m, idc);
		c->data.id_current_owner = o->search_id(o, ido);
		spisok = push(spisok, c);
	}
	return(spisok);
}
void output_(Car *c, char *line, int i)
{
	if (i != 0)
		sprintf(line, "%d " "%d " "%s " "%d " "%s " "%d " "%s " "%d\n", c->data.id, c->data.idmodel->data.id, c->data.currentmodel, c->data.year_of_issue, c->data.platecar, c->data.id_current_owner->data.id, c->data.color, c->data.enginepower);
	else
		sprintf(line, "%d " "%d " "%s " "%d " "%s " "%d " "%s " "%d", c->data.id, c->data.idmodel->data.id, c->data.currentmodel, c->data.year_of_issue, c->data.platecar, c->data.id_current_owner->data.id, c->data.color, c->data.enginepower);
}


Typesfine* input_(Typesfine* t, char *line)
{
	sscanf(line, "%d" "%s", &t->data.id, t->data.typeoffine);
	return(t);
}
void output_(Typesfine *t, char *line, int i)
{
	if (i != 0)
		sprintf(line, "%d " "%s\n", t->data.id, t->data.typeoffine);
	else
		sprintf(line, "%d " "%s", t->data.id, t->data.typeoffine);
}


Fine* Fine::Finereadf(const char* filename, Car* k, Owner1* o, Typesfine* t)
{
	Fine *spisok,*c;
	int idc, ido, idt;
	spisok = NULL;
	std::fstream F;
	F.open(filename);
	while (!F.eof())
	{
		c = new Fine();
		if (!F.eof())
			F >> c->data.id >> idc >> ido >> idt >> c->data.day >> c->data.month >> c->data.year >> c->data.status;
		c->data.idcar = k->search_id(k, idc);
		c->data.idowner = o->search_id(o, ido);
		c->data.idtype = t->search_id(t, idt);
		spisok = push(spisok, c);
	}
	return(spisok);
}
void output_(Fine *f, char *line, int i)
{
	if (i != 0)
		sprintf(line, "%d " "%d " "%d " "%d " "%d " "%d " "%d " "%s\n", f->data.id, f->data.idcar->data.id, f->data.idowner->data.id, f->data.idtype->data.id, f->data.day, f->data.month, f->data.year, f->data.status);
	else
		sprintf(line, "%d " "%d " "%d " "%d " "%d " "%d " "%d " "%s", f->data.id, f->data.idcar->data.id, f->data.idowner->data.id, f->data.idtype->data.id, f->data.day, f->data.month, f->data.year, f->data.status);
}
Fine* Fine::carfine(Fine* fin, int id)
{
	Fine *c, *d, *f;
	c = fin;
	d = fin;
	while (c!= NULL)
	{
		if (c->data.idcar->data.id != id)
			d = del(d, c);
		c = c->next;
	} 
	f = d;
	return(d);
}


Changeow* Changeow::changeowr(const char *filename, Owner1 *o, Car* k)
{
	Changeow *spisok;
	Changeow *c;
	int ido, idc;
	spisok = NULL;
	std::fstream F;
	F.open(filename);
	while (!F.eof())
	{
		c = new Changeow();
		if (!F.eof())
			F >> c->data.id >> ido >> c->data.day >> c->data.month >> c->data.year >> idc;
		c->data.idow = o->search_id(o, ido);
		c->data.idcar = k->search_id(k, idc);
		spisok = push(spisok, c);
	}
	return(spisok);
}
void output_(Changeow *ch, char *line, int i)
{
	if (i != 0)
		sprintf(line, "%d " "%d " "%d " "%d " "%d " "%d\n", ch->data.id, ch->data.idow->data.id, ch->data.day, ch->data.month, ch->data.year, ch->data.idcar->data.id);
	else
		sprintf(line, "%d " "%d " "%d " "%d " "%d " "%d", ch->data.id, ch->data.idow->data.id, ch->data.day, ch->data.month, ch->data.year, ch->data.idcar->data.id);
}
Changeow* Changeow::humancars(Changeow *ch, int id)
{
	Changeow *d, *g, *f;
	g = ch;
	d = ch;
	while (g != NULL)
	{
		if (g->data.idow->data.id != id)
			d = del(d, g);
		g = g->next;
	} 
	f = d;
	return(d);
}
Changeow* Changeow::carowners(Changeow *ch, int id)
{
	Changeow *d, *g, *f;
	g = ch;
	d = ch;
	while (g != NULL)
	{
		if (g->data.idcar->data.id != id)
			d = del(d, g);
		g = g->next;
	} 
	f = d;
	return(d);
}
void Changeow::lastcarowner(Changeow *ch, Car *gg, const char *filename, Owner1 *o)
{
	Changeow *s, *f, *q, *q1, *h;
	Car *k = gg;
	int idc;
	s = ch;
	f = ch;
	while (k != NULL)
	{
		idc = k->data.id;
		f = carowners(ch, idc);
		q = f;
		q1 = f;
		while (q->next!= NULL)
		{
			q1 = q->next;
			if (q->data.year > q1->data.year)
			{
				f = del(f, q1);
				q = f;
			}
			else
			{
				if (q->data.year < q1->data.year)
				{
					f = del(f, q);
					q = f;
					h = f;
				}
				else
				{
					if (q->data.year == q1->data.year)
					{
						if (q->data.month > q1->data.month)
						{
							f = del(f, q1);
							q = f;
						}
						if (q->data.month < q1->data.month)
						{
							f = del(f, q);
							q = f;
						}
						if (q->data.month == q1->data.month)
						{
							if (q->data.day > q1->data.day)
							{
								f = del(f, q1);
								q = f;
							}
							if (q->data.day < q1->data.day)
							{
								f = del(f, q);
								q = f;
							}
						}
					}
				}
			}
		}
		k->data.id_current_owner = f->data.idow;
		k = k->next;
		ch = ch->changeowr(filename, o, gg);
	}
}




//void Changeow::lastcarowner(Changeow *ch, Car *k, const char *filename, Owner *o, Car *sp)
//{
//	Changeow *s, *f, *q, *q1,*h,*c;
//	int idc,fl;
//	s = ch;
//	f = ch;
//	fl = 0;
//	std::cout << "ju" << std::endl;
//	while (k != NULL)
//	{
//		//std::cout << "jgt" << std::endl;
//		idc = k->data.id;
//		std::cout << idc << std::endl;
//		f = carowners(ch, idc);
//		q = f;
//		q1 = q;
//		c = f;
//		while (q1!= NULL)
//		{
//			fl = 0;
//			std::cout << "jgt" << std::endl;
//			while (fl == 0)
//			{
//				if (q1->data.year > c->data.year)
//				{
//					c = q1;
//					std::cout << "1" << c->data.idow->data.surname << std::endl;
//					fl = 1;
//				}
//				if (q1->data.year == c->data.year)
//				{
//					if (q1->data.month > c->data.month)
//					{
//						c = q1;
//						std::cout << "2" << c->data.idow->data.surname << std::endl;
//						fl = 1;
//					}
//					if (q1->data.month == c->data.month)
//					{
//						if (q1->data.day > c->data.day)
//						{
//							c = q1;
//							std::cout << "3" << c->data.idow->data.surname << std::endl;
//							fl = 1;
//						}
//					}
//				}
//			}
//			q1 = q1->next;
//		}
//		k->data.id_current_owner = c->data.idow;
//		std::cout << "¬ладелец" << c->data.idow->data.surname << std::endl;
//		k = k->next;
//		ch = ch->changeowr(filename, o, sp);
//	}
//}

#endif // !TABLECLASS_H