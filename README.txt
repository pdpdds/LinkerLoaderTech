2010.08.30 ��湰μ

�ܥե�����Ͻ���
�֥�󥫡�����������ȯ�ƥ��˥å���(��湰μ��2010/08��CQ���Ǽ�)
����Ͽ�Ǥ���

�� column

�ɲå����Ǥ�������Ū������ǡ���ʸ�ˤϷǺܤ���ʤ��ä���ΤǤ���
�������ơ�����Υڡ����ˤϤ���Ǥ����Ȥ������⤷��ޤ���

�Ȥ��˰ʲ���ʸ�Ϥϡ��ʤ��ʤ���������Ƥ��������̵��������ɤ��Ƥ����Ȥ�������
����ޤ���

column-sec6-p152.txt
��MEMORY���ޥ�ɤˤ�륢�ɥ쥹������Ƥ������

column-sec10-p249.txt
�֥����Х롦�ݥ��󥿤����ѡ�

�� src

��ʸ��ǾҲ𤵤�Ƥ���ƥ�����(��˥ץ����Υ����������ɤ���Ϸ�̤ʤ�)��
����¾�����Ǥ���

�ܥե������̵�ݾڤǤ����Ŀͤ���Ǥ�β������Ѥ��Ƥ���������
�ե����������ԡ����ǼҤϡ��ܥ����������ɤ����Ѥ��뤳�Ȥ�ȯ�����뤤���ʤ�
��Ǥ���餤�ޤ���

�����Υ����������ɤϡ�FreeBSD/NetBSD/GNU+Linux�ʤɤ����ȴ��(ή��)�Ǥ���
�����Υ����������ɤ�����ϡ�ή�Ѹ���°���ޤ���ή�Ѹ��ˤĤ��ƤϽ��Ҥ���ʸ��
���Ȥ��Ƥ����������Ȥ���������̵����Τϡ�FreeBSD�⤷����FreeBSD��ź�դ����
���ۤ���Ƥ���GNU���ġ���Υ����������ɤ����ή�ѤǤ���

����ʳ��Υ����������ɤϽ��Ҥμ�ɮ�ԤǤ����椬����������ΤǤ���
�Ŀͤ���Ǥ�β��ǡ���ͳ�����Ѥ��ƹ����ޤ���

��������������ˤϡ�������ǾҲ𤷤Ƥ��ʤ��¸��ѤΤ�Τʤɤ�ޤޤ�Ƥ��ޤ���
��ͳ�����Ѥ��Ƥ���������

�ʲ��������������ɰ����Ǥ���
�ꥹ���ֹ�ϡ����Ҥ���ʸ��Ǥ��ֹ�Ǥ���
�ޤˤĤ��Ƥϰ����Τ߰ʲ������˷Ǻܤ��Ƥ���ޤ��������Ϸ�̤ʤɤ�¿���Τ�Τ�
src�ǥ��쥯�ȥ�ʲ��ˤ���ޤ��Τǡ�ɬ�פʤ��õ���Ƥߤ�Ȥ������⤷��ޤ���

--------------------------------------------------------------------------------
�ꥹ���ֹ�	����						������������
--------------------------------------------------------------------------------
�ꥹ��1.1	hello.c						src/hello/hello.c
�ꥹ��1.2	gcc -v �η��					src/hello/gcc-v.out
�ꥹ��1.3	size hello �η��				src/hello/size.out
�ꥹ��1.4	objdump -h hello �η��				src/hello/objdump.out
�ꥹ��1.5	/usr/src/usr.bin/size/size.c ���ȴ��		src/hello/size_aout.c
�ꥹ��1.6	struct exec �����(imgact_aout.h ���ȴ��)	src/hello/imgact_aout.h
�ꥹ��1.7	hello ����Ƭ��ʬ��16�ʥ����			src/hello/hello_dump.txt
�ꥹ��1.8	/usr/src/contrib/binutils/binutils/size.c ���ȴ��
								src/hello/size_elf.c
�ꥹ��1.9	objdump -p hello �η��				src/hello/objdump-p.out
�ꥹ��1.10	�͡����ѿ������(values_sub.c)			src/values/values_sub.c
�ꥹ��1.11	�͡����ѿ������(values.c)			src/values/values.c
�ꥹ��1.12	nm values_sub.o �η��				src/values/values_sub_nm.out
�ꥹ��1.13	nm values �η��				src/values/values_nm.out
�ꥹ��1.14	objdump -h values �η��			src/values/objdump.out
�ꥹ��1.15	values �μ¹Է��				src/values/values.out
�ꥹ��1.16	strip values �μ¹Է��				src/values/strip.out
�ꥹ��1.17	��󥫥�����ץȤο���				---
�ꥹ��1.18	����ȥ�ݥ���ȤˤĤ���(info ld ���ȴ��)	---
�ꥹ��1.19	ENTRY()�λ���(elf_i386.x ���ȴ��)		---
--------------------------------------------------------------------------------
�ꥹ��2.1	ELF�ե���������ѥ���ץ�(elfsamp.c)		src/elfsamp/elfsamp.c
�ꥹ��2.2	ELF�ե���������ѥ���ץ�(main.c)		src/elfsamp/main.c
�ꥹ��2.3	ELF32�إå�(elf32.h)				---
�ꥹ��2.4	readelf -h elfsamp.o �η��			src/elfsamp/readelf-o-h.out
�ꥹ��2.5	brandelf.c ���ȴ��				---
�ꥹ��2.6	ELF32�ѥ��������إå�(elf32.h)		---
�ꥹ��2.7	readelf -S elfsamp.o �η��			src/elfsamp/readelf-o-S.out
�ꥹ��2.8	readelf -x 8 elfsamp.o �η��			src/elfsamp/readelf-o-x.out
�ꥹ��2.9	���������̾������ɽ������(readsec.c)		src/elfsamp/readsec.c
�ꥹ��2.10	ELF32�ѥץ����إå�(elf32.h)		---
�ꥹ��2.11	readelf -l elfsamp �η��			src/elfsamp/readelf-l.out
�ꥹ��2.12	���Ȥ�ELF�إå����ɤ߹�����(elfread.c)		src/elfread/elfread.c
�ꥹ��2.13	����ܥ�ơ��֥��ѹ�¤��(ELF32)			---
�ꥹ��2.14	readelf -s elfsamp.o �η��			src/elfsamp/readelf-o-s.out
�ꥹ��2.15	�����֥���ȥ�(ELF32)				---
�ꥹ��2.16	readelf -r elfsamp.o �η��			src/elfsamp/readelf-o-r.out
�ꥹ��2.17	ELF�����Υ���ץץ�������(elfdump.c)	src/elfsamp/elfdump.c
�ꥹ��2.18	elfdump elfsamp.o �μ¹Է��			src/elfsamp/elfdump-o.exec
�ꥹ��2.19	elfdump elfsamp �μ¹Է��			src/elfsamp/elfdump.exec
--------------------------------------------------------------------------------
�ꥹ��3.1	���������֥إå������(ar.h ���ȴ��)		src/ar/ar.h
�ꥹ��3.2	4.4BSDͳ��Υ���������(bsdar.a)			src/ar/bsdar.a
�ꥹ��3.3	GNU binutils �Υ���������(gnuar.a)		src/ar/gnuar.a
�ꥹ��3.4	���������֥ե�����Υ����(readname.c)		src/ar/readname.c
�ꥹ��3.5	���������֥ե�����β���(ardump.c)		src/ar/ardump.c
�ꥹ��3.6	���֥������ȥե�����(ardump.o)�β�����		src/ar/ardump.exec
�ꥹ��3.7	�饤�֥�ꥢ��������(/usr/lib/libc.a)�β�����	src/ar/ardump.exec2
�ꥹ��3.8	main() �ؿ�(main.c)				src/link/main.c
�ꥹ��3.9	����ץ�ե����룱(samp1.c)			src/link/samp1.c
�ꥹ��3.10	����ץ�ե����룲(samp2.c)			src/link/samp2.c
�ꥹ��3.11	����ץ�ե����룳(samp3.c)			src/link/samp3.c
�ꥹ��3.12	����ץ�ե����룴(samp4.c)			src/link/samp4.c
�ꥹ��3.13	����ץ�ե����룲�ν���(samp2.c)		src/link/samp2d.c
---		checksym.c					src/checksym/checksym.c
--------------------------------------------------------------------------------
�ꥹ��4.1	����ȥݥ���(pointer.c)			src/pointer/pointer.c
��4.2		nm pointer �η��				src/pointer/pointer.nm
��4.3		objdump -h pointer �η��			src/pointer/pointer.od
�ꥹ��4.2	const ��������ѿ����ͤ���������(const.c)	src/const/const.c
�ꥹ��4.3	const ��������ѿ����ͤ���������(const_sub.c)	src/const/const_sub.c
��4.8		nm const �η��					src/const/const.nm
��4.9		objdump -h const �η��				src/const/const.od
�ꥹ��4.4	��󥫥�����ץȤν���				src/const/elf_i386.diff
��4.12		nm noconst �η��				src/const/noconst.nm
��4.13		objdump -h noconst �η��			src/const/noconst.od
�ꥹ��4.5	����ܥ륿���פˤĤ���(info nm ���ȴ��)	---
�ꥹ��4.6	�ѿ� b �λ���(const_b.c)			src/const/const_b.c
�ꥹ��4.7	�ѿ� num �λ���(layer.c)			src/layer/layer.c
�ꥹ��4.8	�ѿ� num �����(layer_sub1.c)			src/layer/layer_sub1.c
�ꥹ��4.9	�ѿ� num �λ���(layer_sub2.c)			src/layer/layer_sub2.c
��4.27		nm liblayer.a �η��				src/layer/liblayer.a.nm
��4.31		nm liblayer_local.a �η��			src/layer/liblayer_local.a.nm
��4.35		nm layer_lib.o �η��				src/layer/layer_lib.o.nm
��4.38		nm layer_lib_local.o �η��			src/layer/layer_lib_local.o.nm
�ꥹ��4.10	�ѿ� num �����ʤ�(layer2.c)			src/layer/layer2.c
��4.41		����ܥ뤬��ʣ������				src/layer/layer_lib2.o.comp
�ꥹ��4.11	NetBSD/hpcsh �ѥ�󥫥�����ץ�(ehl-elf.x ���ȴ��)
								---
�ꥹ��4.12	PROVIDE()�λ���(elf_i386.x ���ȴ��)		---
�ꥹ��4.13	����ܥ�Υ��ɥ쥹��ɽ��(edata.c)		src/edata/edata.c
��4.46		objdump -h edata �η��				src/edata/edata.od
�ꥹ��4.14	�������Ǥ�դ˹Ԥʤ�(initialize.c)		src/initialize/initialize.c
��4.47		initialize �μ¹Է��				src/initialize/initialize.comp
								src/initialize/initialize.exec
�ꥹ��4.15	do_ctors()�����(crtbegin.c���ȴ��)		---
�ꥹ��4.16	ctor_end[]�����(crtend.c ���ȴ��)		---
�ꥹ��4.17	.ctors �������������(elf_i386.x���ȴ��)	---
�ꥹ��4.18	�ؿ��μ�ư�ƤӽФ�(ctors.c)			src/ctors/ctors.c
��4.48		ctors �Υ��ɥ쥹����				src/ctors/ctors.comp
								src/ctors/ctors.nm
								src/ctors/ctors.od
�ꥹ��4.19	do_dtors()�����(crtbegin.c���ȴ��)		---
�ꥹ��4.20	atexit() �ˤ�� _fini() ����Ͽ(crt1.c:_start()���ȴ��)
								---
�ꥹ��4.21	exit()�����(exit.c���ȴ��)			---
�ꥹ��4.22	constructor, destructor °��������(constructor.c)
								src/constructor/constructor.c
--------------------------------------------------------------------------------
�ꥹ��5.1	�������ե��������(main.c)			src/linksamp/main.c
�ꥹ��5.2	�������ե��������(lib1.c)			src/linksamp/lib1.c
�ꥹ��5.3	�������ե��������(lib2.c)			src/linksamp/lib2.c
�ꥹ��5.4	objdump �ˤ�����(main.o)			src/linksamp/main.od
�ꥹ��5.5	objdump �ˤ�����(lib1.o)			src/linksamp/lib1.od
�ꥹ��5.6	objdump �ˤ�����(lib2.o)			src/linksamp/lib2.od
�ꥹ��5.7	objdump �ˤ�����(linksamp)			src/linksamp/linksamp.od
�ꥹ��5.8	��ñ�ʥ�󥫥�����ץȤ���(sample.lds)		src/linksamp/sample.lds
�ꥹ��5.9	objdump �ˤ�����(otherscr)			src/linksamp/otherscr.od
--------------------------------------------------------------------------------
�ꥹ��6.1	��ñ�ʥ�󥫥�����ץȤ���(sample.lds)		src/linksamp/sample.lds
�ꥹ��6.2	̿��񤭴�������(overwrite.c)			src/linksamp/overwrite.c
�ꥹ��6.3	����ܥ�����Υ���ץ륹����ץ�(addr.lds)	src/linksamp/addr.lds
�ꥹ��6.4	����ܥ�����Υ���ץ�ץ����(addr.c)	src/linksamp/addr.c
��6.6		addr �β��Ϸ��(ȴ��)				src/linksamp/addr.od
��6.7		addr �μ¹Է��					src/linksamp/addr.out
�ꥹ��6.5	����ܥ���ͤΥ���ץ륹����ץ�(conflict.lds)	src/linksamp/conflict.lds
�ꥹ��6.6	����ܥ���ͤΥ���ץ�ץ����(conflict.c)	src/linksamp/conflict.c
��6.10		conflict �β��Ϸ��(ȴ��)			src/linksamp/conflict.od
��6.11		conflict �μ¹Է��				src/linksamp/conflict.out
�ꥹ��6.7	�����ǽ�ʽ���ͤ�����ΰ�			---
�ꥹ��6.8	����Բ�ǽ�ʽ���ͤ�����ΰ�			---
�ꥹ��6.9	�ѿ������Υ���ץ륹����ץ�(valiable.lds)	src/linksamp/valiable.lds
�ꥹ��6.10	�ѿ������Υ���ץ�ץ����(valiable.c)	src/linksamp/valiable.c
�ꥹ��6.11	FILL()��������ˡ				---
�ꥹ��6.12	FILLEXP��������ˡ				---
��6.13		valiable �β��Ϸ��(ȴ��)			src/linksamp/valiable.od
��6.14		valiable �μ¹Է��				src/linksamp/valiable.out
�ꥹ��6.13	���������κ�����				---
�ꥹ��6.14	���������ε���				---
�ꥹ��6.15	LMA����Υ���ץ륹����ץ�(lma.lds)		src/linksamp/lma.lds
��6.16		lma �β��Ϸ��(ȴ��)				src/linksamp/lma.od
��6.17		nm lma �η��					src/linksamp/lma.nm
--------------------------------------------------------------------------------
�ꥹ��7.1	��󥯤ν��֤Υ���ץ�ץ����(ordermain.c, ...)
								src/order/ordermain.c
								src/order/order1.c
								src/order/order2.c
�ꥹ��7.2	��ʣ����ܥ�Υ���ץ�ץ����(dupmain.c, ...)
								src/duplicate/dupmain.c
								src/duplicate/duptest1.c
								src/duplicate/duptest2.c
								src/duplicate/dup1.c
								src/duplicate/dup2.c
�ꥹ��7.3	�Х��ʥ�ǡ����ξƤ�����(binary.c)		src/binary/binary.c
��7.21		nm binary �η��				src/binary/binary.nm
��7.22		objdump -h binary �η��			src/binary/binary.od
�ꥹ��7.4	.incbin ������(incbin.s)			src/binary/incbin.s
�ꥹ��7.5	usr/initramfs_data.S ��Υ�����		---
�ꥹ��7.6	��󥫥�����ץ�(bindata.scr)			src/binary/bindata.scr
--------------------------------------------------------------------------------
�ꥹ��8.1	ELF�����Υ�����ʬ(imgact_elf.c)		---
��8.1		man execl ���ȴ��				---
��8.2		readelf -S /bin/ls �η��			src/loader/ls.shdr
��8.3		readelf -S /usr/bin/gcc �η��			src/loader/gcc.shdr
�ꥹ��8.2	��󥫥�����ץȤν���				src/loader/ldscript.diff
��8.4		readelf -l /bin/ls �η��			src/loader/ls.phdr
�ꥹ��8.3	�ե饰�ѹ��ѤΥץ����(chflg.c)		src/loader/chflg.c
�ꥹ��8.4	_start()����Ƭ��ʬ(crt1.c)			---
�ꥹ��8.5	(stack_sample.c)				src/stack/stack_sample.c
�ꥹ��8.6	(stack_sample.s)				src/stack/stack_sample.s
�ꥹ��8.7	�ʰץ���(loader.c)				src/loader/loader.c
�ꥹ��8.8	�����оݤΥ���ץ�ץ����(sample.c)	src/loader/sample.c
��8.7		�ʰץ����μ¹Է��				src/loader/loader.out
--------------------------------------------------------------------------------
�ꥹ��9.1	��������׺����ѥץ����(down.c)		src/core/down.c
��9.3		�¹Է����Υ����������			src/core/down.readelf
��9.4		��������פβ���				src/core/core.readelf
�ꥹ��9.2	elf_puthdr()					---
�ꥹ��9.3	elf_putnote()					---
�ꥹ��9.4	Elf_Note �����(elf_common.h)			---
�ꥹ��9.5	prstatus_t �����(procfs.h)			---
�ꥹ��9.6	struct reg �����(reg.h)			---
�ꥹ��9.7	struct fpreg �����(reg.h)			---
�ꥹ��9.8	prpsinfo_t �����(procfs.h)			---
��9.5		��������פβ���				src/core/nm.out
��9.6		�ѿ� count �ն�Υ����				---
�ꥹ��9.9	�¹ԺƳ��ѤΥץ����(continue.c)		src/continue/continue.c
�ꥹ��9.10	�¹ԺƳ��μ¸��ѥ���ץ�ץ����(calc.c)	src/continue/calc.c
��9.7		calc.c �μ¹Է��				src/continue/calc.comp
								src/continue/calc.out
��9.10		�¹ԤκƳ�					src/continue/continue.out
�ꥹ��9.A	_setjmp()/_longjmp() ��������(setjmp.c)		src/setjmp/setjmp.c
��9.A		setjmp.c �μ¹Է��				src/setjmp/setjmp.out
�ꥹ��9.B	_setjmp()/_longjmp() �Υ�����(_setjmp.S)	src/setjmp/_setjmp.S
�ꥹ��9.C	_setjmp() �ƤӽФ���˥����å����˲��������(setjmp2.c)
								src/setjmp/setjmp2.c
��9.B		setjmp2.c �μ¹Է��				src/setjmp/setjmp2.out
--------------------------------------------------------------------------------
�ꥹ��10.1	�ե�����֥��ѤΥ���ץ�ץ����(rasm.c)	src/rasm/rasm.c
�ꥹ��10.2	�ե�����֥��ѤΥ���ץ�ץ����(rasm2.c)	src/rasm/rasm2.c
�ꥹ��10.3	rasm.o �εե�����֥���			src/rasm/rasm.o.ra
�ꥹ��10.4	rasm �εե�����֥���				src/rasm/rasm.ra
�ꥹ��10.5	rasm.o �Υ�������󡤺����֥ơ��֥롤����ܥ�ơ��֥�
								src/rasm/rasm.o.re
�ꥹ��10.6	rasm2.o �Υ���ܥ�ơ��֥�			src/rasm/rasm2.o.re
�ꥹ��10.7	rasm �Υ���ܥ�ơ��֥�				src/rasm/rasm.re
�ꥹ��10.8	i386��¸�����(/usr/include/machine/elf.h)	---
�ꥹ��10.9	weak ����ܥ���������(weak.c)			src/weak/weak.c
�ꥹ��10.10	�����Х륷��ܥ���������(global.c)		src/weak/global.c
�ꥹ��10.11	weak ����ܥ�����Ѥ���(main.c)			src/weak/main.c
�ꥹ��10.12	global.o ���󥯤������μ¹Է��		src/weak/global.exec
�ꥹ��10.13	global.o ���󥯤��ʤ��ä����μ¹Է��	src/weak/noglobal.exec
�ꥹ��10.14	�¹Է��� global �Υ���ܥ�ơ��֥�(ȴ��)	src/weak/global.nm
�ꥹ��10.15	�¹Է��� noglobal �Υ���ܥ�ơ��֥�(ȴ��)	src/weak/noglobal.nm
�ꥹ��10.16	�饤�֥�ꥢ�������֤����Ѥ������μ¹Է��	src/weak/global_a.exec
�ꥹ��10.17	man syscall					---
�ꥹ��10.18	__syscall() �θƤӽФ�				---
�ꥹ��10.19	syscall()�����(ȴ��)				---
�ꥹ��10.20	�����ƥॳ�����ѥ饤�֥��(syscall.s)		src/linker/syscall.s
�ꥹ��10.21	ʸ����ɽ���ѥ饤�֥��(service.c)		src/linker/service.c
�ꥹ��10.22	�������ȥ��å�(crt.c)				src/linker/crt.c
�ꥹ��10.23	����ץ�ץ����(main.c)			src/linker/main.c
�ꥹ��10.24	����ץ�ץ����(sample.c)			src/linker/sample.c
�ꥹ��10.25	����ץ�ץ����(sample2.c)			src/linker/sample2.c
�ꥹ��10.26	����ץ�ץ����μ¹Է��			src/linker/sample.exec
�ꥹ��10.27	����ܥ����ѥ饤�֥��(linklib.h)		src/linker/linklib.h
�ꥹ��10.28	����ܥ����ѥ饤�֥��(linklib.c)		src/linker/linklib.c
�ꥹ��10.29	�����ʥߥå����(dynlink.c)			src/linker/dynlink.c
�ꥹ��10.30	�����ʥߥå���󥫤μ¹Է��			src/linker/dynlink.exec
�ꥹ��10.31	�¹Է����ѤΥ��(linker.c)			src/linker/linker.c
�ꥹ��10.32	�¹Է����ѥ�󥫤μ¹Է��			src/linker/linker.exec
�ꥹ��10.33	��󥫤Ǻ��������¹Է����μ¹Է��		src/linker/sample2.exec
�ꥹ��10.34	PowerPC�ѤΥ���ܥ���				---
--------------------------------------------------------------------------------
�ꥹ��11.1	�饤�֥��Υ���ץ�ץ����(sample.c)	src/shared/sample.c
�ꥹ��11.2	�饤�֥�����ѤΥ���ץ�ץ����(main.c)	src/shared/main.c
��11.7		sample_shared �μ¹Է��			src/shared/sample_shared.exec
��11.11		sample_static �μ¹Է��			src/shared/sample_static.exec
��11.13		readelf -a sample_pic.o �ν��Ϸ��		src/shared/sample_pic.o.re
�ꥹ��11.3	i386�κ����ּ���(/usr/include/machine/elf.h ���ȴ��)
								---
��11.14		objdump -d sample_pic.o �ν��Ϸ��		src/shared/sample_pic.o.ra
��11.15		readelf -a libsample.so.1 �ν��Ϸ��		src/shared/libsample.so.1.re
�ꥹ��11.4	Elf32_Dyn �����(elf32.h ���ȴ��)		---
�ꥹ��11.5	d_tag ��������(elf_common.h ���ȴ��)		---
��11.16		libsample.so.1 �� .got ���������Υ���׷��	src/shared/libsample.so.1.got
��11.17		objdump -d libsample.so.1 �ν��Ϸ��		src/shared/libsample.so.1.ra
��11.18		readelf -a sample_shared �ν��Ϸ��		src/shared/sample_shared.re
��11.19		objdump -d sample_shared �ν��Ϸ��		src/shared/sample_shared.ra
��11.20		sample_shared �� .got ���������Υ���׷��	src/shared/sample_shared.got
�ꥹ��11.6	.rtld_start �����(i386/rtld_start.S)		---
�ꥹ��11.7	_rtld()�����(rtld.c)				---
�ꥹ��11.8	init_rtld()�����(rtld.c)			---
�ꥹ��11.9	digest_phdr()�����(rtld.c)			---
�ꥹ��11.10	digest_dynamic()�����(rtld.c)			---
�ꥹ��11.11	relocate_objects()�����(rtld.c)		---
�ꥹ��11.12	init_pltgot()�����(i386/reloc.c)		---
�ꥹ��11.13	_rtld_bind()�����(rtld.c)			---
�ꥹ��11.14	dlopen()/dlsym()/dlclose()�λ�����(dlopen.c)	src/shared/dlopen.c
��11.21		dlopen.c �μ¹Է��				src/shared/dlopen.exec
�ꥹ��11.15	dlopen()�����(rtld.c)				---
--------------------------------------------------------------------------------

�ʾ�
