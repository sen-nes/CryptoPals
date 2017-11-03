#pragma once

#include <string>
#include <vector>


struct Res {
   std::string hexString;
   std::vector<unsigned char> hex;
};


class CryptoPals {
public:
   CryptoPals() {}

   Res StringToHex(const std::string&);
   std::string HexBase64Encode(const std::string&);
   std::string HexBase64Decode(const std::string&);
   std::vector<unsigned char> HexStringToVector(const std::string&);
};