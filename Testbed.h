#pragma once

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


bool
TestToUpper()
{
   string test = "TestToUpper";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "A1B2C3D4";
   string in = "a1b2c3d4";
   cout << "IN       " << in << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   string out = cp->ToUpper(in);
   cout << "OUT      " << out << endl;
   cout << "EXPECTED " << expected << endl;

   pass = expected.compare(out) == 0;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool
TestHexEncoding()
{
   string test = "TestHexEncoding";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "4A75727261736963205061726B";
   string in = "Jurrasic Park";
   cout << "IN       " << in << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   string out = cp->ToUpper(cp->HexEncode(in));
   cout << "OUT      " << out << endl;
   cout << "EXPECTED " << expected << endl;

   pass = expected.compare(out) == 0;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool
TestHexDecoding()
{
   string test = "TestHexDecoding";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "Jurrasic Park";
   string in = "4A75727261736963205061726B";
   cout << "IN       " << in << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   string out = cp->HexDecode(in);
   cout << "OUT      " << out << endl;
   cout << "EXPECTED " << expected << endl;

   pass = expected.compare(out) == 0;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool
TestHexToBase64()
{
   string test = "TestHexToBase64";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
   string in = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";

   cout << "IN       " << in << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   string out = cp->HexToBase64(in);
   cout << "OUT      " << out << endl;
   cout << "EXPECTED " << expected << endl;

   pass = expected.compare(out) == 0;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool
TestFixedXORA()
{
   string test = "TestFixedXORA";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "746865206b696420646f6e277420706c6179";
   string one = "1c0111001f010100061a024b53535009181c";
   string other = "686974207468652062756c6c277320657965";
   cout << "ONE      " << one << endl;
   cout << "OTHER    " << other << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   string outRaw = cp->FixedXOR(one, other);
   string out = cp->HexEncode(outRaw);

   cout << "OUT      " << out << endl;
   cout << "EXPECTED " << expected << endl;

   pass = expected.compare(out) == 0;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool
TestFixedXORB()
{
   string test = "TestFixedXORB";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "1c0111001f010100061a024b53535009181c";
   string one = "746865206b696420646f6e277420706c6179";
   string other = "686974207468652062756c6c277320657965";
   cout << "ONE      " << one << endl;
   cout << "OTHER    " << other << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   string outRaw = cp->FixedXOR(one, other);
   string out = cp->HexEncode(outRaw);

   cout << "OUT      " << out << endl;
   cout << "EXPECTED " << expected << endl;

   pass = expected.compare(out) == 0;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool
TestFixedXORC()
{
   string test = "TestFixedXORC";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "686974207468652062756c6c277320657965";
   string one = "746865206b696420646f6e277420706c6179";
   string other = "1c0111001f010100061a024b53535009181c";
   cout << "ONE      " << one << endl;
   cout << "OTHER    " << other << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   string outRaw = cp->FixedXOR(one, other);
   string out = cp->HexEncode(outRaw);

   cout << "OUT      " << out << endl;
   cout << "EXPECTED " << expected << endl;

   pass = expected.compare(out) == 0;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


bool
TestSingleByteXOR()
{
   string test = "TestSingleByteXOR";
   bool pass = false;

   cout << "*** Preparing for test " << test << "... ***" << endl;

   CryptoPals *cp = new CryptoPals();
   string expected = "Cooking MC's like a pound of bacon";
   string in = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
   cout << "IN       " << in << endl;

   cout << "*** Done preparing for test " << test << " ***" << endl;

   cout << "*** Running test " << test << "... ***" << endl;

   unsigned char cipher = cp->ScoreText(in);
   string out = cp->SingleByteXOR(in, cipher);

   cout << "CIPHER   " << cipher << endl;
   cout << "OUT      " << out << endl;
   cout << "EXPECTED " << expected << endl;

   pass = expected.compare(out) == 0;

   cout << "*** Completed test " << test << " ***" << endl;

   cout << "*** Cleaning up for test " << test << "... ***" << endl;

   delete cp;

   cout << "# " << test << "............... " << (pass ? "PASS" : "FAIL") << endl;
   cout << "*** Done cleaning up for test " << test << " ***" << endl << endl;

   return pass;
}


void
RunTests()
{
   vector<bool> tests;
   int success = 0;

   tests.push_back(TestToUpper());
   tests.push_back(TestHexEncoding());
   tests.push_back(TestHexDecoding());
   tests.push_back(TestHexToBase64());
   tests.push_back(TestFixedXORA());
   tests.push_back(TestFixedXORB());
   tests.push_back(TestFixedXORC());
   tests.push_back(TestSingleByteXOR());

   for (bool test : tests)
   {
      success += test;
   }

   cout << "Success: " << success << " / " << tests.size() << endl;
}
