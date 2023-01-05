extern int num;
void printnum();
void func1();
void func2();

int main()
{
  printnum();
  num++;   printnum();
  func1(); printnum();
  func2(); printnum();
  exit (0);
}
