all: run

CryptoPals:
	g++ main.cpp CryptoPals.cpp -o CryptoPals

clean:
	rm -f CryptoPals

run: CryptoPals
	./CryptoPals
