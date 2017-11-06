#include "CryptoPals.h"

#include <iostream>
#include <string>
#include <vector>
#include <exception>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::runtime_error;


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
CryptoPals::HexEncode(const string& in)
{
   const char *hexChars = "0123456789abcdef";

   string out;
   out.reserve(in.size() * 2); // + 1
   for (int i = 0; i < in.size(); ++i)
   {
      const unsigned char c = in[i];
      out.push_back(hexChars[c >> 4]);
      out.push_back(hexChars[c & 15]);
   }

   return out;
}


string
CryptoPals::HexDecode(const string& in)
{
   if (in.size() % 2 != 0)
   {
      throw new runtime_error("Invalid hex string length.");
   }

   string hex;
   hex.reserve(in.size());
   for (int i = 0; i < in.size(); ++i)
   {
      unsigned char c = in[i];
      c -= 48;
      if (c > 9) {
         c -= 7;
         if (c > 15) {
            c -= 32;
         }
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


string
CryptoPals::HexToBase64(const string& in)
{
   const char *base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                             "abcdefghijklmnopqrstuvwxyz"
                             "0123456789+/";
   string out;
   try {
      string hexDecode = HexDecode(in);
      out.reserve(hexDecode.size() * 1.25f);
      for (int i = 2; i < hexDecode.size(); i += 3)
      {
         const unsigned char a = hexDecode[i - 2];
         const unsigned char b = hexDecode[i - 1];
         const unsigned char c = hexDecode[i];

         out.push_back(base64Chars[a >> 2]);
         out.push_back(base64Chars[((a & 3) << 4) | (b >> 4)]);
         out.push_back(base64Chars[((b & 15) << 2) | (c >> 6)]);
         out.push_back(base64Chars[c & 63]);
      }

      if (hexDecode.size() % 3 != 0) {
         unsigned char a = 0;
         unsigned char b = 0;
         if (hexDecode.size() % 3 == 1) {
            a = hexDecode[hexDecode.size() - 2];
            b = hexDecode[hexDecode.size() - 1];
         } else {
            a = hexDecode[hexDecode.size() - 1];
            b = 0;
         }
         const unsigned char c = 0;

         out.push_back(base64Chars[a >> 2]);
         out.push_back(base64Chars[((a & 3) << 4) | (b >> 4)]);

         unsigned char tmp = (((b & 15) << 2) | (c >> 6));
         if (tmp != 0)
         {
            out.push_back(base64Chars[tmp]);
         } else {
            out.push_back('=');
         }
         out.push_back('=');
      }
   } catch (runtime_error& e) {
      throw e;
   }

   return out;
}

string
CryptoPals::FixedXOR(const string& aHex, const string& bHex)
{
   string out;
   if (aHex.size() != bHex.size()) {
      throw new runtime_error("Incompatible string sizes.");
   }

   try {
      string a = HexDecode(aHex);
      string b = HexDecode(bHex);
      for (int i = 0; i < a.size(); ++i)
      {
         unsigned char mask = 1;
         unsigned char tmp = 0;
         for (int bit = 0; bit < 8; ++bit)
         {
            if ((a[i] & mask) != (b[i] & mask)) {
               tmp = tmp | mask;
            }
            mask = mask << 1;
         }
         out.push_back(tmp);
      }
   } catch (runtime_error& e) {
      throw e;
   }

   return out;
}


string
CryptoPals::SingleByteXOR(const string& str, const unsigned char& key)
{
   string out;
   try {
      string a = HexDecode(str);
      for (int i = 0; i < a.size(); ++i)
      {
         unsigned char mask = 1;
         unsigned char tmp = 0;
         for (int bit = 0; bit < 8; ++bit)
         {
            if ((a[i] & mask) != (key & mask)) {
               tmp = tmp | mask;
            }
            mask = mask << 1;
         }
         out.push_back(tmp);
      }
   } catch (runtime_error& e) {
      throw e;
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


unsigned char
CryptoPals::ScoreText(const string& str)
{
   const string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                          "abcdefghijklmnopqrstuvwxyz";

   double maxCoverage = 0.0f;
   int index;
   for (int i = 0; i < letters.size(); ++i)
   {
      string out = SingleByteXOR(str, letters[i]);
      double coverage = GetCharFrequency(out);
      if (coverage > maxCoverage) {
         maxCoverage = coverage;
         index = i;
      }
   }

   return letters[index];
}
