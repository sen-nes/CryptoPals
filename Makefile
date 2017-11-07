#g++ main.cpp CryptoPals.cpp -o CryptoPals
#./CryptoPals
all: run

CryptoPals:
	/build/toolchain/lin32/gcc-4.8.0/bin/x86_64-linux5.0-g++ -std=c++11 main.cpp CryptoPals.cpp -o CryptoPals

clean:
	rm -f CryptoPals

run: CryptoPals
	LD_LIBRARY_PATH=/build/toolchain/lin32/gcc-4.8.0/x86_64-linux5.0/lib64/ ./CryptoPals