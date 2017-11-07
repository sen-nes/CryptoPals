#pragma once

#include <string>
#include <vector>


class CryptoPals {
public:
   CryptoPals() {}

   std::string ToUpper(const std::string&);
   std::string ToLower(const std::string&);
   std::string HexEncode(const std::string&);
   std::string HexDecode(const std::string&);
   std::string HexToBase64(const std::string&);
   // TODO: Handle '=' correctly and research efficiency
   std::string Base64Decode(const std::string&);
   std::string FixedXOR(const std::string&, const std::string&);
   // TODO: Test 
   unsigned char FixedXOR(const unsigned char&, const unsigned char&);
   double GetCharFrequency(const std::string&);
   unsigned char ScoreText(const std::string&);
   std::string SingleByteXOR(const std::string&, const unsigned char&);
   std::string RepeatingKeyXOR(const std::string&, const std::string&);
};