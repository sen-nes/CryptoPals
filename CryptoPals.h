#pragma once

#include <string>
#include <vector>


class CryptoPals {
public:
   CryptoPals() {}

   std::string ToUpper(const std::string&);
   std::string HexEncode(const std::string&);
   std::string HexDecode(const std::string&);
   std::string HexToBase64(const std::string&);
   std::string Base64ToHex(const std::string&);
   std::string FixedXOR(const std::string&, const std::string&);
   double GetCharFrequency(const std::string&);
   unsigned char ScoreText(const std::string&);
   std::string SingleByteXOR(const std::string&, const unsigned char&);
};