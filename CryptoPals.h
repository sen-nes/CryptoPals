#pragma once

#include <string>
#include <vector>


class CryptoPals {
public:
   static const std::string BASE64;
   static const std::string HEX;
   CryptoPals() {}

   // TODO: Change to out-parameters.

   std::string ToUpper(const std::string& str);
   std::string ToLower(const std::string& str);
   std::string HexEncode(const std::string& str);
   std::string HexDecode(const std::string& str);
   std::string Base64Encode(const std::string& str);
   // TODO: Handle '=' correctly and research efficiency
   std::string Base64Decode(const std::string& str);
   unsigned char FixedXOR(const unsigned char& first,
                          const unsigned char& second);
   std::string FixedXOR(const std::string& first,
                        const std::string& second);
   std::string SingleByteXOR(const std::string& str,
                             const unsigned char& byte);
   std::string RepeatingKeyXOR(const std::string& str,
                               const std::string& key);
   double GetCharFrequency(const std::string& str);
   unsigned char ScoreText(const std::string& str);
   std::string ReadFile(const std::string& name,
                        std::string& out);
};