void throwInvalid();
void throwDenormalized();
void readExceptions();

int main()
{
	throwInvalid();
	readExceptions();


	throwDenormalized();
	readExceptions();
}
