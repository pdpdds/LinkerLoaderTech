int dummy_extvalue = 4;
int dummy_extbssvalue;
int extvalue = 2; /* .data ��������� */
int extbssvalue;  /* .bss ��������� */

void dummy_extfunc() {}

int extfunc()
{
  return (0);
}
