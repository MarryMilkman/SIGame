#ifndef MEMLIST_HPP
# define MEMLIST_HPP

# include <iostream>

template <typename U>
struct				s_list
{
	U				*value;
	struct s_list	*next;
};


template <typename T>
class memlist
{
public:
	memlist() {
		this->list = 0;
	}
	memlist(memlist const & ref) {
		*this = ref;
	}
	~memlist() {}

	struct s_list<T>	*list;

	void				delite(int index) {
		struct s_list<T>	*dList = 0;
		struct s_list<T>	*pList = 0;
		struct s_list<T>	*sList = this->list;

		while ((dList = sList) && index--) {
			pList = sList;
			sList = sList->next;
		}
		if (!dList)
			return ;
		if (!pList)
			this->list = this->list->next;
		else
			pList->next = dList->next;
		delete dList->value;
		delete dList;
	}
	void				push_front(T *value) {
		struct s_list<T>	*nList = new struct s_list<T>;

		nList->value = value;
		nList->next = this->list;
		this->list = nList;
	}

	int					size() {
		int					size;
		struct s_list<T>	*sList = this->list;

		size = 0;
		while (sList) {
			size++;
			sList = sList->next;
		}
		return size;
	}

	bool				checkExistence(T *value) {
		struct s_list<T>	*sList;

		sList = this->list;
		while (sList) {
			if (sList->value == value)
				return true;
			sList = sList->next;
		}
		return false;
	}

	T					*operator[](int i) {
		struct s_list<T>	*sList;

		sList = this->list;
		while (sList && i--)
			sList = sList->next;
		if (!sList)
			return 0;
		return sList->value;
	}

	memlist				& operator=(memlist const & ref) {
		this->list = ref.list;
		return *this;
	}
};

#endif