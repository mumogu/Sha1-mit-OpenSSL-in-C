#include <stdio.h>
#include <stdlib.h>
#include <openssl/sha.h>

// Apple has deprecated the OpenSSL routines because they want you to use their "Common Data Security
// Architecture" but since OpenSSL isn't going to go away anytime soon, this disables the deprecated-warnings.
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void print_hex(unsigned char *data, int length) {
	for(int i=0; i<length; i++) {
		printf("%02x", (unsigned char)data[i]);
	}
	printf("\n");
}

int main(int argc, char * const argv[]) {		
	// Let's try sone hashing. 
	unsigned char input[] = {'H', 'a', 'l', 'l', 'o', ' ', 'W', 'e', 'l', 't'}; 

	unsigned char hash[20]; // sha1 hash is always 20 bytes long
	SHA1(input, 10, hash); // (input, input-length, output)
	printf("SHA1 Hash of \"Hallo Welt\": ");
	print_hex(hash, 20);

	return 0;
}
