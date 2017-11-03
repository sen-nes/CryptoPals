all: run

#TpmStore.cpp
CryptoPals:
	/build/toolchain/lin32/gcc-4.8.0/bin/x86_64-linux5.0-g++ -ggdb -std=c++11 -I/build/toolchain/lin64/openssl-1.0.2l/include/ -L/build/toolchain/lin64/openssl-1.0.2l/lib64/ -Wl,-rpath,/build/toolchain/lin64/openssl-1.0.2l/lib64/ -lcrypto main.cpp CryptoPals.cpp -o CryptoPals

clean:
	rm -f CryptoPals

run: CryptoPals
	LD_LIBRARY_PATH=/build/toolchain/lin32/gcc-4.8.0/x86_64-linux5.0/lib64/ ./CryptoPals
