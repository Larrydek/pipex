#include <stdio.h>
#include <unistd.h>

int main(){
	char c = 32;

	c = c + 1;

	write(1, &c, 1);
	return (0);
}
