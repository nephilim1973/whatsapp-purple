
#ifndef __WACOMMON__H__
#define __WACOMMON__H__

#include <string>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <locale>

static unsigned long long str2lng(std::string s)
{
	unsigned long long r;
	#ifdef _WIN32
	sscanf(s.c_str(), "%I64u", &r);
	#else
	sscanf(s.c_str(), "%llu", &r);
	#endif
	return r;
}

static std::string i2s(unsigned int num)
{
	char temp[512];
	sprintf(temp, "%d", num);
	return std::string(temp);
}

static int a2i(const std::string & s)
{
	int d;
	sscanf(s.c_str(), "%d", &d);
	return d;
}

static double str2dbl(std::string s)
{
	float longitude = 0.0f;
	std::istringstream istr(s);
	istr.imbue(std::locale("C"));
	istr >> longitude;
	return longitude;
}

static std::string getusername(std::string user)
{
	size_t pos = user.find('@');
	if (pos != std::string::npos)
		return user.substr(0, pos);
	else
		return user;
}

#define makeAttr1(k1,v1) std::map<std::string, std::string> ({ {k1,v1} })
#define makeAttr2(k1,v1,k2,v2) std::map<std::string, std::string> ({ {k1,v1},{k2,v2} })
#define makeAttr3(k1,v1,k2,v2,k3,v3) std::map<std::string, std::string> ({ {k1,v1},{k2,v2},{k3,v3} })
#define makeAttr4(k1,v1,k2,v2,k3,v3,k4,v4) std::map<std::string, std::string> ({ {k1,v1},{k2,v2},{k3,v3},{k4,v4} })
#define makeAttr5(k1,v1,k2,v2,k3,v3,k4,v4,k5,v5) std::map<std::string, std::string> ({ {k1,v1},{k2,v2},{k3,v3},{k4,v4},{k5,v5} })


#endif

