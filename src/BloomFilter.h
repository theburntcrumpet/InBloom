#include <string>
class BloomFilter
{
private:
	int m_nBloomSize;
	bool * m_bloomData;
	std::hash<std::string> strHash;
private:
	void GetHashIndexes(std::string strHashString,int nIndexSize,int * indexes);
public:
	bool Query(std::string strQuery);
	void Insert(std::string strQuery);
	BloomFilter(unsigned int nBloomSize);
	~BloomFilter();
};
