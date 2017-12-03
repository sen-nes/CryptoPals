#include "CryptoPals.h"

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::exception;
using std::runtime_error;
using std::ifstream;
using std::ios;
using std::istreambuf_iterator;

const string CryptoPals::HEX =    "0123456789abcdef";
const string CryptoPals::BASE64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                  "abcdefghijklmnopqrstuvwxyz"
                                  "0123456789+/";


string
CryptoPals::ToUpper(const string& str)
{
   string out;
   out.reserve(str.size());
   for (int i = 0; i < str.size(); i++)
   {
      unsigned char c = str[i];
      if (c >= 97 && c <= 122) {
         c -= 32;
      }

      out.push_back(c);
   }

   return out;
}


string
CryptoPals::ToLower(const string& str)
{
   string out;
   out.reserve(str.size());
   for (int i = 0; i < str.size(); i++)
   {
      unsigned char c = str[i];
      if (c >= 65 && c <= 90) {
         c += 32;
      }

      out.push_back(c);
   }

   return out;
}


string
CryptoPals::HexEncode(const string& str)
{
   string out;
   out.reserve(str.size() * 2); // + 1
   for (int i = 0; i < str.size(); ++i)
   {
      const unsigned char c = str[i];
      out.push_back(HEX[c >> 4]);
      out.push_back(HEX[c & 15]);
   }

   return out;
}


string
CryptoPals::HexDecode(const string& str)
{
   if (str.size() % 2 != 0)
   {
      throw runtime_error("Invalid hex string length.");
   }

   string hex;
   hex.reserve(str.size()); // / 2);
   string lower = ToLower(str);
   for (int i = 0; i < lower.size(); ++i)
   {
      unsigned char c = lower[i];
      c -= 48;
      if (c > 9) {
         c -= 39;
      }

      if (c > 15 || c < 0) {
         throw runtime_error("Hex string contains invalid characters.");
      }

      hex.push_back(c);
   }

   string out;
   for (int i = 1; i < hex.size(); i += 2)
   {
      out.push_back(((hex[i - 1] << 4) | (hex[i])));
   }

   return out;
}


// TODO: Refactor.
string
CryptoPals::Base64Encode(const string& str)
{
   // TODO:: Research impact of accessing size().
   size_t len = str.size();
   // TODO: Reserve space for out.
   string out;

   // TODO: Is it required for str to be hex encoded?
   for (int i = 2; i < len; i += 3)
   {
      const unsigned char a = str[i - 2];
      const unsigned char b = str[i - 1];
      const unsigned char c = str[i];

      out.push_back(BASE64[a >> 2]);
      out.push_back(BASE64[((a & 3) << 4) | (b >> 4)]);
      out.push_back(BASE64[((b & 15) << 2) | (c >> 6)]);
      out.push_back(BASE64[c & 63]);
   }

   if (len % 3 != 0) {
      unsigned char a = 0;
      unsigned char b = 0;
      if (str.size() % 3 == 1) {
         a = str[len - 2];
         b = str[len - 1];
      } else {
         a = str[len - 1];
         b = 0;
      }
      const unsigned char c = 0;

      out.push_back(BASE64[a >> 2]);
      out.push_back(BASE64[((a & 3) << 4) | (b >> 4)]);

      unsigned char tmp = (((b & 15) << 2) | (c >> 6));
      if (tmp != 0)
      {
         out.push_back(BASE64[tmp]);
      } else {
         out.push_back('=');
      }
      out.push_back('=');
   }

   return out;
}


string
CryptoPals::Base64Decode(const string& str)
{
   if (str.size() % 4 != 0) {
      throw runtime_error("Invalid input string size.");
   }

   string out;
   out.reserve(str.size() * 0.75f);
   for (int i = 3; i < str.size(); i += 4)
   {
      // TODO: Handle '=' correctly
      unsigned char a = BASE64.find(str[i - 3]);
      unsigned char b = BASE64.find(str[i - 2]);
      unsigned char c = BASE64.find(str[i - 1]);
      unsigned char d = BASE64.find(str[i]);

      out.push_back(a << 2 | b >> 4);
      out.push_back((b & 15) << 4 | c >> 2);
      out.push_back((c & 3) << 6 | d);
   }

   return out;
}


unsigned char
CryptoPals::FixedXOR(const unsigned char& first,
                     const unsigned char& second)
{
   unsigned char mask = 1;
   unsigned char result = 0;

   for (int bit = 0; bit < 8; ++bit)
   {
      if ((first & mask) != (second & mask)) {
         result = result | mask;
      }
      mask = mask << 1;
   }

   return result;
}


string
CryptoPals::FixedXOR(const string& first,
                     const string& second)
{
   string out;
   if (first.size() != second.size()) {
      throw runtime_error("Incompatible string sizes.");
   }

   for (int i = 0; i < first.size(); ++i)
   {
      unsigned char c = FixedXOR(first[i], second[i]);
      out.push_back(c);
   }

   return out;
}


// TODO: No point in passing key as a reference.
string
CryptoPals::SingleByteXOR(const string& str,
                          const unsigned char& key)
{
   string out;
   for (int i = 0; i < str.size(); ++i)
   {
      unsigned char c = FixedXOR(str[i], key);
      out.push_back(c);
   }

   return out;
}


string
CryptoPals::RepeatingKeyXOR(const string& str,
                            const string& key)
{
   string out;
   out.reserve(str.size());

   size_t keySize = key.size();
   size_t ik = 0;
   for (int is = 0; is < str.size(); ++is)
   {
      unsigned char r = FixedXOR(str[is], key[ik]);
      out.push_back(r);

      ik = (ik + 1) % keySize;
   }

   return out;
}


double
CryptoPals::GetCharFrequency(const string& str)
{
   double letters = 0.0f;
   for (int i = 0; i < str.size(); ++i)
   {
      unsigned char c = str[i];
      if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90)) {
         letters++;
      }
   }

   return letters / str.size();
}


string
CryptoPals::ReadFile(const string& name,
                     string& out)
{
   string path = "./tmp/" + name;
   ifstream file;
   file.open(path.data(), ios::in);
   if (file.is_open())
   {
      out.clear();
      out = string((istreambuf_iterator<char>(file)),
                   istreambuf_iterator<char>());
   }
   return out;
}


unsigned char
CryptoPals::ScoreText(const string& str)
{
   double bestCoverage = 0.0f;
   unsigned char best;
   for (unsigned char c = 0; c < 255; ++c)
   {
      string out = SingleByteXOR(str, c);
      double coverage = GetCharFrequency(out);
      if (coverage > bestCoverage) {
         bestCoverage = coverage;
         best = c;
      }
   }

   return best;
}
