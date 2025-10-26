#include "leftBehindHandler.hpp"

leftBehindHandler::leftBehindHandler()
{

}

leftBehindHandler::leftBehindHandler(const leftBehindHandler &src)
{
	*this = src;
}

leftBehindHandler::~leftBehindHandler()
{

}


leftBehindHandler &leftBehindHandler::operator=(const leftBehindHandler &src)
{
	pairsLi.clear();
	leftoverPairsLi.clear();
	pairsVec.clear();
	leftoverPairsVec.clear();

	pairsLi = src.getPairsLi();
	leftoverPairsLi = src.getLeftOversLi();
	pairsVec = src.getPairsVec();
	leftoverPairsVec = src.getLeftOversVec();

	return (*this);
}


intPairsList	leftBehindHandler::getPairsLi() const
{
	return (pairsLi);
}

intPairsList	leftBehindHandler::getLeftOversLi() const
{
	return (leftoverPairsLi);
}

intPairsVector	leftBehindHandler::getPairsVec() const
{
	return (pairsVec);
}

intPairsVector	leftBehindHandler::getLeftOversVec() const
{
	return (leftoverPairsVec);
}


void	leftBehindHandler::setPairsLi(const intPairsList &src)
{
	pairsLi.clear();
	pairsLi = src;
}

void	leftBehindHandler::setLeftOversLi(const intPairsList &src)
{
	leftoverPairsLi.clear();
	leftoverPairsLi = src;
}

void	leftBehindHandler::setPairsVec(const intPairsVector &src)
{
	pairsVec.clear();
	pairsVec = src;
}

void	leftBehindHandler::setLeftOversVec(const intPairsVector &src)
{
	leftoverPairsVec.clear();
	leftoverPairsVec = src;
}

