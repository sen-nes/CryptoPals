#pragma once

#include <string>
#include <vector>


class CryptoPals {
public:
   CryptoPals() {}

   std::string HexEncode(const std::string&);
   std::string HexDecode(const std::string&);
   std::string HexToBase64(const std::string&);
   std::string Base64ToHex(const std::string&);
   std::string FixedXOR(const std::string&, const std::string&);
};