template < class container >
PmergeMe<container>::PmergeMe() : _cont(0)
{

}

template <class container >
PmergeMe<container>::PmergeMe(const std::vector<unsigned int> &src)
{
	for (std::vector<unsigned int>::const_iterator it = src.begin(); it != src.end(); it++)
	{
		_cont.push_back(*it);
	}
	
}

template <class container >
PmergeMe<container>::PmergeMe(const PmergeMe &src):
	_cont(src.getCont())
{

}

template <class container >
PmergeMe<container>::~PmergeMe()
{

}


template <class container >
container PmergeMe<container>::getCont() const
{
	return (_cont);
}

template <class container >
PmergeMe<container> &PmergeMe<container>::operator=(
	const PmergeMe<container> &src)
{
	_cont = src.getCont();

	return (*this);
}
