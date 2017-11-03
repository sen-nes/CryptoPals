#include <string>

class CryptoPals {
public:
   CryptoPals() {}
   
   std::string StringToHex(const std::string&);
   std::string Base64Encode(const std::string&);
   std::string Base64Decode(const std::string&);
};