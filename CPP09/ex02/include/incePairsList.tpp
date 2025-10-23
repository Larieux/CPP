template < class container >
incePairsList<container>::incePairsList() : _abomination(0)
{

}

template < class container >
incePairsList<container>::incePairsList(const container &src)
{
	_abomination = src;
}

template < class container >
incePairsList<container>::incePairsList(const incePairsList<container> &src)
{
	*this = src;
}

template < class container >
incePairsList<container>::~incePairsList()
{

}


template < class container >
incePairsList<container> &incePairsList<container>::operator=(const incePairsList<container> &src)
{
	_abomination = src.getAbomination();

	return (*this);
}


template < class container >
container	incePairsList<container>::getAbomination() const
{
	return (_abomination);
}


template < class container >
container	incePairsList<container>::sortPairs()
{
	container	sortedPairs = makePairs();

	return (_abomination);
}

template < class container >
unsigned int	incePairsList<container>::findSecond(typename container::const_iterator it)
{
	if (dynamic_cast<unsigned int *>(&((*it).second)) != NULL)
		return ((*it).second);
	else
		return (findSecond((*it).second));
}

template < class container >
container	incePairsList<container>::makePairs()
{
	container	pairs;

	typename container::const_iterator it = _abomination.begin();
	it++;
	for (typename container::const_iterator ite = _abomination.begin(); it != _abomination.end();)
	{
		if (findSecond(it) < findSecond(ite))
			pairs.push_back(std::make_pair(*it, *ite));
		else
			pairs.push_back(std::make_pair(*ite, *it));

		it++;
		ite++;
		if (it == _abomination.end())
			return (pairs);
		it++;
		ite++;
	}

	return (pairs);
}
