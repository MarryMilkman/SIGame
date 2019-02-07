#ifndef MEMLIST_HPP
# define MEMLIST_HPP

# include <iostream>

template <typename U>
struct				s_list
{
	U				value;
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
	~memlist() {
		struct s_list<T>	*dList;

		while (this->list) {
			dList = this->list;
			this->list = this->list->next;
			delete dList;
		}
	}

	class memlistException : public std::exception
	{
	public:
		virtual const char	*what() const throw() {
			return ("Out of range");
		}
	};

	memlist				& operator=(memlist const & ref) {
		// struct s_list<T>	*s_list = this->list;
		// struct s_list<T>	*r_list = ref.list;
		// struct s_list<T>	*d_list;

		// if (!s_list) {
		// 	this->list = new struct s_list<T>;
		// 	this->list->next = 0;
		// }
		// s_list = this->list;
		// while(r_list) {
		// 	if (!this->list)
		// 		this->list = new struct s_list<T>;
		// 	this->list->value = r_list->value;
		// 	this->list->next = r_list->next;
		// 	this->list = list->next;
		// 	r_list = r_list->next;
		// 	std::cout << ".";
		// }
		// if (this->list)
		// 	while (this->list) {
		// 		d_list = this->list;
		// 		this->list = this->list->next;
		// 		delete d_list;
		// 		std::cout << "u";
		// 	}
		// this->list = s_list;
		this->list = ref.list;
		return *this;
	}

// MARK: -

	struct s_list<T>	*list;

	T					pop(int index) {
		struct s_list<T>	*dList = 0;
		struct s_list<T>	*pList = 0;
		struct s_list<T>	*sList = this->list;
		T					rValue;

		while ((dList = sList) && index--) {
			pList = sList;
			sList = sList->next;
		}
		if (!dList)
			return 0;
		if (!pList)
			this->list = this->list->next;
		else
			pList->next = dList->next;
		rValue = dList->value;
		delete dList;
		return rValue;
	}

	void				push_front(T value) {
		struct s_list<T>	*nList = new struct s_list<T>;

		nList->value = value;
		nList->next = this->list;
		this->list = nList;
	}

	void				push_back(T value) {
		struct s_list<T>	*nList = new struct s_list<T>;
		struct s_list<T>	*bList = this->list;

		nList->value = value;
		nList->next = 0;
		if (!bList) {
			this->list = nList;
			return ;
		}
		while (bList->next)
			bList = bList->next;
		bList->next = nList;
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

	bool				checkExistence(T value) {
		struct s_list<T>	*sList;

		sList = this->list;
		while (sList) {
			if (sList->value == value)
				return true;
			sList = sList->next;
		}
		return false;
	}

	T					operator[](int i) {
		struct s_list<T>	*sList;

		sList = this->list;
		while (sList && i--)
			sList = sList->next;
		if (!sList) {
			throw memlist::memlistException();
		}
		return sList->value;
	}

};

#endif