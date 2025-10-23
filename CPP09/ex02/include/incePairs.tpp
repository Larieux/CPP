template < class container >
incePairs< container >::incePairs() : _abomination(0)
{

}

template < class container >
incePairs< container >::incePairs(const container &srcFirst, const container &srcSecond)
{
	_abomination = std::make_pair(srcFirst, srcSecond);
}

template < class container >
incePairs< container >::incePairs(const incePairs< container > &src)
{
	*this = src;
}

template < class container >
incePairs< container >::~incePairs()
{

}


template < class container >
incePairs< container > &incePairs< container >::operator=(const incePairs< container > &src)
{
	for (typename container::const_iterator it = src.begin(); it != src.end(); it++)
		_abomination.push_back(*it);

	return (*this);
}


template < class container >
void		incePairs< container >::setAbomination(const container &src)
{
	_abomination = src;
}

template < class container >
void		incePairs< container >::setAbomination(const unsigned int &srcFirst, const unsigned int &srcSecond)
{
	_abomination = std::make_pair(srcFirst, srcSecond);
}


template < class container >
container	incePairs< container >::getAbomination() const
{
	return (_abomination);
}


template < class container >
container	incePairs< container >::sortPairs()
{
	incePairs< std::pair<container, container> >	containerIncePair;
	containerIncePair.setAbomination(makePairs(_abomination)).;
	container	sortedPairs;

	if (pairs.size() > 1)
		sortedPairs = sortPairs();
	else
		sortedPairs = _abomination;

	return (sortedPairs);
}

template < class container >
unsigned int	incePairs< container >::findSecond(container abomi)
{
	if (dynamic_cast< container *>(&(abomi.second)) != NULL)
		return (findSecond(abomi.second));
	else
		return (abomi.second);
}

template < class container >
container	incePairs< container >::makePairs(container &src)
{
	std::pair<container, container>	pair;

	if (findSecond(src.first) < findSecond(src.second))
		pair = std::make_pair(src.first, src.second);
	else
		pair = std::make_pair(src.second, src.first);

	return (pair);
}
