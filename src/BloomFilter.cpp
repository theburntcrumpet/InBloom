#include <stdio.h>
#include "BloomFilter.h"


BloomFilter::BloomFilter(unsigned int nBloomSize)
{
	m_nBloomSize = nBloomSize;
	m_bloomData = new bool[m_nBloomSize];
	for (int i = 0; i < m_nBloomSize; i++) {
		m_bloomData[i] = false;
	}
}

BloomFilter::~BloomFilter()
{
	delete[] m_bloomData;
}

void BloomFilter::GetHashIndexes(std::string hashString, int nIndexSize,int * indexes) {
	size_t nHash = strHash(hashString);
	size_t maskBits = 1 << (sizeof(nHash)*8-1);
	int nCurrent=0;
	for (int i = 0; i < sizeof(nHash) * 8 || i < nIndexSize; i++) {
		if ((nHash >> i) & 1) {
			indexes[nCurrent] = i;
			nCurrent++;
		}
		maskBits >>= 1;
	}
}

bool BloomFilter::Query(std::string strQuery) {
	int * pIndexes = new int[m_nBloomSize];
	for (int n = 0; n < m_nBloomSize; n++) {
		pIndexes[n] = 0;
	}
	GetHashIndexes(strQuery,m_nBloomSize,pIndexes);
	for (int i = 0; i < m_nBloomSize; i++) {
		if (m_bloomData[pIndexes[i]] == false) {
			delete[] pIndexes;
			return false;
		}
	}
	delete[] pIndexes;
	return true;
}

void BloomFilter::Insert(std::string strQuery) {
	int * pIndexes = new int[m_nBloomSize];
	for (int n = 0; n < m_nBloomSize; n++) {
		pIndexes[n] = 0;
	}
	GetHashIndexes(strQuery, m_nBloomSize, pIndexes);
	for (int i = 0;i < m_nBloomSize;i++) {
		int nIndex = pIndexes[i];
		m_bloomData[nIndex] = true;
	}
	delete[] pIndexes;
}
